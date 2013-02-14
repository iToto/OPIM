#include "server.h"
#include <iostream>

Client::Client( Database* db, int socket, sockaddr_in addr ) : _db( db ), _socket( socket ), _myAddr( addr ), _sendSock( 0 ), _loggedIn( false )
{ }

Client::~Client()
{
	close( _socket );

	if ( _sendSock != 0 )
		close( _sendSock );

	if ( _loggedIn )
	{
		Query q( *_db );

		q.execute( makeSql( "delete from connected_users where user_id = ?", longToString( _id ).c_str() ) );
	}
}

void Client::sendListUpdate( int cmd, Client* otherClient )
{
	sendCmd( _sendSock, cmd );

	int res = receiveCmd( _sendSock );

	if ( res == ack )
	{
		stringstream ss;

		ss << "<user><id>" << otherClient->id() << "</id><name>" << otherClient->name() << "</name></user>";

		sendMessage( _sendSock, ss.str() );
	}
}

bool Client::registerMe()
{
	sendCmd( _socket, ack );

	string xml = receiveMessage( _socket );
	xmlDocPtr x = xmlReadMemory( xml.c_str(), xml.length(), "register", NULL, 0 );;
	xmlNode* root = xmlDocGetRootElement(x);
	const char* username = (const char*)root->children->children->content;
	const char* password = (const char*)root->children->next->children->content;
	string sql = "select 1 from users where username = ?";
	query q( *_db );

	cout << "Client " << ip() << " wants to register as " << username << " with password " << password << ".\n" << flush;

	q.get_result( makeSql( sql, username, password ) );

	long userExists = q.num_rows();

	q.free_result();

	if ( userExists )
	{
		cout << "Username " << username << " is already taken.\n" << flush;

		sendCmd( _socket, nak );
		sendMessage( _socket, "Username is already taken. Please choose another." );

		return false;
	}
	else
	{
		sql = "insert into users (username,password,time_added) values (?,?,date('now'))";

		q.execute( makeSql( sql, username, password ) );

		sendCmd( _socket, ack );

		cout << "Username " << username << " free! Registration successful!\n" << flush;

		return true;
	}

	xmlFreeDoc(x);       // free document
	xmlCleanupParser();    // Free globals

	return 0;
}

bool Client::login()
{
	sendCmd( _socket, ack ); //tell client it's ok to login.

	string xml = receiveMessage( _socket ); //getting the login information from the client.
	xmlDocPtr x = xmlReadMemory( xml.c_str(), xml.length(), "login", NULL, 0 );
	xmlNode* root = xmlDocGetRootElement(x);
	const char* username = (const char*)root->children->children->content;
	const char* password = (const char*)root->children->next->children->content;
	string sql = "select id,username from users where username = ? and password = ?";
	query q( *_db );

	q.get_result( makeSql( sql, username, password ) );

	cout << "Client " << ip() << " wants to login as " << username << " with password " << password << endl << flush;

	if ( q.num_rows() ) //user exist in database?
	{
		q.fetch_row();

		_id = q.getval();
		_name = q.getstr();
		sql = "select 1 from connected_users where user_id = ?";

		q.free_result();
		q.get_result( makeSql( sql, longToString( _id ).c_str() ) );

		if ( q.num_rows() == 0 ) //user not already connected?
		{
			sql = "insert into connected_users (user_id,login_time,status_id) values (?,date('now'),1)";
			_loggedIn = true;

			cout << "Client " << ip() << " successfully logs in as " << username << "!\n" << flush;

			q.free_result();
			q.execute( makeSql( sql, longToString( _id ).c_str() ) );
			sendCmd( _socket, ack );

			sockaddr_in theirAddr;
			cout << "Wating for send socket...\n" << flush;

			return true;
		}
		else
		{
			stringstream mes;

			mes << "You are already logged in as " << username << " with ip " << ip() << ".";
			cout << "Client " << _name << " is already logged int with ip " << ip() << endl << flush;

			q.free_result();
			sendCmd( _socket, nak );
			sendMessage( _socket, mes.str() );
		}
	}
	else
	{
		q.free_result();
		sendCmd( _socket, nak );
		sendMessage( _socket, "Login information incorrect. Please try again." );

		cout << "Bad login from " << ip() << " as " << username << " with password " << password << endl << flush;
	}

	xmlFreeDoc(x);       // free document
	xmlCleanupParser();    // Free globals

	return false;
}

string Client::xml()
{
	stringstream ss;

	ss << "<user><id>" << _id << "</id><name>" << _name << "</name><ip>" << ip() << "</ip></user>";

	return ss.str();
}

void Client::setSendSocket( int sock ){ _sendSock = sock; }

string Client::name(){ return _name; }

int Client::id(){ return _id; }

const char* Client::ip(){ return inet_ntoa( _myAddr.sin_addr ); }

bool Client::loggedIn(){ return _loggedIn; }

int Client::status(){ return _status; }

int Client::socket(){ return _socket; }

int Client::sendSock(){ return _sendSock; }

void Client::changeStatus( int newStatus ){	_status = newStatus; }
