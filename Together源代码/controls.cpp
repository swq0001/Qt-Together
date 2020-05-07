#include "controls.h"
#include<QToolButton>
#include<QDebug>

Controls::Controls(QWidget *parent) : QWidget(parent)
{
    setMouseTracking(true);
    setWindowFlag(Qt::FramelessWindowHint);
    m_slider = new QSlider();
    m_slider->setOrientation(Qt::Horizontal);
    m_slider->setEnabled(false);//先不能滑动，播放的时候才能滑动

    m_uploadBtn = new QToolButton;
    m_uploadBtn->setIcon(QIcon(":/image/images/upload.png"));

    m_openBtn = new QToolButton;
    m_openBtn->setIcon(QIcon(":/image/images/open.png"));

    m_receiveBtn = new QToolButton;
    m_receiveBtn->setIcon(QIcon(":/image/images/receive.png"));

    m_playBtn = new QToolButton;
    m_playBtn->setIcon(QIcon(":/image/images/play.png"));
//    m_playBtn->setIconSize(m_playBtn->size()*2);

    m_stopBtn = new QToolButton;
    m_stopBtn->setIcon(QIcon(":/image/images/stop.png"));

    //音量按钮
    m_volumeBtn=new QToolButton;
    m_volumeBtn->setIcon(QIcon(":/image/images/volume.png"));

    connect(m_uploadBtn,SIGNAL(clicked()),this,SLOT(uploadBtnClicked()));
    connect(m_openBtn,SIGNAL(clicked()),this,SLOT(openBtnClicked()));
    connect(m_receiveBtn,SIGNAL(clicked()),this,SLOT(receiveBtnClicked()));
    connect(m_playBtn,SIGNAL(clicked()),this,SLOT(playBtnClicked()));
    connect(m_stopBtn,SIGNAL(clicked()),this,SLOT(stopBtnClicked()));
    connect(m_volumeBtn,SIGNAL(clicked()),this,SLOT(volumnBtnClicked()));



    //音量条
    volume_slider=new QSlider(Qt::Horizontal);
    volume_slider->setRange(0,100);
    volume_slider->setValue(50);


    hbox=new QHBoxLayout;
    hbox->addWidget(m_uploadBtn);
    hbox->addWidget(m_openBtn);
    hbox->addWidget(m_receiveBtn);
    hbox->addWidget(m_playBtn);
    hbox->addWidget(m_stopBtn);
    hbox->addWidget(m_volumeBtn);
    hbox->addWidget(volume_slider);


    vbox=new QVBoxLayout;
    vbox->addWidget(m_slider);
    vbox->addLayout(hbox);
    setLayout(vbox);
}

QAbstractButton *Controls::openBtn() const
{
    return m_openBtn;
}

QSlider *Controls::slider() const
{
    return m_slider;
}

QSlider *Controls::getVolume_slider() const
{
    return volume_slider;
}

//void Controls::enterEvent(QEvent *event)
//{
//    popAnimation->start();
//    opacityAnimation->start();
//}

//void Controls::leaveEvent(QEvent *event)
//{
//    hideAnimation->start();
//    opacityAnimation->setDirection(QPropertyAnimation::Backward);
//    opacityAnimation->start();
//}

//void Controls::initAnimations()
//{
//    animationDuration=1000;
//    outsidePixelNum=2;
//    opacityAnimation=new QPropertyAnimation(this,"windowOpacity");
//    opacityAnimation->setStartValue(0);
//    opacityAnimation->setEndValue(1);
//    opacityAnimation->setDuration(animationDuration);

//    popAnimation=new QPropertyAnimation(this,"geometry");
//    popAnimation->setStartValue(QRect(pos(),size()));
//    popAnimation->setEndValue(QRect(x(),y()-height()+outsidePixelNum,width(),height()));
//    popAnimation->setDuration(animationDuration);

//    hideAnimation=new QPropertyAnimation(this,"geometry");
//    hideAnimation->setStartValue(QRect(pos(),size()));
//    hideAnimation->setEndValue(QRect(x(),y()+height()-outsidePixelNum,width(),height()));
//    hideAnimation->setDuration(animationDuration);
//}


void Controls::uploadBtnClicked()
{
    emit uploadBtnClickedSignal();
}

void Controls::openBtnClicked()
{
//    qDebug()<<"OpenBtn clicked";//发射信号是成功的
    emit openBtnClickedSignal();
}

void Controls::receiveBtnClicked()
{
    emit receiveBtnClickedSignal();
}

void Controls::playBtnClicked()
{
    emit playBtnClickedSignal();
}

void Controls::stopBtnClicked()
{
    emit stopBtnClickedSignal();
}

void Controls::volumeBtnClicked()
{
    emit volumeBtnClickedSignal();
}



