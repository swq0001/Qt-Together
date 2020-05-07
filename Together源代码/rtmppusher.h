#ifndef RTMPPUSHER_H
#define RTMPPUSHER_H
#include<QString>
#include<QThread>

class RtmpPusher:public QThread
{
public:
    RtmpPusher(QString videourl,QString serverUrl);
    void startPushing();

protected:
    void run();
private:
    QString videoUrl,serverUrl;

};

#endif // RTMPPUSHER_H
