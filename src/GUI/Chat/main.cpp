#include <QApplication>

#include "opimClientChat.h"

 int main(int argc, char *argv[])
 {
     	QApplication app(argc, argv);
     	opimClientChat chatDialog;
     	chatDialog.show();
     	return app.exec();
 }
