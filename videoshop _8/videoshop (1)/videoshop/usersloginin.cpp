#include "usersloginin.h"
#include "ui_usersloginin.h"
#include "enroll.h"
#include "users.h"
usersloginin::usersloginin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::usersloginin)
{
    ui->setupUi(this);
    QPixmap pixmap = QPixmap(":/back/userslogin_bk.jpg").scaled(this->size());//设置背景
    QPalette  palette (this->palette());
    palette .setBrush(QPalette::Background, QBrush(pixmap));
    this-> setPalette( palette );
}

usersloginin::~usersloginin()
{
    delete ui;
}

void usersloginin::on_pushButton_2_clicked()
{
    enroll e;
    e.exec();
}

void usersloginin::on_pushButton_clicked()
{

    users *win = new users;//创建登录界面
    win->show();//显示登录界面
    this->close();//把主界面删除
}
