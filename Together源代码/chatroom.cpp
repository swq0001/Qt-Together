#include <QUdpSocket>
#include <QHostInfo>
#include <QMessageBox>
#include <QScrollBar>
#include <QDateTime>
#include <QNetworkInterface>
#include <QProcess>
#include <QFileDialog>
#include <QColorDialog>
#include "chatroom.h"
#include"tcpserver.h"
#include"tcpclient.h"
ChatRoom::ChatRoom(QWidget *parent) :
    QWidget(parent)
{
    setWindowTitle(("Together Chat Room"));
    setAttribute(Qt::WA_DeleteOnClose);
    setMouseTracking(true);
//    setWindowOpacity(0.4);
    init();
    udpSocket = new QUdpSocket(this);
    port = qint16(45454);
    udpSocket->bind(port, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
    connect(udpSocket, SIGNAL(readyRead()), this, SLOT(processPendingDatagramsSlot()));
    sendMessage(NewParticipant);// 这里有问题

    server = new TcpServer(this);
    connect(server, SIGNAL(sendFileName(QString)), this, SLOT(getFileNameSlot(QString)));
}

ChatRoom::~ChatRoom()
{

}

// 使用UDP广播发送信息
void ChatRoom::sendMessage(MessageTypes type, QString serverAddress)
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    QString localHostName = QHostInfo::localHostName();
    QString address = getIP();
    out << type << getUserName() << localHostName;

    switch(type)
    {
    case Message :
        if (messageTextEdit->toPlainText() == "") {
            QMessageBox::warning(0,QStringLiteral("警告"),QStringLiteral("发送内容不能为空"),QMessageBox::Ok);
            return;
        }
        out << address << getMessage();
        messageBrowser->verticalScrollBar()
                ->setValue(messageBrowser->verticalScrollBar()->maximum());
        break;

    case NewParticipant :
        out << address;
        break;

    case ParticipantLeft :
        break;

    case FileName : {
        int row = userTableWidget->currentRow();
        QString clientAddress = userTableWidget->item(row, 2)->text();
        out << address << clientAddress << fileName;
        break;
    }

    case Refuse :
        out << serverAddress;
        break;
    }
    udpSocket->writeDatagram(data,data.length(),QHostAddress::Broadcast, port);
}

// 接收UDP信息
void ChatRoom::processPendingDatagramsSlot()
{
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(), datagram.size());
        QDataStream in(&datagram, QIODevice::ReadOnly);
        int messageType;
        in >> messageType;
        QString userName,localHostName,ipAddress,message;
        QString time = QDateTime::currentDateTime()
                .toString("yyyy-MM-dd hh:mm:ss");

        switch(messageType)
        {
        case Message:
            in >> userName >> localHostName >> ipAddress >> message;
            messageBrowser->setTextColor(Qt::blue);
            messageBrowser->setCurrentFont(QFont("Times New Roman",12));
            messageBrowser->append("[ " +userName+" ] "+ time);
            messageBrowser->append(message);
            break;

        case NewParticipant:
            in >>userName >>localHostName >>ipAddress;
            newParticipant(userName,localHostName,ipAddress);
            break;

        case ParticipantLeft:
            in >>userName >>localHostName;
            participantLeft(userName,localHostName,time);
            break;

        case FileName: {
            in >> userName >> localHostName >> ipAddress;
            QString clientAddress, fileName;
            in >> clientAddress >> fileName;
            hasPendingFile(userName, ipAddress, clientAddress, fileName);
            break;
        }

        case Refuse: {
            in >> userName >> localHostName;
            QString serverAddress;
            in >> serverAddress;
            QString ipAddress = getIP();

            if(ipAddress == serverAddress)
            {
                server->refused();
            }
            break;
        }
        }
    }
}

