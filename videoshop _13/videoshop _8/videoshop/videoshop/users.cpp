#include "users.h"
#include "ui_users.h"
#include "rent1.h"
#include "guihuan1.h"
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
    rent1 *win = new rent1;//创建登录界面
    win->show();//显示登录界面
   this->close();//把主界面删除
}

void users::on_pushButton_2_clicked()
{
    guihuan1 *win = new guihuan1;//创建登录界面
    win->show();//显示登录界面
    this->close();//把主界面删除
}
