#include <QtGui>
#include "opimUserList.h"
#include <iostream>
#include <sstream>
#include <libxml/parser.h>
#include <libxml/tree.h>

using namespace std;
pthread_mutex_t _listMutex = PTHREAD_MUTEX_INITIALIZER; 

/*Constructor*/
opimUserList::opimUserList(string ip, int sSock, string name, QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
	_dt = new delegateThread(this);
	_ip = ip;
	_sSock = sSock;
	_socket = setupSocket(_myAddr);	
	lblName->setText(QApplication::translate("Dialog", name.c_str(), 0, QApplication::UnicodeUTF8));
	connect(btnConnect,SIGNAL(clicked()),this, SLOT(startConversation()));
	connect(this,SIGNAL(dummy(int,int)),this,SLOT(makeNewWindow(int,int)));

	_dt->startThread( boost::bind( &opimUserList::startListening, this, _1 ), (void*)0 );
}

void* opimUserList::startListening( void* Arg)
{
	int cmd;
	sockaddr_in theirAddr;
	_rSock = connectTo (_ip.c_str(),theirAddr);
	string xml = receiveMessage( _rSock );
	cout << xml << endl << flush;

	xmlDocPtr x = xmlReadMemory( xml.c_str(), xml.length(), "users", NULL, 0);
	xmlNode* root = xmlDocGetRootElement(x);

	for ( xmlNode* curNode = root->children ; curNode ; curNode = curNode->next )
	{
		listUsers->addItem(
		(QListWidgetItem*)(new clientItem( atoi( (const char*)curNode->children->children->content ), (char*)curNode->children->next->children->content ) )
		);
	}
	
	xmlFreeDoc(x);       // free document
	xmlCleanupParser();    // Free globals
	
	while ( true )
	{
		cmd = receiveCmd ( _rSock );

		if( cmd == startConvo )
		{
			//string xml = receiveMessage( _rSock );
			int rSock = listenFor( _socket, theirAddr );
			int sSock = listenFor( _socket, theirAddr );
        		cout << "Got convo from other client: " << rSock << " " << sSock << endl << flush;
			dummy(rSock,sSock);
		}
		else if( cmd == addClient)
		{
			sendCmd( _rSock,ack );
			
			string xml = receiveMessage( _rSock );
			
			cout << xml << endl << flush;
			
			x = xmlReadMemory( xml.c_str(), xml.length(), "user", NULL, 0);
			root = xmlDocGetRootElement(x);
			
			cout << "Adding to list: " << (const char*)root->children->children->content << ", " << (const char*)root->children->next->children->content << endl << flush;
			
			listUsers->addItem(
				(QListWidgetItem*)(new clientItem( atoi( (const char*)root->children->children->content ), (const char*)root->children->next->children->content ) )
			);

			xmlFreeDoc(x);       // free document
			xmlCleanupParser();    // Free globals
		}
		else if( cmd == removeClient)
		{
			sendCmd( _rSock,ack );
			
			string xml = receiveMessage( _rSock );
			
			cout << xml << endl << flush;
			
			x = xmlReadMemory( xml.c_str(), xml.length(), "user", NULL, 0);
			root = xmlDocGetRootElement(x);
			
			cout << "Removing from list: " << (const char*)root->children->children->content << ", " << (const char*)root->children->next->children->content << endl << flush;
			
			QList<QListWidgetItem*> list = listUsers->findItems( (const char*)root->children->next->children->content, Qt::MatchExactly );
			
			if ( list.size() )
			{
				delete list[0];
			}

        	        xmlFreeDoc(x);       // free document
	                xmlCleanupParser();    // Free global
		}
		
//		xmlFreeDoc(x);       // free document
//		xmlCleanupParser();    // Free globals
	}
	
}

void opimUserList::startConversation()
{
	cout << "Wanting conversation\n" << flush;
	
	sockaddr_in theirAddr;
	sendCmd(_sSock,startConvo);
	cout << "Sent\n" << flush;
	int cmd = receiveCmd(_sSock);
	cout << "Received " << cmd << endl << flush;
	if(cmd == ack)
	{
		cout << "Convo Can be Started" << endl << flush;
		clientItem *item = (clientItem*)listUsers->currentItem();
		sendMessage(_sSock,longToString(item->client().id));
		
		cmd = receiveCmd(_sSock);
		if(cmd == ack)
		{
			cout << "Starting New Convo" << endl << flush;
			string ip = receiveMessage(_sSock);
			//parse xml.
			cout << "Other client's IP: " << ip << endl << flush;
			int sSock = connectTo(ip.c_str(),theirAddr);
			int rSock = connectTo(ip.c_str(),theirAddr);
			cout << "Creating Chat Window" << endl << flush;
			opimClientChat* chatWindow= new opimClientChat(rSock,sSock,this);
			chatWindow->show();
			chatWindow->activateWindow();
		}
	}	
}

void opimUserList::makeNewWindow(int rSock,int sSock)
{
	cout << "Heres the report: " << rSock << sSock << endl << flush;
	opimClientChat* chatWindow= new opimClientChat(rSock,sSock,this);
	chatWindow->show();
	chatWindow->activateWindow();
}

string opimUserList::longToString( const long& number )
{
	stringstream ss;

	ss << number;

	return ss.str();
}