// 处理新用户加入
void ChatRoom::newParticipant(QString userName, QString localHostName, QString ipAddress)
{
    bool isEmpty = userTableWidget->findItems(localHostName, Qt::MatchExactly).isEmpty();
    if (isEmpty) {
        QTableWidgetItem *user = new QTableWidgetItem(userName);
        QTableWidgetItem *host = new QTableWidgetItem(localHostName);
        QTableWidgetItem *ip = new QTableWidgetItem(ipAddress);

        userTableWidget->insertRow(0);
        userTableWidget->setItem(0,0,user);
        userTableWidget->setItem(0,1,host);
        userTableWidget->setItem(0,2,ip);
        messageBrowser->setTextColor(Qt::gray);
        messageBrowser->setCurrentFont(QFont("Times New Roman",10));
        messageBrowser->append(QStringLiteral("%1 在线！").arg(userName));
        userNumLabel->setText(QStringLiteral("在线人数：%1").arg(userTableWidget->rowCount()));

        sendMessage(NewParticipant);
    }
}

// 处理用户离开
void ChatRoom::participantLeft(QString userName, QString localHostName, QString time)
{
    int rowNum = userTableWidget->findItems(localHostName, Qt::MatchExactly).first()->row();
    userTableWidget->removeRow(rowNum);
    messageBrowser->setTextColor(Qt::gray);
    messageBrowser->setCurrentFont(QFont("Times New Roman", 10));
    messageBrowser->append(QStringLiteral("%1 于 %2 离开！").arg(userName).arg(time));
    userNumLabel->setText(QStringLiteral("在线人数：%1").arg(userTableWidget->rowCount()));
}

// 获取ip地址
QString ChatRoom::getIP()
{
    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    foreach (QHostAddress address, list) {
        if(address.protocol() == QAbstractSocket::IPv4Protocol)
            return address.toString();
    }
    return 0;
}

// 获取用户名
QString ChatRoom::getUserName()
{
    QStringList envVariables;
    envVariables << "USERNAME.*" << "USER.*" << "USERDOMAIN.*"
                 << "HOSTNAME.*" << "DOMAINNAME.*";
    QStringList environment = QProcess::systemEnvironment();
    foreach (QString string, envVariables) {
        int index = environment.indexOf(QRegExp(string));
        if (index != -1) {
            QStringList stringList = environment.at(index).split('=');
            if (stringList.size() == 2) {
                return stringList.at(1);
                break;
            }
        }
    }
    return "unknown";
}

// 获得要发送的消息
QString ChatRoom::getMessage()
{
    QString msg = messageTextEdit->toHtml();

    messageTextEdit->clear();
    messageTextEdit->setFocus();
    return msg;
}


// 发送消息
void ChatRoom::sendButtonClickedSlot()
{
    sendMessage(Message);
}

// 获取要发送的文件名
void ChatRoom::getFileNameSlot(QString name)
{
    fileName = name;
    sendMessage(FileName);
}

// 传输文件按钮
void ChatRoom::sendToolBtnClickedSlot()
{
    if(userTableWidget->selectedItems().isEmpty())
    {
        QMessageBox::warning(0, QStringLiteral("选择用户"),
                             QStringLiteral("请先从用户列表选择要传送的用户！"), QMessageBox::Ok);
        return;
    }
    server->show();
    server->initServer();
}

// 是否接收文件
void ChatRoom::hasPendingFile(QString userName, QString serverAddress,
                            QString clientAddress, QString fileName)
{
    QString ipAddress = getIP();
    if(ipAddress == clientAddress)
    {
        int btn = QMessageBox::information(this,QStringLiteral("接受文件"),
                                           QStringLiteral("来自%1(%2)的文件：%3,是否接收？")
                                           .arg(userName).arg(serverAddress).arg(fileName),
                                           QMessageBox::Yes,QMessageBox::No);
        if (btn == QMessageBox::Yes) {
            QString name = QFileDialog::getSaveFileName(0,QStringLiteral("保存文件"),fileName);
            if(!name.isEmpty())
            {
                TcpClient *client = new TcpClient(this);
                client->setFileName(name);
                client->setHostAddress(QHostAddress(serverAddress));
                client->show();
            }
        } else {
            sendMessage(Refuse, serverAddress);
        }
    }
}



// 更改字体族
void ChatRoom::fontComboBoxCurrentFontChangedSlot(QFont f)
{
    font.setFamily(f.family());
    messageTextEdit->setFont(font);
    messageTextEdit->setFocus();
}


