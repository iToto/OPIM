#include "server.h"
#include <iostream>

using namespace std;

int main( void )
{
	opimServer* server = new opimServer();

	server->bringOnline();
	server->startServer();

	delete server;

	cout << "Server is offline.\n" << flush;

	return 0;
}
