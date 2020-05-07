#include "logindlg.h"
#include "signupdialog.h"
#include<QSize>
LogInDlg::LogInDlg()
{
    setWindowFlag(Qt::FramelessWindowHint);
    setFixedSize(QSize(600,800));
    setObjectName("LogInDlg");
    initTitleBar();
    setBackgroudImage();

    //设置logo标签
    title=new QLabel(QStringLiteral("Together"),this);
    title->setObjectName("Together");
    title->setFont(QFont(tr("Crimes Times Six"),72));
    //登录界面提示标签
    hint=new QLabel(QStringLiteral("登录"),this);
    hint->setFont(QFont(tr("SimHei"),32));
    //设置标签
    name=new QLabel(QStringLiteral("用户名"),this);
    password=new QLabel(QStringLiteral("密码"),this);
    //设置标签对应输入框
    nameEdit=new QLineEdit(this);
    name->setFont(QFont(tr("SimHei"),20));
    password->setFont(QFont(tr("SimHei"),20));
    nameEdit->setMaximumSize(QSize(350,40));
    passwordEdit=new QLineEdit(this);
    passwordEdit->setMaximumSize(QSize(350,40));
    passwordEdit->setEchoMode(QLineEdit::Password);//设置为密码模式
    //设置格式布局
    formLayout=new QFormLayout;
    formLayout->addRow(name,nameEdit);
    formLayout->addRow(password,passwordEdit);
    formLayout->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);//里面的内容垂直居中
    formLayout->setVerticalSpacing(40);//设置垂直间距

    //设置按钮的布局
    hboxLayout=new QHBoxLayout;

    signIn=new QPushButton(QStringLiteral("登录"));
    signIn->setFont(QFont(tr("SimHei"),12,true));
    signIn->setMaximumSize(QSize(200,35));
    signUp=new QPushButton(QStringLiteral("注册"));
    signUp->setFont(QFont(tr("SimHei"),12,true));
    signUp->setMaximumSize(QSize(200,35));

    signIn->setObjectName("SignIn");
    signUp->setObjectName("SignUp");
    hboxLayout->addWidget(signIn);
    hboxLayout->addWidget(signUp);


    //加入总的垂直布局
    vboxLayout=new QVBoxLayout;
    vboxLayout->addWidget(title);
    vboxLayout->addWidget(hint);
    vboxLayout->addLayout(formLayout);
    vboxLayout->addLayout(hboxLayout);
    vboxLayout->itemAt(0)->setAlignment(Qt::AlignHCenter|Qt::AlignBottom);
    vboxLayout->itemAt(1)->setAlignment(Qt::AlignTop|Qt::AlignHCenter);
    vboxLayout->itemAt(2)->setAlignment(Qt::AlignTop|Qt::AlignHCenter);

    connect(signIn,&QPushButton::clicked,this,&LogInDlg::signInButtonClickedSlot);
    //如果注册按钮signUp被点击，那么执行showSignUpDlg
    connect(signUp,&QPushButton::clicked,this,&LogInDlg::signUpButtonClickedSlot);
    setLayout(vboxLayout);
}

void LogInDlg::initTitleBar()
{
    titleBar=new TitleBar(this);
    titleBar->move(0,0);
    titleBar->setTitleWidth(this->width());
    titleBar->setBackgroundColor(255,0,0,true);
    titleBar->setButtonType(ButtonType::MIN_CLOSE_BUTTON);
    titleBar->show();

    connect(titleBar,&TitleBar::minButtonClickedSignal,this,&LogInDlg::minButtonClickedSlot);
    connect(titleBar,&TitleBar::closeButtonClickedSignal,this,&LogInDlg::closeButtonClickedSlot);
}

void LogInDlg::setBackgroudImage()
{
    this->setStyleSheet("QWidget#LogInDlg{background-image:url(:/image/images/logIn.jpg)}"
                        "QPushButton#SignIn{background-image:url(:/image/images/logIn.jpg)}"
                        "QPushButton#SignUp{background-image:url(:/image/images/logIn.jpg)}");
    //    this->setStyleSheet("background-image:url(:/image/images/logIn.jpg)");
}

void LogInDlg::signInButtonClickedSlot()
{
    customWidget=new CustomWidget();
    customWidget->show();
    close();
}

void LogInDlg::signUpButtonClickedSlot()
{

    SignUpDialog signUpDlg;
    signUpDlg.exec();
}

void LogInDlg::minButtonClickedSlot()
{
    showMinimized();
}

void LogInDlg::closeButtonClickedSlot()
{
    close();
}
