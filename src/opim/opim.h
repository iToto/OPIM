#ifndef __OPIM_H__
#define __OPIM_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <cstdlib>
#include <ctime>

using namespace std;

const int PORT = 27419;
const int MAX_MESSAGE_SIZE = ( 1024 * 1024 ) + 1; //1 megabyte.
const int MAX_MESSAGE_BUFFER_SIZE = ( 1024 * 4 ) + 1; //4 kilobytes.
const int BACKLOG = 10;

class opim
{
	public:
		enum Cmds { discon = 0, disconFlood = 8, nak, ack, reg, login, startConvo, endConvo, say, fullList, addClient, removeClient, editClient };
		enum status { online = 1, offline = 2, away = 3, busy = 4 };
		opim( void );
		virtual int setupSocket( sockaddr_in& );
		virtual int receiveCmd( int );
		virtual void sendCmd( int, int );
		virtual string receiveMessage( int );
		virtual void sendMessage( int, string );
		virtual int listenFor( int, sockaddr_in& );
		virtual int connectTo( const char*, sockaddr_in& );
};

#endif
