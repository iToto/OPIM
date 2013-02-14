/********************************************************************************
** Form generated from reading ui file 'ui_userListzF7544.ui'
**
** Created: Mon Apr 20 19:35:19 2009
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_USERLISTZF7544_H
#define UI_USERLISTZF7544_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_UserList
{
public:
    QListWidget *listUsers;
    QLabel *lblName;
    QPushButton *btnConnect;

    void setupUi(QDialog *Dialog)
    {
    if (Dialog->objectName().isEmpty())
        Dialog->setObjectName(QString::fromUtf8("Dialog"));
    Dialog->resize(321, 556);
    listUsers = new QListWidget(Dialog);
    listUsers->setObjectName(QString::fromUtf8("listUsers"));
    listUsers->setGeometry(QRect(10, 70, 301, 431));
    lblName = new QLabel(Dialog);
    lblName->setObjectName(QString::fromUtf8("lblName"));
    lblName->setGeometry(QRect(20, 20, 101, 31));
    btnConnect = new QPushButton(Dialog);
    btnConnect->setObjectName(QString::fromUtf8("btnConnect"));
    btnConnect->setGeometry(QRect(110, 510, 101, 31));

    retranslateUi(Dialog);

    QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
    Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
    lblName->setText(QApplication::translate("Dialog", "USER NAME", 0, QApplication::UnicodeUTF8));
    btnConnect->setText(QApplication::translate("Dialog", "Start Conversation", 0, QApplication::UnicodeUTF8));
    Q_UNUSED(Dialog);
    } // retranslateUi

};

namespace Ui {
    class UserList: public Ui_UserList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERLISTZF7544_H

