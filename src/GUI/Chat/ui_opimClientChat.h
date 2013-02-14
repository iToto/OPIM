/********************************************************************************
** Form generated from reading ui file 'ui_opimClientChatyi7544.ui'
**
** Created: Mon Apr 13 17:18:59 2009
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_OPIMCLIENTCHATYI7544_H
#define UI_OPIMCLIENTCHATYI7544_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientChat
{
public:
    QTextEdit *txtMsg;
    QLineEdit *txtTypeMsg;
    QPushButton *btnSend;
    QPushButton *btnInit;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *txtIp;

    void setupUi(QDialog *Dialog)
    {
    if (Dialog->objectName().isEmpty())
        Dialog->setObjectName(QString::fromUtf8("Dialog"));
    Dialog->resize(603, 476);
    txtMsg = new QTextEdit(Dialog);
    txtMsg->setObjectName(QString::fromUtf8("txtMsg"));
    txtMsg->setGeometry(QRect(20, 20, 561, 311));
    txtMsg->setTextInteractionFlags(Qt::TextSelectableByKeyboard|Qt::TextSelectableByMouse);
    txtTypeMsg = new QLineEdit(Dialog);
    txtTypeMsg->setObjectName(QString::fromUtf8("txtTypeMsg"));
    txtTypeMsg->setGeometry(QRect(20, 360, 471, 28));
    btnSend = new QPushButton(Dialog);
    btnSend->setObjectName(QString::fromUtf8("btnSend"));
    btnSend->setGeometry(QRect(500, 360, 80, 28));
    btnInit = new QPushButton(Dialog);
    btnInit->setObjectName(QString::fromUtf8("btnInit"));
    btnInit->setGeometry(QRect(350, 410, 141, 51));
    widget = new QWidget(Dialog);
    widget->setObjectName(QString::fromUtf8("widget"));
    widget->setGeometry(QRect(150, 420, 132, 30));
    horizontalLayout = new QHBoxLayout(widget);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    horizontalLayout->setContentsMargins(0, 0, 0, 0);
    label = new QLabel(widget);
    label->setObjectName(QString::fromUtf8("label"));

    horizontalLayout->addWidget(label);

    txtIp = new QLineEdit(widget);
    txtIp->setObjectName(QString::fromUtf8("txtIp"));

    horizontalLayout->addWidget(txtIp);

    txtIp->raise();
    txtMsg->raise();
    txtTypeMsg->raise();
    btnSend->raise();
    btnInit->raise();
    txtIp->raise();
    label->raise();
    txtIp->raise();

    retranslateUi(Dialog);

    QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
    Dialog->setWindowTitle(QApplication::translate("Dialog", "Opim Chat", 0, QApplication::UnicodeUTF8));
    btnSend->setText(QApplication::translate("Dialog", "Send", 0, QApplication::UnicodeUTF8));
    btnInit->setText(QApplication::translate("Dialog", "Init Conersation", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("Dialog", "IP:", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Dialog);
    } // retranslateUi

};

namespace Ui {
    class ClientChat: public Ui_ClientChat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPIMCLIENTCHATYI7544_H

