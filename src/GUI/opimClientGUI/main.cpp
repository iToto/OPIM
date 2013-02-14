#include <QApplication>
#include "opimClientGUI.h"

 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     opimClientGUI dialog;
     dialog.show();
     return app.exec();
 }
