#include "server.h"
#include <iostream>

pthread_mutex_t _clientsMutex = PTHREAD_MUTEX_INITIALIZER; //sorry need to do it this way :P
pthread_mutex_t _convosMutex = PTHREAD_MUTEX_INITIALIZER; //sorry need to do it this way :P

opimServer::opimServer( void ) : _online( false )
{
	_db = new Database( _dbMutex, "opim.db", &_dbLog );
	_dt = new delegateThread( this );

	setupDB();
}

opimServer::~opimServer( void )
{
	delete _dt;
	delete _db;

	for ( clientIt it = 0 ; it != _clients.size() ; ++it )
		delete _clients[it];
}

void opimServer::setupDB()
{
	query q( *_db );
	stringstream sql;

	//creating users table.
	sql << "create table if not exists users (";
	sql << "  id integer primary key autoincrement not null,";
	sql << "  username text,";
	sql << "  password text,";
	sql << "  time_added date)";
	q.execute( sql.str() );
	sql.str("");

	//creating user status table
	q.execute( "drop table if exists user_status" );
	q.execute( "create table user_status (id integer primary key not null, name text)" );
	q.execute( "insert into user_status (id,name) values (1,'online')" );
	q.execute( "insert into user_status (id,name) values (2,'offline')" );
	q.execute( "insert into user_status (id,name) values (3,'away')" );
	q.execute( "insert into user_status (id,name) values (4,'busy')" );

	//creating connected users table.
	sql << "create table if not exists connected_users (";
	sql << "  user_id integer primary key not null,";
	sql << "  login_time date,";
	sql << "  status_id integer)";
	q.execute( sql.str() );
	q.execute( "delete from connected_users where 1" );
}

void* opimServer::acceptClients( void* ptr )
{
	Client* client;
	int sock;
	sockaddr_in theirAddr;
	int cmd;

	while ( true )
	{
		sock = listenFor( _socket, theirAddr );

		cout << "Got connection from " << inet_ntoa( theirAddr.sin_addr ) << " on socket " << sock << "!\n" << flush;

		if ( sock != -1 )
		{
			client = new Client( _db, sock, theirAddr );
			cmd = receiveCmd( client->socket() );

			switch ( cmd )
			{
				case login:

					if ( client->login() ) //login successful?
					{
						pthread_mutex_lock( &_clientsMutex ); //need to tell the other clients that someone has logged in.
						updateClientsLists( addClient, client );
						_clients.push_back( client );
						client->setSendSocket( listenFor( _socket, theirAddr ) );
						updateClientsLists( fullList, client );
						_dt->startThread( boost::bind( &opimServer::handleClient, this, _1 ), (void*)client );

						pthread_mutex_unlock( &_clientsMutex );

						cout << "Started listening to client " << client->ip() << "!" << endl << flush;
					}
					else
						delete client;

					break;

				case reg: client->registerMe();	break;
				default: cout << "Invaild startup command from " << client->ip() << ": " << cmd << endl << flush;
			}
		}
	}

	return 0;
}

