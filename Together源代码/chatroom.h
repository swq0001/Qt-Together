#ifndef CHATROOM_H
#define CHATROOM_H
#include <QWidget>
#include <QTextCharFormat>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QFontComboBox>
#include<QComboBox>
#include<QToolButton>
#include<QPushButton>
#include<QTextEdit>
#include<QTextBrowser>
#include<QTableWidget>
#include<QLabel>
#include<QSlider>
#include<QGraphicsOpacityEffect>

class QUdpSocket;
class TcpServer;

// 枚举变量标志信息的类型，分别为消息，新用户加入，用户退出，文件名，拒绝接受文件
enum MessageTypes{Message, NewParticipant, ParticipantLeft, FileName, Refuse};
class ChatRoom : public QWidget
{
    Q_OBJECT

public:
    explicit ChatRoom(QWidget *parent = 0);
    ~ChatRoom();

protected:
    void newParticipant(QString userName,
                        QString localHostName, QString ipAddress);
    void participantLeft(QString userName,
                         QString localHostName, QString time);
    void sendMessage(MessageTypes type, QString serverAddress="");
    QString getIP();
    QString getUserName();
    QString getMessage();
    void hasPendingFile(QString userName, QString serverAddress,
                        QString clientAddress, QString fileName);

    bool saveFile(const QString& fileName);
    void closeEvent(QCloseEvent *);

private:
    QHBoxLayout *hbox1,*hbox2;
    QVBoxLayout *vbox1,*vbox2;
    QSlider *opacitySlider;
    QToolButton *boldToolBtn,*clearToolBtn,*colorToolBtn,*italicToolBtn,
    *saveToolBtn,*sendToolBtn,*underlineToolBtn;
    QPushButton *sendButton;
    QFontComboBox *fontComboBox;
    QComboBox *sizeComboBox;
    QTextBrowser *messageBrowser;
    QTextEdit *messageTextEdit;
    QTableWidget *userTableWidget;
    QLabel *userNumLabel;

    QUdpSocket *udpSocket;
    qint16 port;
    QString fileName;
    TcpServer *server;
    QColor color;
    QFont font;
    QGraphicsOpacityEffect *opacityEffect;
    bool isBold,isItalic,isUnderline;
    void init();

private slots:
    void processPendingDatagramsSlot();
    void getFileNameSlot(QString);
    void fontComboBoxCurrentFontChangedSlot(QFont f);
    void sizeComboBoxCurrentIndexChangedSlot(QString );
    void sendButtonClickedSlot();
    void sendToolBtnClickedSlot();
    void boldToolBtnClickedSlot();
    void italicToolBtnClickedSlot();
    void underlineToolBtnClickedSlot();
    void colorToolBtnClickedSlot();
    void saveToolBtnClickedSlot();
    void clearToolBtnClickedSlot();
    void currentFormatChangedSlot(const QTextCharFormat &format);
    void opacitySliderValueChangedSlot();
};

#endif // CHATROOM_H
