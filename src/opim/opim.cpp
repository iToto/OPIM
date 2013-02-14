#include "opim.h"
#include <iostream>

opim::opim(){ }

int opim::receiveCmd( int client )
{
	unsigned char buf[1];
	int bytesRead;

	if ( ( bytesRead = recv( client, buf, 1, 0 ) ) == -1 )
		return discon; //client disconnection.

	return buf[0];
}

void opim::sendCmd( int client, int cmd )
{
	unsigned char buf[1];

	buf[0] = cmd;

	send( client, buf, 1, 0 );
}

string opim::receiveMessage( int client )
{
	char message[MAX_MESSAGE_BUFFER_SIZE];
	int bytesRead;
	string str = "";

	while ( true )
	{
		if ( ( bytesRead = recv( client, message, MAX_MESSAGE_BUFFER_SIZE, 0 ) ) == -1 )
			return "";

		message[bytesRead] = '\0';
		str += message;

		if ( bytesRead != MAX_MESSAGE_BUFFER_SIZE )
			break;
	}

	return str;
}

void opim::sendMessage( int destination, string message )
{
	char buf[MAX_MESSAGE_SIZE];

	strcpy( buf, message.c_str() );

	send( destination, buf, message.size(), 0 );
}

int opim::setupSocket( sockaddr_in &addr )
{
	int yes = 1;
	int sock;

	if ( ( sock = socket( PF_INET, SOCK_STREAM, 0 ) ) == -1 )
	{
		perror( "socket" );
		exit( 1 );
	}

	if ( setsockopt( sock, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof( int ) ) == -1 )
	{
		perror( "setsockopt" );
		exit( 1 );
	}

	addr.sin_family = AF_INET; //host byte order
	addr.sin_port = htons( PORT ); //short, network byte order
	addr.sin_addr.s_addr = INADDR_ANY; //automatically fill with my IP

	memset( &( addr.sin_zero ), '\0', 8 ); // zero the rest of the struct

	if ( bind( sock, (sockaddr*)&addr, sizeof( sockaddr ) ) == -1 )
	{
		perror( "bind" );
		exit( 1 );
	}

	if ( listen( sock, BACKLOG ) == -1 )
	{
		perror( "listen" );
		exit( 1 );
	}

	return sock;
}

int opim::connectTo( const char* host, sockaddr_in &theirAddr )
{
	hostent *he;
	int sock;

	if ( ( he = gethostbyname( host ) ) == NULL )
	{
		herror( "gethostbyname" );
		exit( 1 );
	}

	if ( ( sock = socket( PF_INET, SOCK_STREAM, 0 ) ) == -1 )
	{
		perror( "socket" );
		exit( 1 );
	}

	theirAddr.sin_family = AF_INET;     //host byte order
	theirAddr.sin_port   = htons( PORT ); //short, network byte order
	theirAddr.sin_addr   = *( (in_addr*)he->h_addr );

	memset( &( theirAddr.sin_zero ), '\0', 8 );  // zero the rest of the struct

	if ( connect( sock, (sockaddr*)&theirAddr, sizeof( sockaddr ) ) == -1 )
	{
		perror( "connect" );
		exit( 1 );
	}

	return sock;
}

int opim::listenFor( int sock, sockaddr_in &theirAddr )
{
	socklen_t sin_size = sizeof( struct sockaddr_in );

	return accept( sock, (sockaddr*)&theirAddr, &sin_size ); //-1 means connection error!
}
