#ifndef RTMPPUSHERWIDGET_H
#define RTMPPUSHERWIDGET_H

#include <QWidget>
#include "rtmppusher.h"
#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
class RtmpPusherWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RtmpPusherWidget(QWidget *parent = nullptr);

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    RtmpPusher *rtmpPusher;
    QVBoxLayout *vLayout;
    QHBoxLayout *hLayout;
    QFormLayout *formLayout;
    QLabel *localVideoUrl,*serverUrl,*statusLabel;
    QLineEdit *localVideoUrlEdit,*serverUrlEdit;
    QPushButton *okBtn,*selectBtn;
    bool isPushing;

public slots:
    void startToPush();
    void showFileDlg();
    void changeStatusLabel();
};

#endif // RTMPPUSHERWIDGET_H
