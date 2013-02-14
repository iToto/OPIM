#ifndef OPIMUSERLIST_H
#define OPIMUSERLIST_H

#include <string>
#include "../../opim/opim.h"
#include "ui_opimUserList.h"
#include "../Chat/opimClientChat.h"
#include "../../delegateThread/delegateThread.h"


using namespace std;

struct clientNfo;

class opimUserList : public QDialog, private Ui::UserList, public opim
{
	Q_OBJECT

	public:
		opimUserList(string,int,string,QWidget *parent = 0);
		
	public slots:
		void startConversation();
		void makeNewWindow(int,int);
	signals:
		void dummy(int,int);

	private slots:
		void* startListening( void* );
		

	private:
		string _ip;
		int _socket;
		int _sSock;
		int _rSock;
		delegateThread* _dt;
		sockaddr_in _myAddr;
		string longToString(const long&);
};

#endif
