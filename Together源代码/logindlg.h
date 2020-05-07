#ifndef LOGINDLG_H
#define LOGINDLG_H

#include<QDialog>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QFormLayout>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<titlebar.h>
#include<customwidget.h>
class LogInDlg : public QWidget
{
public:
    LogInDlg();
private:
    TitleBar *titleBar;
    CustomWidget *customWidget;
    QVBoxLayout *vboxLayout;//总体布局
    QHBoxLayout *hboxLayout;//按钮的布局
    QFormLayout *formLayout;//输入区域的布局
    QLabel *title,*hint,*name,*password;//标题、用户名及密码标签
    QLineEdit *passwordEdit,*nameEdit;//用户名及密码输入框
    QPushButton *signIn,*signUp;//登录及注册按钮

    void initTitleBar();
    void setBackgroudImage();

private slots:
//    void emitAccept();
    void signInButtonClickedSlot();
    void signUpButtonClickedSlot();
    void minButtonClickedSlot();
    void closeButtonClickedSlot();
};

#endif // LOGINDLG_H
