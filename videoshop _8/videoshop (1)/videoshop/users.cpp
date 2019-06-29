#include "users.h"
#include "ui_users.h"
#include "rent.h"
#include "guihuan.h"
users::users(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::users)
{
    ui->setupUi(this);
    QPixmap pixmap = QPixmap(":/back/mainwindow_bg.png").scaled(this->size());//设置背景
    QPalette  palette (this->palette());
    palette .setBrush(QPalette::Background, QBrush(pixmap));
    this-> setPalette( palette );
}

users::~users()
{
    delete ui;
}

void users::on_pushButton_clicked()
{
    rent *win = new rent;//创建登录界面
    win->show();//显示登录界面
   this->close();//把主界面删除
}

void users::on_pushButton_2_clicked()
{
    guihuan *win = new guihuan;//创建登录界面
    win->show();//显示登录界面
    this->close();//把主界面删除
}
