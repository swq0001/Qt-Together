#ifndef SIGNUPDIALOG_H
#define SIGNUPDIALOG_H

#include <QDialog>
#include<QLabel>
#include<QLineEdit>
#include<QVBoxLayout>
#include<QFormLayout>
#include<QPushButton>
#include<QGroupBox>
namespace Ui {
class SignUpDialog;
}

class SignUpDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SignUpDialog(QWidget *parent = nullptr);
    ~SignUpDialog();

private:
    Ui::SignUpDialog *ui;
    QVBoxLayout *vboxLayout;
    QFormLayout *formLayout;
    QLabel *title,*name,*password,*password1,*email;
    QLineEdit *nameEdit,*passwordEdit,*password1Edit,*emailEdit;
    QPushButton *signUpButton;

    void setBackgroundImage();
};

#endif // SIGNUPDIALOG_H
