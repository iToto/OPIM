#include <QtGui>
#include "opimClientGUI.h"
#include <iostream>
#include <sstream>

using namespace std;

/*Constructor*/
opimClientGUI::opimClientGUI(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);

	connect(btnRegister,SIGNAL(clicked()),this, SLOT(sendRegister()));
	connect(btnLogin,SIGNAL(clicked()),this, SLOT(getLogin()));
}

void opimClientGUI::sendRegister()
{
	string u = txtUserName->text().toStdString();
	string p = txtPassword->text().toStdString();
	string ip = txtIp->text().toStdString();

	/*Empty Feild*/	
	if (u == "" || p == "" || ip == "")
	{
		QMessageBox::critical( this, "OpimClient", "Please enter a username, password and server IP." );
	}
	/*Send login info to Server!*/
	else
	{
		sockaddr_in theirAddr;
		int sSock = connectTo(ip.c_str(),theirAddr);
		int cmd;
		string message;
		
		sendCmd(sSock,reg);
		
		cmd = receiveCmd(sSock);
		
		if(cmd == ack)
		{
			stringstream ss;
			
			ss << "<register><username>" << u << "</username><password>" << p << "</password></register>";
			
			sendMessage(sSock,ss.str());
			
			cmd = receiveCmd( sSock );
			
			if(cmd == ack)
			{
				QMessageBox::information( this, "OpimClient", "Registration successfully!" );
			}
			else
			{
				message = receiveMessage( sSock );
				QMessageBox::critical( this, "OpimClient", message.c_str() );
				cout << message << endl << flush;
			}		
		}
		else
		{
			cout << "Bad startup command" << endl << flush;
		}
	}	
}

void opimClientGUI::getLogin()
{
	QString username = txtUserName->text();
	QString password = txtPassword->text();
	QString Ip       = txtIp->text();
	string un = username.toStdString();
	string pw = password.toStdString();
	string ip = Ip.toStdString();

	/*Empty Feild*/	
	if (username.isEmpty() || password.isEmpty())
	{
				
	}
	/*Send Registration info to server*/
	else
	{
		//cout << "UserName: " << un << " "<< "Password: " << pw << endl;
		sendLogin(un, pw, ip);
	}
}

/*Send login info to Server*/
void opimClientGUI::sendLogin(string &username, string &password, string &ip)
{
	cout << "UserName: " << username << " "<< "Password: " << password << endl;
	sockaddr_in theirAddr;
	int sSock = connectTo(ip.c_str(),theirAddr);
	sendCmd(sSock,login);
	int cmd = receiveCmd(sSock);
	if(cmd == ack)
	{
		stringstream ss;
		ss << "<login><username>" << username << "</username><password>" << password << "</password></login>";
		sendMessage(sSock,ss.str());
		cmd = receiveCmd( sSock );
		if(cmd == ack)
		{
			//int rSock = connectTo (ip.c_str(),theirAddr);
			cout << "Making UserList Window" << endl << flush;
			chatWindow = new opimUserList(ip,sSock,username,this);
			chatWindow->show();
			chatWindow->activateWindow();
			this->hide();
		}
		else
		{
			cout << "Incorrect Login Info" << endl << flush;
		}		
	}
	else
	{
		cout << "LOGIN ERROR" << endl << flush;
	}
}
