/********************************************************************************
** Form generated from reading UI file 'tcpserver.ui'
**
** Created by: Qt User Interface Compiler version 5.13.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPSERVER_H
#define UI_TCPSERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TcpServer
{
public:
    QPushButton *serverCloseBtn;
    QLabel *serverStatusLabel;
    QPushButton *serverSendBtn;
    QPushButton *serverOpenBtn;
    QProgressBar *progressBar;

    void setupUi(QDialog *TcpServer)
    {
        if (TcpServer->objectName().isEmpty())
            TcpServer->setObjectName(QString::fromUtf8("TcpServer"));
        TcpServer->resize(350, 180);
        serverCloseBtn = new QPushButton(TcpServer);
        serverCloseBtn->setObjectName(QString::fromUtf8("serverCloseBtn"));
        serverCloseBtn->setGeometry(QRect(240, 140, 75, 23));
        serverStatusLabel = new QLabel(TcpServer);
        serverStatusLabel->setObjectName(QString::fromUtf8("serverStatusLabel"));
        serverStatusLabel->setGeometry(QRect(10, 10, 331, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        serverStatusLabel->setFont(font);
        serverStatusLabel->setAlignment(Qt::AlignCenter);
        serverSendBtn = new QPushButton(TcpServer);
        serverSendBtn->setObjectName(QString::fromUtf8("serverSendBtn"));
        serverSendBtn->setGeometry(QRect(140, 140, 75, 23));
        serverOpenBtn = new QPushButton(TcpServer);
        serverOpenBtn->setObjectName(QString::fromUtf8("serverOpenBtn"));
        serverOpenBtn->setGeometry(QRect(40, 140, 75, 23));
        progressBar = new QProgressBar(TcpServer);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(40, 90, 291, 23));
        progressBar->setValue(0);

        retranslateUi(TcpServer);

        QMetaObject::connectSlotsByName(TcpServer);
    } // setupUi

    void retranslateUi(QDialog *TcpServer)
    {
        TcpServer->setWindowTitle(QCoreApplication::translate("TcpServer", "\345\217\221\351\200\201\347\253\257", nullptr));
        serverCloseBtn->setText(QCoreApplication::translate("TcpServer", "\345\205\263\351\227\255", nullptr));
        serverStatusLabel->setText(QCoreApplication::translate("TcpServer", "\350\257\267\351\200\211\346\213\251\350\246\201\345\217\221\351\200\201\347\232\204\346\226\207\344\273\266\357\274\201", nullptr));
        serverSendBtn->setText(QCoreApplication::translate("TcpServer", "\345\217\221\351\200\201", nullptr));
        serverOpenBtn->setText(QCoreApplication::translate("TcpServer", "\346\211\223\345\274\200", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TcpServer: public Ui_TcpServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPSERVER_H