// 更改字体大小
void ChatRoom::sizeComboBoxCurrentIndexChangedSlot(QString size)
{
    font.setPointSizeF(size.toDouble());
    messageTextEdit->setFont(font);
    messageTextEdit->setFocus();
}

// 加粗
void ChatRoom::boldToolBtnClickedSlot()
{
    isBold=!isBold;
    font.setBold(isBold);
    messageTextEdit->setFont(font);
    messageTextEdit->setFocus();
}

// 倾斜
void ChatRoom::italicToolBtnClickedSlot()
{
    isItalic=!isItalic;
    font.setItalic(isItalic);
    messageTextEdit->setFont(font);
    messageTextEdit->setFocus();
}

// 下划线
void ChatRoom::underlineToolBtnClickedSlot()
{
    isUnderline=!isUnderline;
    font.setUnderline(isUnderline);
    messageTextEdit->setFont(font);
    messageTextEdit->setFocus();
}

// 颜色
void ChatRoom::colorToolBtnClickedSlot()
{
    color = QColorDialog::getColor(color, this);
    if (color.isValid())
    {
        messageTextEdit->setTextColor(color);
        messageTextEdit->setFocus();
    }
}

void ChatRoom::currentFormatChangedSlot(const QTextCharFormat &format)
{
    fontComboBox->setCurrentFont(format.font());

    // 如果字体大小出错(因为我们最小的字体为9)，使用12
    if (format.fontPointSize() < 9) {
        sizeComboBox->setCurrentIndex(3);
    } else {
        sizeComboBox->setCurrentIndex( sizeComboBox
                                          ->findText(QString::number(format.fontPointSize())));
    }
    boldToolBtn->setChecked(format.font().bold());
    italicToolBtn->setChecked(format.font().italic());
    underlineToolBtn->setChecked(format.font().underline());
    color = format.foreground().color();
}

void ChatRoom::opacitySliderValueChangedSlot()
{
    opacityEffect->setOpacity(opacitySlider->value()/100.0);
}

// 保存聊天记录
void ChatRoom::saveToolBtnClickedSlot()
{
    if (messageBrowser->document()->isEmpty()) {
        QMessageBox::warning(0, QStringLiteral("警告"), QStringLiteral("聊天记录为空，无法保存！"), QMessageBox::Ok);
    } else {
        QString fileName = QFileDialog::getSaveFileName(this,
                                                        QStringLiteral("保存聊天记录"), QStringLiteral("聊天记录"), QStringLiteral("文本(*.txt);;All File(*.*)"));
        if(!fileName.isEmpty())
            saveFile(fileName);
    }
}

// 保存聊天记录
bool ChatRoom::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, QStringLiteral("保存文件"),
                             QStringLiteral("无法保存文件 %1:\n %2").arg(fileName)
                             .arg(file.errorString()));
        return false;
    }
    QTextStream out(&file);
    out << messageBrowser->toPlainText();

    return true;
}

// 清空聊天记录
void ChatRoom::clearToolBtnClickedSlot()
{
    messageBrowser->clear();
}


// 关闭事件
void ChatRoom::closeEvent(QCloseEvent *e)
{
    sendMessage(ParticipantLeft);
    QWidget::closeEvent(e);
}

