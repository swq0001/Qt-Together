#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QWidget>
#include <QtAV>
#include<chatroom.h>

QT_BEGIN_NAMESPACE
class RtmpPusher;
class QString;
class RtmpPusherWidget;
class Controls;
class QPropertyAnimation;
class QSlider;
QT_END_NAMESPACE
class VideoPlayer : public QWidget
{
    Q_OBJECT
public:
    explicit VideoPlayer(QWidget *parent = 0);

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;
public slots:
    void openMedia();
    void receiveRtmpStream();
    void seekBySlider(int value);
    void seekBySlider();
    void playPause();
    void initRtmpPusherWidget();
    void showRtmpPusherWidget();

private slots:
    void updateSlider(qint64 value);
    void updateSlider();
    void updateSliderUnit();
    void onVolumeSliderValueChanged();
    void stop();
private:
    QtAV::VideoOutput *m_vo;
    QtAV::AVPlayer *m_player;
    ChatRoom *chatRoom;
    Controls *controls;
    QSlider *m_slider,*volume_slider;//引用controls里面的m_slider
    int m_unit;
    QString fileUrl,receiveServerUrl;
    RtmpPusherWidget *rtmpPusherWidget;
    QPropertyAnimation *showControlsAnimation;
    qreal convertVolume(int volume);
    void initVolume();
};

#endif // VIDEOPLAYER_H
