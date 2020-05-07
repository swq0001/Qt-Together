#ifndef PERSONALINFODIALOG_H
#define PERSONALINFODIALOG_H

#include <QDialog>
#include<QLabel>
#include<QLineEdit>
#include<QRadioButton>
#include<QButtonGroup>
#include<QTextEdit>
#include<QDateEdit>
#include<QFormLayout>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QGroupBox>
#include<QPixmap>
#include<QPushButton>

class PersonalInfoDialog : public QWidget
{
    Q_OBJECT

public:
    explicit PersonalInfoDialog(QWidget *parent = nullptr);
private:
    QLabel *title,*name,*sex,*birthDate,*signature;//标题、昵称、性别、出生日期及个性签名
    QLineEdit *nameEdit;
    QTextEdit *signatureEdit;
    QButtonGroup *sexButtonsGroup;
    QDateEdit *dateEdit;
    QRadioButton *maleButton,*femaleButton,*secretButton;
    QVBoxLayout *vboxLayout;
    QHBoxLayout *sexHBox,*signatureHBox;
    QFormLayout *formLayout;
    QGroupBox *groupBox;
    QPushButton *avatarButton,*saveButton;

    void setBackgroundImage();
};

#endif // PERSONALINFODIALOG_H
