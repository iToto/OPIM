#include <QApplication>
#include "opimUserList.h"

 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     opimUserList dialog;
     dialog.show();
     return app.exec();
 }
