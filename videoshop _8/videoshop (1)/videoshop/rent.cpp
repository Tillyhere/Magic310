#include "rent.h"
#include "ui_rent.h"
#include "users.h"
rent::rent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rent)
{
    ui->setupUi(this);
}

rent::~rent()
{
    delete ui;
}

void rent::on_pushButton_clicked()
{
    users *win = new users;//创建登录界面
    win->show();//显示登录界面
   this->close();//把主界面删除
}
