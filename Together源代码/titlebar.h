#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>
#include<QLabel>
#include<QPushButton>
enum ButtonType
{
    MIN_CLOSE_BUTTON=0,
    MIN_MAX_CLOSE_BUTTON,
    CLOSE_ONLY_BUTTON
};

class TitleBar : public QWidget
{
    Q_OBJECT
public:
    explicit TitleBar(QWidget *parent = nullptr);
    ~TitleBar();
    //设置标题栏背景颜色，默认非透明
    void setBackgroundColor(int r,int g,int b, bool isTransparent=false);
    //设置标题栏图标
    void setTitleIcon(QString filePath,QSize iconSize=QSize(25,25));
    //设置标题内容
    void setTitleContent(QString titleContent, int titleFontSize=9);
    //设置标题栏长度
    void setTitleWidth(int width);
    //设置标题栏上按钮类型
    void setButtonType(ButtonType buttonType);
    //设置窗口边框宽度
    void setWindowBorderWidth(int borderWidth);

private:
    QLabel *icon;
    QLabel *titleContent;
    QPushButton *minButton,*maxButton,*closeButton;
    int colorR,colorG,colorB;
    bool isPressed;
    QPoint startMovePos;
    QString titleContentString;
    ButtonType buttonType;
    int windowBorderWidth;
    bool isTransparent;
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

    //初始化控件
    void initControls();
    //信号槽的绑定
    void initConnections();

signals:
    void minButtonClickedSignal();
    void maxButtonClickedSignal();
    void closeButtonClickedSignal();

public slots:
    void minButtonClickedSlot();
    void maxButtonClickedSlot();
    void closeButtonClickedSlot();
};

#endif // TITLEBAR_H
