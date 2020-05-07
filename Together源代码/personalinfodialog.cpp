#include "personalinfodialog.h"
#include<QDebug>
PersonalInfoDialog::PersonalInfoDialog(QWidget *parent) :
    QWidget(parent)
{
    setWindowTitle("Together");
    setFixedSize(QSize(300,450));
    title=new QLabel(QStringLiteral("头像"));
    title->setFont(QFont(QStringLiteral("宋体"),12,1,false));

    avatarButton=new QPushButton;
    QPixmap avatar(tr(":/image/images/avatar.png"));
    avatarButton->setIcon(avatar);
    avatarButton->setIconSize(QSize(200,200));

    name=new QLabel(QStringLiteral("昵称"));
    name->setMaximumWidth(50);
    sex=new QLabel(QStringLiteral("性别"));
    birthDate=new QLabel(QStringLiteral("出生日期"));
    signature=new QLabel(QStringLiteral("个性签名"));

    nameEdit=new QLineEdit;
    nameEdit->setText("Hu Huiyang");

    maleButton=new QRadioButton(QStringLiteral("男"));
    femaleButton=new QRadioButton(QStringLiteral("女"));
    secretButton=new QRadioButton(QStringLiteral("保密"));

    sexButtonsGroup=new QButtonGroup;
    sexButtonsGroup->addButton(maleButton);
    sexButtonsGroup->addButton(femaleButton);
    sexButtonsGroup->addButton(secretButton);

    sexHBox=new QHBoxLayout;
    sexHBox->addWidget(sex);
    sexHBox->addWidget(maleButton);
    sexHBox->addWidget(femaleButton);
    sexHBox->addWidget(secretButton);

    dateEdit=new QDateEdit;

    signatureEdit=new QTextEdit;
    signatureEdit->setMaximumHeight(60);
    signatureEdit->setText("The best singer among programmers.");
    signature->setBuddy(signatureEdit);

    signatureHBox=new QHBoxLayout;
    signatureHBox->addWidget(signature);
    signatureHBox->addWidget(signatureEdit);

    formLayout=new QFormLayout;
    formLayout->addRow(name,nameEdit);
    formLayout->addRow(birthDate,dateEdit);
    formLayout->setFormAlignment(Qt::AlignLeft);
    formLayout->setMargin(0);//消除边距

    groupBox=new QGroupBox;
    groupBox->setLayout(formLayout);

    saveButton=new QPushButton(QStringLiteral("保存"));
    saveButton->setFixedSize(QSize(50,30));
    vboxLayout=new QVBoxLayout;
    vboxLayout->addWidget(avatarButton);
    vboxLayout->addWidget(title);
    vboxLayout->addWidget(groupBox);
    vboxLayout->addLayout(sexHBox);
    vboxLayout->addLayout(signatureHBox);
    vboxLayout->addWidget(saveButton);

    vboxLayout->setAlignment(title,Qt::AlignHCenter);
    vboxLayout->setAlignment(avatarButton,Qt::AlignHCenter);
    vboxLayout->setAlignment(saveButton,Qt::AlignHCenter);
    setLayout(vboxLayout);
}
