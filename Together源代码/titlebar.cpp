#include "titlebar.h"
#include<QHBoxLayout>
#include<QPainter>
#include<QBrush>
#include<QMouseEvent>
#include<QDebug>
const int BUTTON_HEIGHT=30;
const int BUTTON_WIDTH=30;
const int TITLE_HEIGHT=30;
TitleBar::TitleBar(QWidget *parent) : QWidget(parent)
{
    colorR=153;
    colorG=153;
    colorB=153;
    isPressed=false;
    buttonType=MIN_MAX_CLOSE_BUTTON;
    windowBorderWidth=0;
    isTransparent=false;
    initControls();
    initConnections();
}

TitleBar::~TitleBar()
{

}

//初始化控件
void TitleBar::initControls()
{
    icon=new QLabel();
    titleContent=new QLabel();

    minButton=new QPushButton();
    minButton->setIcon(QIcon(":/image/images/minimize.png"));
    maxButton=new QPushButton();
    maxButton->setIcon(QIcon(":/image/images/maximize.png"));
    closeButton=new QPushButton();
    closeButton->setIcon(QIcon(":/image/images/close.png"));

    minButton->setFixedSize(QSize(BUTTON_WIDTH,BUTTON_HEIGHT));
    maxButton->setFixedSize(QSize(BUTTON_WIDTH,BUTTON_HEIGHT));
    closeButton->setFixedSize(QSize(BUTTON_WIDTH,BUTTON_HEIGHT));

    titleContent->setObjectName("TitleContent");
    minButton->setObjectName("MinButton");
    maxButton->setObjectName("MaxButton");
    closeButton->setObjectName("CloseButton");

    QHBoxLayout *hbox=new QHBoxLayout(this);
    hbox->addWidget(icon);
    hbox->addWidget(titleContent);
    hbox->addWidget(minButton);
    hbox->addWidget(maxButton);
    hbox->addWidget(closeButton);

    hbox->setSpacing(0);
    hbox->setContentsMargins(5,0,0,0);
    this->setFixedHeight(TITLE_HEIGHT);
    this->setWindowFlag(Qt::FramelessWindowHint);
}

void TitleBar::initConnections()
{
    connect(minButton,SIGNAL(clicked()),this,SLOT(minButtonClickedSlot()));
    connect(maxButton,SIGNAL(clicked()),this,SLOT(maxButtonClickedSlot()));
    connect(closeButton,SIGNAL(clicked()),this,SLOT(closeButtonClickedSlot()));
}

//绘制标题栏背景色
void TitleBar::paintEvent(QPaintEvent *)
{
    if(!isTransparent)
    {
        QPainter painter(this);
        QPainterPath pathBack;
        pathBack.setFillRule(Qt::WindingFill);
        pathBack.addRoundedRect(QRect(0,0,this->width(),this->height()),3,3);
        painter.setRenderHint(QPainter::Antialiasing,true);
        painter.fillPath(pathBack,QBrush(QColor(colorR,colorG,colorB)));
    }
//    QWidget::paintEvent(event);
}

//设置标题栏背景颜色
void TitleBar::setBackgroundColor(int r, int g, int b, bool isTransparent)
{
    colorR=r;
    colorG=g;
    colorB=b;
    this->isTransparent=isTransparent;
    //调用paintEvent事件
    update();
}

//设置标题栏图标
void TitleBar::setTitleIcon(QString filePath, QSize iconSize)
{
    QPixmap titleIcon(filePath);
    icon->setPixmap(titleIcon.scaled(iconSize));
}

//设置标题内容
void TitleBar::setTitleContent(QString titleContent, int titleFontSize)
{
    //设置字体大小
    QFont font=this->titleContent->font();
    font.setPointSize(titleFontSize);
    this->titleContent->setFont(font);

    //设置标题内容
    this->titleContent->setText(titleContent);
    titleContentString=titleContent;
}

void TitleBar::setTitleWidth(int width)
{
    this->setFixedWidth(width);
}

//设置按钮类型
void TitleBar::setButtonType(ButtonType buttonType)
{
    this->buttonType=buttonType;
    switch(buttonType)
    {
        case MIN_CLOSE_BUTTON:
        {
            maxButton->setVisible(false);
        }
        break;
        case CLOSE_ONLY_BUTTON:
        {
            minButton->setVisible(false);
            maxButton->setVisible(false);
        }
        break;
        default:
            break;
    }
}

//设置窗口边框宽度
void TitleBar::setWindowBorderWidth(int borderWidth)
{
    windowBorderWidth=borderWidth;
}

void TitleBar::mousePressEvent(QMouseEvent *event)
{
    isPressed=true;
    startMovePos=event->globalPos();
}

void TitleBar::mouseMoveEvent(QMouseEvent *event)
{
    if(isPressed)
    {
        QPoint movePoint=event->globalPos()-startMovePos;
        QPoint widgetPos=this->parentWidget()->pos();
        startMovePos=event->globalPos();
        this->parentWidget()->move(widgetPos.x()+movePoint.x(),widgetPos.y()+movePoint.y());
    }
}

void TitleBar::mouseReleaseEvent(QMouseEvent *)
{
    isPressed=false;
}

void TitleBar::minButtonClickedSlot()
{
//    qDebug()<<"min!!!";
    emit minButtonClickedSignal();
}

void TitleBar::maxButtonClickedSlot()
{
//    qDebug()<<"max!!!";
    emit maxButtonClickedSignal();
}

void TitleBar::closeButtonClickedSlot()
{
//    qDebug()<<"close!!!";
    emit closeButtonClickedSignal();
}
