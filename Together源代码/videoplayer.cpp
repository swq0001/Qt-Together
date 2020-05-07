/*
 * 目前没解决的问题：
 * 1.怎么实现控件悬浮，鼠标移动控件浮现
 * 2.键盘事件连接到播放进度上有问题
 * 3.播放和暂停按钮图标的更替，总是有bug
 * 4.上传mkv格式的视频就会显示输出URL有问题，为什么换个格式就不行。怎么可能会是输出URL有问题？
 * 输出URL一直没变过。
*/

#include "videoplayer.h"
#include <QToolButton>
#include <QSlider>
#include <QLayout>
#include <QMessageBox>
#include <QFileDialog>
#include <QInputDialog>
#include <QStyle>
#include <QAudio>
#include <QKeyEvent>
#include <QMouseEvent>
#include<QPropertyAnimation>
#include"controls.h"
#include "rtmppusherwidget.h"
using namespace QtAV;

VideoPlayer::VideoPlayer(QWidget *parent) : QWidget(parent)
{
    m_unit = 1000;
    setWindowTitle(QStringLiteral("Together播放器"));
    m_player = new AVPlayer(this);

    QVBoxLayout *vl = new QVBoxLayout();
    vl->setMargin(0);
    setLayout(vl);

    m_vo = new VideoOutput(this);
    if (!m_vo->widget())
    {
        QMessageBox::warning(0, QString::fromLatin1("Error"), tr("Can not create video renderer"));
        return;
    }

    m_player->setRenderer(m_vo);
    m_vo->widget()->setMouseTracking(true);
    vl->addWidget(m_vo->widget());

    chatRoom=new ChatRoom(this);
    controls=new Controls(this);

    //引用controls里面的控件
    m_slider=controls->slider();
    m_slider->setOrientation(Qt::Horizontal);
    m_slider->setEnabled(false);//先不能滑动，播放的时候才能滑动

    volume_slider=controls->getVolume_slider();
    volume_slider->setValue(50);

    setMouseTracking(true);

    connect(m_slider, SIGNAL(sliderMoved(int)),SLOT(seekBySlider(int)));
    connect(m_slider, SIGNAL(sliderPressed()), SLOT(seekBySlider()));
    connect(m_player, SIGNAL(positionChanged(qint64)), SLOT(updateSlider(qint64)));
    connect(m_player, SIGNAL(started()), SLOT(updateSlider()));
    connect(m_player, SIGNAL(notifyIntervalChanged()), SLOT(updateSliderUnit()));

    //音量条改变，音量随之改变
    connect(volume_slider,&QSlider::valueChanged,this,&VideoPlayer::onVolumeSliderValueChanged);

    //这里关联槽与信号的另一种写法就不行，这两种写法有什么区别？？
    connect(controls,&Controls::uploadBtnClickedSignal,this,&VideoPlayer::showRtmpPusherWidget);
    connect(controls,&Controls::openBtnClickedSignal, this, &VideoPlayer::openMedia);
    connect(controls,&Controls::receiveBtnClickedSignal,this,&VideoPlayer::receiveRtmpStream);
    connect(controls, &Controls::playBtnClickedSignal, this,&VideoPlayer::playPause);
    connect(controls, &Controls::stopBtnClickedSignal, this, &VideoPlayer::stop);

    initRtmpPusherWidget();
    setAttribute(Qt::WA_DeleteOnClose);//设置这个，就可以在窗口关闭的时候删除该对象，默认情况下是不删除的！
}

void VideoPlayer::keyPressEvent(QKeyEvent *event)
{
    //按↑则增大10音量
    if(event->key()==Qt::Key_Up)
    {
        volume_slider->setValue(volume_slider->value()+10);//不知道这个函数有没有限制增长上限，不然要自己写限制
    }
    //按↓则减小10音量
    if(event->key()==Qt::Key_Down)
    {
        volume_slider->setValue(volume_slider->value()-10);
    }
    //按→则快进一段时间
    if(event->key()==Qt::Key_Right)
    {
        seekBySlider(m_slider->value()+2);
    }
    //按←则后退一段时间
    if(event->key()==Qt::Key_Left)
    {
        seekBySlider(m_slider->value()-2);
    }
    if(event->key()==Qt::Key_Escape)
    {
        setWindowState(Qt::WindowNoState);
    }
}

