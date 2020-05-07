#include "signupdialog.h"
#include "ui_signupdialog.h"
#include<QFont>
SignUpDialog::SignUpDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUpDialog)
{
    ui->setupUi(this);
    setFixedSize(QSize(400,400));
    setBackgroundImage();
    title=new QLabel(QStringLiteral("注册"));
    title->setFont(QFont("SimHei",40,1,false));
    name=new QLabel(QStringLiteral("用户名"));
    name->setFont(QFont("SimHei",18));
    password=new QLabel(QStringLiteral("密码"));
    password->setFont(QFont("SimHei",18));
    password1=new QLabel(QStringLiteral("确认密码"));
    password1->setFont(QFont("SimHei",18));
    email=new QLabel(QStringLiteral("邮箱"));
    email->setFont(QFont("SimHei",18));

    nameEdit=new QLineEdit;
//    nameEdit->setMaximumWidth(250);
    passwordEdit=new QLineEdit;
    passwordEdit->setEchoMode(QLineEdit::Password);
//    passwordEdit->setMaximumWidth(250);
    password1Edit=new QLineEdit;
    password1Edit->setEchoMode(QLineEdit::Password);
//    password1Edit->setMaximumWidth(250);
    emailEdit=new QLineEdit;
//    emailEdit->setMaximumWidth(250);

    formLayout=new QFormLayout;
    formLayout->addRow(name,nameEdit);
    formLayout->addRow(password,passwordEdit);
    formLayout->addRow(password1,password1Edit);
    formLayout->addRow(email,emailEdit);
    formLayout->setSpacing(20);

    signUpButton=new QPushButton(QStringLiteral("确认注册"));
    signUpButton->setObjectName("SignUp");
    signUpButton->setFixedSize(QSize(80,40));
    vboxLayout=new QVBoxLayout;
    vboxLayout->addWidget(title);
    vboxLayout->addLayout(formLayout);
    vboxLayout->addWidget(signUpButton);
    vboxLayout->itemAt(1)->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
    vboxLayout->itemAt(2)->setAlignment(Qt::AlignHCenter);

    vboxLayout->setAlignment(title,Qt::AlignCenter);
    setLayout(vboxLayout);
}

SignUpDialog::~SignUpDialog()
{
    delete ui;
}

void SignUpDialog::setBackgroundImage()
{
    this->setStyleSheet("QDialog{background-image:url(:/image/images/logIn.jpg)}"
                        "QPushButton#SignUp{background-image:url(:/image/images/logIn.jpg)}");
}
