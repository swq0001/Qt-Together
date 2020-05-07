#include "rtmppusherwidget.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QCloseEvent>

RtmpPusherWidget::RtmpPusherWidget(QWidget *parent) : QWidget(parent)
{
    setWindowTitle(QStringLiteral("上传视频"));
    setWindowIcon(QIcon(":/image/images/upload.png"));

    localVideoUrl=new QLabel(QStringLiteral("本地视频路径："));
    localVideoUrlEdit=new QLineEdit;
    serverUrl=new QLabel(QStringLiteral("rtmp服务器地址："));
    serverUrlEdit=new QLineEdit;

    formLayout=new QFormLayout;
    formLayout->addRow(localVideoUrl,localVideoUrlEdit);
    formLayout->addRow(serverUrl,serverUrlEdit);

    statusLabel=new QLabel(QStringLiteral("上传状态：未上传"));

    okBtn=new QPushButton(QStringLiteral(" 开始上传"));
    selectBtn=new QPushButton(QStringLiteral("选择视频文件"));

    hLayout=new QHBoxLayout;
    hLayout->addWidget(okBtn);
    hLayout->addWidget(selectBtn);

    vLayout=new QVBoxLayout;
    vLayout->addWidget(statusLabel);
    vLayout->setAlignment(statusLabel,Qt::AlignHCenter);

    vLayout->addLayout(formLayout);
    vLayout->addLayout(hLayout);

    setLayout(vLayout);
    connect(okBtn,&QPushButton::clicked,this,&RtmpPusherWidget::startToPush);
    connect(selectBtn,&QPushButton::clicked,this,&RtmpPusherWidget::showFileDlg);
}

void RtmpPusherWidget::closeEvent(QCloseEvent *event)
{
    if(isPushing)
    {
        QMessageBox msgBox;
        msgBox.setText(QStringLiteral("停止上传视频？"));
        msgBox.setInformativeText(QStringLiteral("停止上传视频的话大家都看不到了！确定吗？"));
        msgBox.setStandardButtons(QMessageBox::Ok|QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Cancel);
        int ret=msgBox.exec();
        if(ret==QMessageBox::Ok)
        {
            event->accept();
            isPushing=false;
            changeStatusLabel();
            return;
        }
    }
    hide();
    event->ignore();
}

void RtmpPusherWidget::startToPush()
{
    rtmpPusher=new RtmpPusher(localVideoUrlEdit->text(),serverUrlEdit->text());
    rtmpPusher->startPushing();
    isPushing=true;
    changeStatusLabel();
}

void RtmpPusherWidget::showFileDlg()
{

    QString videoUrl=QFileDialog::getOpenFileUrl(0,QStringLiteral("选择上传的视频")).toString();
    videoUrl.remove(0,8);//去掉videoUrl开头的file:///

    if(!videoUrl.isEmpty())
    {
        localVideoUrlEdit->setText(videoUrl);
        serverUrlEdit->setText("rtmp://47.100.94.20/live");
    }

}

void RtmpPusherWidget::changeStatusLabel()
{
    if(isPushing)
    {
        statusLabel->setText(QStringLiteral("上传状态：正在上传中..."));
    }
    else
    {
        statusLabel->setText(QStringLiteral("上传状态：未上传"));
    }
}
