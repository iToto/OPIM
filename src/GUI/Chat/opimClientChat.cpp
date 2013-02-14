#include <QtGui>
#include "opimClientChat.h"
#include <iostream>

using namespace std;

/*Constructor*/
opimClientChat::opimClientChat(int rSock,int sSock,QWidget *parent)
	: QDialog()
{
	setupUi(this);
	_rSock = rSock;
	_sSock = sSock;
	//_otherClient = client;
	txtTypeMsg->setFocusPolicy(Qt::StrongFocus);
     	txtMsg->setFocusPolicy(Qt::NoFocus);

	connect(btnSend,SIGNAL(clicked()),this, SLOT(getMsg()));

	_dt = new delegateThread(this);
	_dt->startThread( boost::bind( &opimClientChat::conversation, this, _1 ), (void*)0 );
}

void * opimClientChat::conversation( void* Arg)
{ 
	int cmd;
	QString msg;
	while ( true )
	{
		cmd = receiveCmd( _rSock );

		if (cmd == say)
		{
			sendCmd(_rSock, ack);
			msg = receiveMessage(_rSock).c_str();
			cout << "They Say: " << msg.toStdString() << endl << flush;
			appendMsg(msg,false);
		}
		else if ( cmd == discon )
		{
			cout << "They disconnect.\n" << flush;

			::close( _rSock );

			break;
		}
		else
		{
			sendCmd( _rSock, nak );

			cout << "They send bad command.\n" << flush;
		}
	}	
}
/*
void* opimClientChat::startListening( void* Arg)
{
	int cmd;
	
	while ( true )
	{
		cmd = receiveCmd ( _rSock );

		if( cmd == startConvo)
		{
			_dt->startThread( boost::bind( &opimClientChat::conversation, this, _1 ), (void*)0 );
		}
	}
	
}

void opimClientChat::initConvo()
{
	_starter = true;
	sockaddr_in theirAddr;
	string ip = txtIp->text().toStdString();
	cout << "Connecting To: " << ip << endl << flush;
	_sSock = connectTo(ip.c_str(),theirAddr);
}
*/
/*Get login info from user*/
void opimClientChat::getMsg()
{
	QString msg = txtTypeMsg->text();
	string msgString = msg.toStdString();
	txtTypeMsg->clear();

	/*Empty Feild*/	
	if (msg.isEmpty())
	{
		return;			
	}
	/*Send message to other client*/
	else
	{
		sendMsg(msg);
	}	
}

/*Send message to other client*/
void opimClientChat::sendMsg(QString &msg)
{
	string msgString = msg.toStdString();
	cout << "Message: " << msgString << endl;
	sendCmd(_sSock,say);
	int cmd = receiveCmd(_sSock);		
	if (cmd == ack)
	{
		sendMessage(_sSock,msgString);
		appendMsg(msg,true);
	}
	else if (cmd == nak)
	{
		cout << "Server cannot Process Request, try again" << endl << flush;
	}	
}
void opimClientChat::appendMsg(QString &msg,bool fromMe)
{
	if (msg=="")
         return;	
	QString table;
     	QTextCursor cursor(txtMsg->textCursor());
     	cursor.movePosition(QTextCursor::End);
	if (fromMe)
		table = "I said: " + msg + "\n";
	else
		table = "They said: " + msg + "\n";
	cursor.insertText(table);	
	QScrollBar *bar = txtMsg->verticalScrollBar();
	bar->setValue(bar->maximum());
}
