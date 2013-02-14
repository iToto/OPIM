#include "server.h"

bool convo::inConvo( Client* client1, Client* client2 )
{
	bool found1 = false;

	for ( clientIt it = 0 ; it != _clients.size() ; ++it )
	{
		if ( _clients[it] == client1 || _clients[it] == client2 )
		{
			if ( found1 )
				return true;
			else
				found1 = true;
		}
	}

	return false;
}

bool convo::inConvo( Client* client )
{
	for ( clientIt it = 0 ; it != _clients.size() ; ++it )
	{
		if ( _clients[it] == client  )
			return true;
	}

	return false;
}
void convo::addClient( Client* client )
{
	_clients.push_back( client );
}
