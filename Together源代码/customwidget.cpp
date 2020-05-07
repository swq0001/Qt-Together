#include "customwidget.h"
#include<QBitmap>
#include<QPainter>
#include<QStyleOption>
#include<QTimer>
#include<QPushButton>
#include<QDebug>
#include<QAction>
#include<QMenu>
#include<QApplication>
#include<QCloseEvent>
#include<QPropertyAnimation>
#include<QParallelAnimationGroup>
#include<QGraphicsOpacityEffect>
void CustomWidget::paintEvent(QPaintEvent *event)
{
    angle+=3;
    if(angle==360)
        angle=0;
    QPainter painter(this);
    painter.translate(100,100);
    painter.rotate(angle);
    painter.setOpacity(0.4);
    painter.drawPixmap(-100,-90,pixmap);
    QPen pen(Qt::red,9);
    painter.setPen(pen);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setOpacity(0.7);
    painter.drawEllipse(QPoint(0,0),95,95);
    pen.setColor(Qt::lightGray);
    pen.setWidth(2);
    painter.setPen(pen);
    painter.drawEllipse(QPoint(0,0),90,90);
    painter.drawEllipse(QPoint(0,0),99,99);
}

void CustomWidget::mouseMoveEvent(QMouseEvent *event)
{
//    qDebug()<<event->x();

    if(event->buttons()&Qt::LeftButton)
    {
        move(event->globalPos()-currentPos);
    }
    if(!isPressed)
    {
        if(playBtn->underMouse()&&!isPlayingPlay)
        {
            playBtnOpacityAnimation->start();
            isPlayingPlay=true;
            isPlayingChat=isPlayingConfig=isPlayingExit=false;
            chatBtnOpacity->setOpacity(opacityStartVal);
            configBtnOpacity->setOpacity(opacityStartVal);
            exitBtnOpacity->setOpacity(opacityStartVal);
        }
        if(chatBtn->underMouse()&&!isPlayingChat)
        {
            chatBtnOpacityAnimation->start();
            isPlayingChat=true;
            isPlayingPlay=isPlayingConfig=isPlayingExit=false;
            playBtnOpacity->setOpacity(opacityStartVal);
            configBtnOpacity->setOpacity(opacityStartVal);
            exitBtnOpacity->setOpacity(opacityStartVal);
        }
        if(configBtn->underMouse()&&!isPlayingConfig)
        {
            configBtnOpacityAnimation->start();
            isPlayingConfig=true;
            isPlayingPlay=isPlayingChat=isPlayingExit=false;
            playBtnOpacity->setOpacity(opacityStartVal);
            chatBtnOpacity->setOpacity(opacityStartVal);
            exitBtnOpacity->setOpacity(opacityStartVal);
        }
        if(exitBtn->underMouse()&&!isPlayingExit)
        {
            exitBtnOpacityAnimation->start();
            isPlayingExit=true;
            isPlayingPlay=isPlayingChat=isPlayingConfig=false;
            playBtnOpacity->setOpacity(opacityStartVal);
            chatBtnOpacity->setOpacity(opacityStartVal);
            configBtnOpacity->setOpacity(opacityStartVal);
        }
    }
}

void CustomWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        currentPos=event->globalPos()-frameGeometry().topLeft();
        isPressed=true;
        event->accept();
    }
}

void CustomWidget::mouseReleaseEvent(QMouseEvent *event)
{
    isPressed=false;
}

void CustomWidget::closeEvent(QCloseEvent *event)
{
    trayIcon->showMessage(QStringLiteral("哈喽"),QStringLiteral("我现在隐藏到系统图标区域了！"),
                          QSystemTrayIcon::MessageIcon::Information,5000);
    hide();
    event->ignore();
}

