#ifndef __OPIM_SERVER_H__
#define __OPIM_SERVER_H__

#include "../opim/opim.h"
#include "../delegateThread/delegateThread.h"
#include "../helpers/helpers.h"
#include <vector>
#include <sqlite3.h>
#include <libsqlitewrapped.h>
#include <sstream>
#include <libxml/parser.h>
#include <libxml/tree.h>

using namespace std;
using namespace helpers;

class Client;
class convo;

class opimServer: public opim
{
	public:
		opimServer( void );
		virtual ~opimServer( void );
		void bringOnline( void );
		void startServer( void );
		void* acceptClients( void* );
		void* handleClient( void* );
		void* serverCLI( void* );
		void updateClientsLists( int, Client* );
		void print();

	private:
		void setupDB();
		bool notInAConvo( Client*, Client* );
		Client* getClientById( int id );

		Database::Mutex _dbMutex;
		Database* _db;
		StderrLog _dbLog;
		vector<convo*> _convos;
		vector<Client*> _clients;
		int _socket;
		sockaddr_in _myAddr;
		bool _online;
		delegateThread* _dt;
};



class Client: public opim
{
	public:
		Client( Database*, int, sockaddr_in );
		virtual ~Client();
		bool registerMe();
		bool login();
		string name();
		int id();
		const char* ip();
		bool loggedIn();
		int status();
		int socket();
		void changeStatus( int );
		void sendListUpdate( int, Client* );
		void setSendSocket( int );
		int sendSock();
		string xml();

	private:
		sockaddr_in _myAddr;
		int _id;
		string _name;
		string _password;
		Database* _db;
		int _status;
		int _socket;
		int _sendSock;
		bool _loggedIn;
};



class convo
{
	public:
		convo(){ }
		bool inConvo( Client*, Client* );
		bool inConvo( Client* );
		void addClient( Client* );

	private:
		vector<Client*> _clients;
};

typedef Query query;
typedef vector<convo>::size_type convoIt;
typedef vector<Client*>::size_type clientIt;

#endif