void ChatRoom::init()
{
    isBold=false;
    isItalic=false;
    isUnderline=false;
    boldToolBtn=new QToolButton(this);
    boldToolBtn->setIcon(QIcon(":/image/images/bold.png"));
    clearToolBtn=new QToolButton(this);
    clearToolBtn->setIcon(QIcon(":/image/images/clear.png"));
    colorToolBtn=new QToolButton(this);
    colorToolBtn->setIcon(QIcon(":/image/images/color.png"));
    italicToolBtn=new QToolButton(this);
    italicToolBtn->setIcon(QIcon(":/image/images/italic.png"));
    saveToolBtn=new QToolButton(this);
    saveToolBtn->setIcon(QIcon(":/image/images/save.png"));
    sendToolBtn=new QToolButton(this);
    sendToolBtn->setIcon(QIcon(":/image/images/send.png"));
    underlineToolBtn=new QToolButton(this);
    underlineToolBtn->setIcon(QIcon(":/image/images/under.png"));

    sendButton=new QPushButton(QStringLiteral("发送"),this);

    fontComboBox=new QFontComboBox(this);
    sizeComboBox=new QComboBox(this);
    QStringList list;
    list.clear();
    list<<tr("9")<<tr("10")<<tr("10.5")<<tr("11")<<tr("12")<<tr("14")
       <<tr("16")<<tr("18")<<tr("20")<<tr("22")<<tr("24")<<tr("26")
      <<tr("28")<<tr("36")<<tr("48")<<tr("72");
    sizeComboBox->addItems(list);
    messageBrowser=new QTextBrowser(this);
    messageTextEdit=new QTextEdit(this);

    opacityEffect=new QGraphicsOpacityEffect();
    this->setGraphicsEffect(opacityEffect);

    opacitySlider=new QSlider(this);
    opacitySlider->setOrientation(Qt::Vertical);
    opacitySlider->setValue(70);

    connect(boldToolBtn,&QToolButton::clicked,this,&ChatRoom::boldToolBtnClickedSlot);
    connect(clearToolBtn,&QToolButton::clicked,this,&ChatRoom::clearToolBtnClickedSlot);
    connect(colorToolBtn,&QToolButton::clicked,this,&ChatRoom::colorToolBtnClickedSlot);
    connect(italicToolBtn,&QToolButton::clicked,this,&ChatRoom::italicToolBtnClickedSlot);
    connect(saveToolBtn,&QToolButton::clicked,this,&ChatRoom::saveToolBtnClickedSlot);
    connect(sendToolBtn,&QToolButton::clicked,this,&ChatRoom::sendToolBtnClickedSlot);
    connect(underlineToolBtn,&QToolButton::clicked,this,&ChatRoom::underlineToolBtnClickedSlot);
    connect(sendButton,&QPushButton::clicked,this,&ChatRoom::sendButtonClickedSlot);

    connect(opacitySlider,&QSlider::valueChanged,this,&ChatRoom::opacitySliderValueChangedSlot);

    connect(fontComboBox,&QFontComboBox::currentFontChanged,this,&ChatRoom::fontComboBoxCurrentFontChangedSlot);
    connect(sizeComboBox,&QComboBox::currentTextChanged,this,&ChatRoom::sizeComboBoxCurrentIndexChangedSlot);

    connect(messageTextEdit, SIGNAL(currentCharFormatChanged(QTextCharFormat)),
            this, SLOT(currentFormatChangedSlot(const QTextCharFormat)));

    userTableWidget=new QTableWidget(this);
//    userTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
//    userTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
//    userTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    userTableWidget->autoFillBackground();
    userTableWidget->setColumnCount(3);
    QStringList header;
    header<<QStringLiteral("用户名")<<QStringLiteral("主机名")<<QStringLiteral("IP地址");
    userTableWidget->setHorizontalHeaderLabels(header);
    userTableWidget->setShowGrid(false);

    userNumLabel=new QLabel(this);

    hbox1=new QHBoxLayout();
    hbox2=new QHBoxLayout();
    vbox1=new QVBoxLayout();
    vbox2=new QVBoxLayout();

    hbox1->addLayout(vbox1);
    hbox1->addLayout(vbox2);

    vbox1->addWidget(userNumLabel);
    vbox1->addWidget(userTableWidget);
    vbox1->addWidget(messageBrowser);
    hbox2->addWidget(fontComboBox);
    hbox2->addWidget(sizeComboBox);
    vbox1->addLayout(hbox2);
    vbox1->addWidget(messageTextEdit);
    vbox1->addWidget(sendButton);

    vbox2->addWidget(boldToolBtn);
    vbox2->addWidget(italicToolBtn);
    vbox2->addWidget(underlineToolBtn);
    vbox2->addWidget(colorToolBtn);
    vbox2->addWidget(saveToolBtn);
    vbox2->addWidget(sendToolBtn);
    vbox2->addWidget(clearToolBtn);
    vbox2->addWidget(opacitySlider);

    setLayout(hbox1);
}

