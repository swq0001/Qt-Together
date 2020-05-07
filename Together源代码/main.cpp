#include"logindlg.h"
#include"signupdialog.h"
#include"personalinfodialog.h"
#include"commonhelper.h"
#include"controls.h"
#include<customwidget.h>
#include <QApplication>
#include<chatroom.h>
#include<tcpclient.h>
#include<tcpserver.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CommonHelper::setStyle("://QSS/white.qss");
    LogInDlg w;
    w.show();
    return a.exec();
}



