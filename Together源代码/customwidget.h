#ifndef CUSTOMWIDGET_H
#define CUSTOMWIDGET_H

#include <QMainWindow>
#include<videoplayer.h>
#include<personalinfodialog.h>
#include<QSystemTrayIcon>
#include<chatroom.h>
class QTimer;
class QPushButton;
class QGraphicsOpacityEffect;
class CustomWidget : public QMainWindow
{
    Q_OBJECT

protected:
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void closeEvent(QCloseEvent *event);

public:
    explicit CustomWidget(QWidget *parent = nullptr);

private:
    VideoPlayer *videoPlayer;
    ChatRoom *chatRoom;
    PersonalInfoDialog *personalInfoDialog;
    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;
    QAction *quitAction;
    QPoint currentPos;
    QPixmap pixmap,playIconPixmap,chatIconPixmap,
    configIconPixmap,exitIconPixmap;
    QPushButton *playBtn,*chatBtn,*configBtn,*exitBtn;
    QTimer *timer;
    int angle;
    bool isInIcon;//表示鼠标在标识上面

    QGraphicsOpacityEffect *playBtnOpacity,*chatBtnOpacity,*configBtnOpacity,
    *exitBtnOpacity;
    QPropertyAnimation *playBtnOpacityAnimation,*chatBtnOpacityAnimation,*configBtnOpacityAnimation,
    *exitBtnOpacityAnimation;
    double opacityStartVal,opacityEndVal;
    int opacityAnimationDuration;
    int centerX,centerY;//标志的中心坐标
    bool isPlayingPlay,isPlayingChat,isPlayingConfig,isPlayingExit;
    bool isPressed;
    void initBtns();
    void initTrayIconMenu();
    void initTrayIcon();
    void initArgs();
public slots:
    void playBtnClickedSlot();
    void chatBtnClickedSlot();
    void configBtnClickedSlot();
    void exitBtnClickedSlot();


private slots:
    void trayIconActivatedSlot(QSystemTrayIcon::ActivationReason reason);

};

#endif // CUSTOMWIDGET_H