void VideoPlayer::mouseDoubleClickEvent(QMouseEvent *event)
{
    if(windowState()!=Qt::WindowFullScreen)
    {
       setWindowState(Qt::WindowFullScreen);
    }
    else
        setWindowState(Qt::WindowNoState);
    event->accept();
}

void VideoPlayer::mouseMoveEvent(QMouseEvent *event)
{
    //这里为什么鼠标点一下才能出现啊！好像是省资源默认设置的，怎么搞呢？
    if(event->y()>=height()-controls->height())//80是controls部件的高度，太硬核了。。
    {
        controls->show();
    }
    if(event->y()<height()-controls->height())
    {
        controls->hide();
    }
    if(event->x()<width()-chatRoom->width())
    {
        chatRoom->hide();
    }
    else
    {
        chatRoom->show();
    }
    return;
}

void VideoPlayer::resizeEvent(QResizeEvent *event)
{
    int width=m_vo->widget()->size().width();
    int height=m_vo->widget()->size().height();
    controls->setGeometry(0,5*height/6,width,height/6);
    chatRoom->setGeometry(4*width/5,0,width/5,5*height/6);
}

/*根据服务器地址接受Rtmp流*/
void VideoPlayer::receiveRtmpStream()
{
    bool ok;
    //默认从自己的服务器接收rtmp流
    receiveServerUrl=QInputDialog::getText(this,QStringLiteral("输入服务器地址"),
                                            QStringLiteral("服务器地址："),
                                            QLineEdit::Normal,tr("rtmp://47.100.94.20/live"),&ok);
    if(ok&&!receiveServerUrl.isEmpty())
    {
        m_player->play(receiveServerUrl);
        m_slider->setEnabled(true);
        initVolume();
    }
}

void VideoPlayer::openMedia()
{
    qDebug()<<"open media";
    QString file = QFileDialog::getOpenFileName(0, QStringLiteral("选择一个视频"));
    if (file.isEmpty())
        return;
    m_player->play(file);

    m_slider->setEnabled(true);
    initVolume();
}

void VideoPlayer::seekBySlider(int value)
{
    if (!m_player->isPlaying())
        return;
    m_player->seek(qint64(value*m_unit));
}

void VideoPlayer::seekBySlider()
{
    seekBySlider(m_slider->value());
}

///*这里有个bug，为啥播放、暂停图标不能顺利切换？？*/
void VideoPlayer::playPause()
{
    if (!m_player->isPlaying()) {
        m_player->play();
//        if(m_player->isPlaying())
//        {
//            m_playBtn->setIcon(QIcon(":/image/images/pause.png"));
//        }
        return;
    }
    m_player->pause(!m_player->isPaused());
//    if(m_player->isPaused())
//    {
//        m_playBtn->setIcon(QIcon(":/image/images/play.png"));
//    }
}

void VideoPlayer::stop()
{
    m_player->stop();
    m_slider->setValue(0);
    m_slider->setEnabled(false);
}


void VideoPlayer::updateSlider(qint64 value)
{
    m_slider->setRange(0, int(m_player->duration()/m_unit));
    m_slider->setValue(int(value/m_unit));
}

void VideoPlayer::updateSlider()
{
    updateSlider(m_player->position());
}

void VideoPlayer::updateSliderUnit()
{
    m_unit = m_player->notifyInterval();
    updateSlider();
}

qreal VideoPlayer::convertVolume(int volume)
{
    qreal realVolume=QAudio::convertVolume(volume / qreal(100),
                                           QAudio::LogarithmicVolumeScale,
                                           QAudio::LinearVolumeScale);
    return realVolume;
}

/*根据音量条初始化音量*/
void VideoPlayer::initVolume()
{
    m_player->audio()->setVolume(convertVolume(volume_slider->value()));
}

///*音量条被改变的槽*/
void VideoPlayer::onVolumeSliderValueChanged()
{
    //转换成线性声音,也就是我们听到的音量随音量条线性变化
    qreal realVolume=convertVolume(volume_slider->value());
    m_player->audio()->setVolume(realVolume);
}

void VideoPlayer::initRtmpPusherWidget()
{
    rtmpPusherWidget=new RtmpPusherWidget;
}

void VideoPlayer::showRtmpPusherWidget()
{
    rtmpPusherWidget->show();
}