void* opimServer::handleClient( void* arg )
{
	Client* client = (Client*)arg;
	int cmd;

	while ( true )
	{
		cmd = receiveCmd( client->socket() );

		if ( cmd == discon || cmd == disconFlood ) //client disconnected?
		{
			pthread_mutex_lock( &_clientsMutex );

			for ( clientIt it = 0 ; it != _clients.size() ; ++it ) //find the client in the clients list and remove them.
			{
				if ( _clients[it]->id() == client->id() )
				{
					_clients.erase( _clients.begin() + it );
					break;
				}
			}

			for ( convoIt it = 0 ; it != _convos.size() ; ++it ) //find and remove all conversations containing the disconnecting client.
			{
				if ( _convos[it]->inConvo( client ) )
				{
					_convos.erase( _convos.begin() + it );
					delete _convos[it];

					--it;
				}
			}

			updateClientsLists( removeClient, client );

			cout << client->name() << " disconnects\n" << flush;
			cout << _clients.size() << " client(s) now connected.\n" << flush;

			delete client;

			pthread_mutex_unlock( &_clientsMutex );

			break;
		}
		else if ( cmd == startConvo ) //client wants to start a conversation with another client?
		{
			sendCmd( client->socket(), ack );

			int clientId = atoi( receiveMessage( client->socket() ).c_str() );

			cout << client->name() << " wants to talk to client " << clientId << endl << flush;

			if ( clientId != client->id() ) //not starting a conversation with themselves?
			{
				Query q( *_db );

				q.get_result( makeSql( "select 1 from connected_users where user_id = ?", longToString( clientId ).c_str() ) );

				if ( q.num_rows() ) //other client online?
				{
					pthread_mutex_lock( &_clientsMutex );

					Client* otherClient = getClientById( clientId );

					if ( otherClient != 0 ) //client found in clients list?
					{
						if ( notInAConvo( client, otherClient ) )
						{
							convo* c = new convo();

							c->addClient( client );
							c->addClient( otherClient );
							_convos.push_back( c );
							sendCmd( otherClient->sendSock(), startConvo );
							sendCmd( client->socket(), ack );
							sendMessage( client->socket(), otherClient->ip() );

							cout << "Conversation started between " << client->name() << " and " << otherClient->name() << endl << flush;
						}
						else
						{
							sendCmd( client->socket(), nak );
							sendMessage( client->socket(), "Already in a conversation" );

							cout << client->name() << " already in conversation with " << otherClient->name() << endl << flush;
						}
					}
					else
					{
						sendCmd( client->socket(), nak );
						sendMessage( client->socket(), "Client is not online" );

						cout << "Other client is not online\n" << flush;
					}

					pthread_mutex_unlock( &_clientsMutex );
				}
				else
				{
					sendCmd( client->socket(), nak );
					sendMessage( client->socket(), "Client is not online" );

					cout << client->name() << " other client is not online\n" << flush;
				}

				q.free_result();
			}
			else
			{
				sendCmd( client->socket(), nak );
				sendMessage( client->socket(), "You cannot start a conversation with yourself" );

				cout << client->name() << " tries to start a conversation with themself\n" << flush;
			}
		}
		else
		{
			sendCmd( client->socket(), nak );
			sendMessage( client->socket(), "Command not recongnized" );

			cout << client->name() << " send unrecongnized command: " << cmd << endl << flush;
		}
	}

	return 0;
}

void opimServer::updateClientsLists( int cmd, Client* client )
{
	if ( cmd == fullList )
	{
		stringstream ss;

		ss << "<users>";

		for ( clientIt it = 0 ; it != _clients.size() ; ++it )
			ss << "<user><id>" << _clients[it]->id() << "</id><name>" << _clients[it]->name() << "</name></user>";

		ss << "</users>";

		sendMessage( client->sendSock(), ss.str() );
	}
	else
	{
		for ( clientIt it = 0 ; it != _clients.size() ; ++it )
			_clients[it]->sendListUpdate( cmd, client );
	}
}

void opimServer::bringOnline( void )
{
	_socket = setupSocket( _myAddr );
	_online = true;

	cout << "Server is online!\n" << flush;
}

void opimServer::startServer( void )
{
	if ( _online ) //server online?
	{
		//starting the server threads.
		cout << "Starting acceptClients thread...\n" << flush;
		pthread_t thAcceptClients = _dt->startThread( boost::bind( &opimServer::acceptClients, this, _1 ), (void*)0 );

		cout << "Server has started!\n" << flush;

		//waiting for all threads to die.
		pthread_join( thAcceptClients, NULL );
	}
	else
		cout << "Error: server has not been brought online." << flush;
}

void print( string message )
{
//	pthread_mutex_lock( &this->_ostreamMutex );
//
//	cout << message << flush;
//
//	pthread_mutex_unlock( &this->_ostreamMutex );
}

void* opimServer::serverCLI( void* ptr )
{
	while ( true )
	{

	}
}

bool opimServer::notInAConvo( Client* client1, Client* client2 )
{
	for ( convoIt it = 0 ; it != _convos.size() ; ++it )
	{
		if ( _convos[it]->inConvo( client1, client2 ) )
			return false;
	}

	return true;
}

Client* opimServer::getClientById( int id )
{
	for ( clientIt it = 0 ; it != _clients.size() ; ++it )
	{
		if ( _clients[it]->id() == id  )
			return _clients[it];
	}

	return 0;
}
