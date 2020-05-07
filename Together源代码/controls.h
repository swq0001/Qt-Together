#ifndef CONTROLS_H
#define CONTROLS_H

#include <QWidget>
#include<QSlider>
#include<QAbstractButton>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QGroupBox>
#include<QPropertyAnimation>
class Controls : public QWidget
{
    Q_OBJECT
public:
    explicit Controls(QWidget *parent = nullptr);

    QAbstractButton *openBtn() const;
    QSlider *slider() const;
    QSlider *getVolume_slider() const;
//    int outsidePixelNum;//露出外面的大小

//    void enterEvent(QEvent *event);
//    void leaveEvent(QEvent *event);
private:
    QSlider *m_slider,*volume_slider;
    QAbstractButton *m_uploadBtn;
    QAbstractButton *m_openBtn;
    QAbstractButton *m_receiveBtn;
    QAbstractButton *m_playBtn;
    QAbstractButton *m_stopBtn;
    QAbstractButton *m_volumeBtn;
    QVBoxLayout *vbox;
    QHBoxLayout *hbox;
//    QPropertyAnimation *opacityAnimation,*popAnimation,*hideAnimation;
//    int animationDuration;

//    void initAnimations();
signals:
    void uploadBtnClickedSignal();
    void openBtnClickedSignal();
    void receiveBtnClickedSignal();
    void playBtnClickedSignal();
    void stopBtnClickedSignal();
    void volumeBtnClickedSignal();

public slots:
    void uploadBtnClicked();
    void openBtnClicked();
    void receiveBtnClicked();
    void playBtnClicked();
    void stopBtnClicked();
    void volumeBtnClicked();

};

#endif // CONTROLS_H
