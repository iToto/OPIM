#ifndef OPIMCLIENTGUI_H
#define OPIMCLIENTGUI_H

#include <string>
#include "../../opim/opim.h"
#include "ui_opimClientGUI.h"
#include "../UserList/opimUserList.h"

using namespace std;

class opimClientGUI : public QDialog, private Ui::Login, public opim
{
	Q_OBJECT

	public:
		opimClientGUI(QWidget *parent = 0);
		
	public slots:
		void getLogin();
		void sendRegister();

	private slots:
		void sendLogin(string&, string&, string&);

	private:
		QString user;
		QString password;
		opimUserList* chatWindow;
};

#endif