CustomWidget::CustomWidget(QWidget *parent) : QMainWindow(parent)
{
    setWindowFlag(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setMouseTracking(true);//鼠标跟踪
    pixmap.load(":/image/images/T.png");
    resize(pixmap.size());
    timer=new QTimer(this);
    timer->start(25);
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    angle=0;
    initArgs();
    //初始化按钮
    initBtns();
    initTrayIconMenu();
    initTrayIcon();
}

void CustomWidget::initBtns()
{
    //设置按钮的图片和位置
    playIconPixmap.load(":/image/images/playIcon.png");
    int width=playIconPixmap.width();
    int height=playIconPixmap.height();
    playBtn=new QPushButton(this);
    playBtn->resize(playIconPixmap.size());
    playBtn->setMask(playIconPixmap.mask());
    playBtn->setStyleSheet("background-image: url(:/image/images/playIcon.png)");
    playBtn->move(width-10,height-5);

    chatIconPixmap.load(":/image/images/chatIcon.png");
    chatBtn=new QPushButton(this);
    chatBtn->resize(chatIconPixmap.size());
    chatBtn->setMask(chatIconPixmap.mask());
    chatBtn->setStyleSheet("background-image: url(:/image/images/chatIcon.png)");
    chatBtn->move(70+width,height-5);

    configIconPixmap.load(":/image/images/configIcon.png");
    configBtn=new QPushButton(this);
    configBtn->resize(configIconPixmap.size());
    configBtn->setMask(configIconPixmap.mask());
    configBtn->setStyleSheet("background-image: url(:/image/images/configIcon.png)");
    configBtn->move(width-10,75+height);

    exitIconPixmap.load(":/image/images/exitIcon.png");
    exitBtn=new QPushButton(this);
    exitBtn->resize(exitIconPixmap.size());
    exitBtn->setMask(exitIconPixmap.mask());
    exitBtn->setStyleSheet("background-image: url(:/image/images/exitIcon.png)");
    exitBtn->move(70+width,75+height);

    //设置按钮透明度
    playBtnOpacity=new QGraphicsOpacityEffect(this);
    playBtnOpacity->setOpacity(opacityStartVal);
    playBtn->setGraphicsEffect(playBtnOpacity);

    chatBtnOpacity=new QGraphicsOpacityEffect(this);
    chatBtnOpacity->setOpacity(opacityStartVal);
    chatBtn->setGraphicsEffect(chatBtnOpacity);

    configBtnOpacity=new QGraphicsOpacityEffect(this);
    configBtnOpacity->setOpacity(opacityStartVal);
    configBtn->setGraphicsEffect(configBtnOpacity);

    exitBtnOpacity=new QGraphicsOpacityEffect(this);
    exitBtnOpacity->setOpacity(opacityStartVal);
    exitBtn->setGraphicsEffect(exitBtnOpacity);

    //设置按钮透明度动画
    playBtnOpacityAnimation=new QPropertyAnimation(playBtnOpacity,"opacity");
    playBtnOpacityAnimation->setStartValue(opacityStartVal);
    playBtnOpacityAnimation->setEndValue(opacityEndVal);
    playBtnOpacityAnimation->setDuration(opacityAnimationDuration);

    chatBtnOpacityAnimation=new QPropertyAnimation(chatBtnOpacity,"opacity");
    chatBtnOpacityAnimation->setStartValue(opacityStartVal);
    chatBtnOpacityAnimation->setEndValue(opacityEndVal);
    chatBtnOpacityAnimation->setDuration(opacityAnimationDuration);

    configBtnOpacityAnimation=new QPropertyAnimation(configBtnOpacity,"opacity");
    configBtnOpacityAnimation->setStartValue(opacityStartVal);
    configBtnOpacityAnimation->setEndValue(opacityEndVal);
    configBtnOpacityAnimation->setDuration(opacityAnimationDuration);

    exitBtnOpacityAnimation=new QPropertyAnimation(exitBtnOpacity,"opacity");
    exitBtnOpacityAnimation->setStartValue(opacityStartVal);
    exitBtnOpacityAnimation->setEndValue(opacityEndVal);
    exitBtnOpacityAnimation->setDuration(opacityAnimationDuration);

    playBtn->setMouseTracking(true);
    chatBtn->setMouseTracking(true);
    configBtn->setMouseTracking(true);
    exitBtn->setMouseTracking(true);
    //关联按钮的信号与槽
    connect(playBtn,SIGNAL(clicked()),this,SLOT(playBtnClickedSlot()));
    connect(chatBtn,SIGNAL(clicked()),this,SLOT(chatBtnClickedSlot()));
    connect(configBtn,SIGNAL(clicked()),this,SLOT(configBtnClickedSlot()));
    connect(exitBtn,SIGNAL(clicked()),this,SLOT(exitBtnClickedSlot()));

}

void CustomWidget::initTrayIconMenu()
{
    quitAction=new QAction(QStringLiteral("退出"),this);
    connect(quitAction,&QAction::triggered,qApp,&QApplication::quit);

    trayIconMenu=new QMenu();
    trayIconMenu->addAction(quitAction);
}

void CustomWidget::initTrayIcon()
{
    trayIcon=new QSystemTrayIcon(this);
    trayIcon->setContextMenu(trayIconMenu);
    trayIcon->setIcon(QIcon(":/image/images/T.png"));
    trayIcon->show();

    connect(trayIcon,&QSystemTrayIcon::activated,this,&CustomWidget::trayIconActivatedSlot);
    qDebug()<<QSystemTrayIcon::isSystemTrayAvailable();
}

void CustomWidget::initArgs()
{
    opacityStartVal=0.5;
    opacityEndVal=1;
    opacityAnimationDuration=500;
    centerX=100;
    centerY=100;
    isPlayingPlay=isPlayingChat=isPlayingConfig=isPlayingExit=false;
}

void CustomWidget::playBtnClickedSlot()
{
    qDebug()<<"play!!!";
    videoPlayer=new VideoPlayer;
    videoPlayer->resize(800,600);
    videoPlayer->show();
}

void CustomWidget::chatBtnClickedSlot()
{
    qDebug()<<"chat!!!";
    chatRoom=new ChatRoom();
    chatRoom->show();
}

void CustomWidget::configBtnClickedSlot()
{
    qDebug()<<"config!!!";
    personalInfoDialog=new PersonalInfoDialog;
    personalInfoDialog->show();
}

void CustomWidget::exitBtnClickedSlot()
{
    qDebug()<<"exit!!!";
    close();
}

void CustomWidget::trayIconActivatedSlot(QSystemTrayIcon::ActivationReason reason)
{
    if(reason==QSystemTrayIcon::DoubleClick)
    {
        show();
    }
}
