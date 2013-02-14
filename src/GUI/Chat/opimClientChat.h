#ifndef OPIMCLIENTGUI_H
#define OPIMCLIENTGUI_H

#include <string>
#include "ui_opimClientChat.h"
#include "../../opim/opim.h"
#include "../../delegateThread/delegateThread.h"
#include <QListWidgetItem>

struct clientNfo
{
 int id;
 string name;
 int status;
};

class opimClientChat : public QDialog, private Ui::ClientChat, public opim
{
	Q_OBJECT

	public:
		opimClientChat(int,int,QWidget *parent = 0);
		
	public slots:
		void getMsg();

	private slots:
		void sendMsg(QString&);
		void appendMsg(QString&, bool);
		//void receiveMsg(Qstring&);
		void* conversation ( void* );
	private:
		//clientNfo _otherClient;
		int _sSock;
		int _rSock;
		delegateThread* _dt;
		sockaddr_in _myAddr;
		QString user;
		QString password;
		QTextTableFormat tableFormat;
		QDialog *aWindow;
};

class clientItem: public QListWidgetItem
{
	public:
	clientItem( int id, string name ) : QListWidgetItem( name.c_str() )
	{
		_client.id = id;
		_client.name = name;
	}
	clientNfo client(){ return _client; }
	private:		clientNfo _client;
};

#endif
