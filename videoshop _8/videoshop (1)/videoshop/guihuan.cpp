#include "guihuan.h"
#include "ui_guihuan.h"
#include "users.h"
guihuan::guihuan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::guihuan)
{
    ui->setupUi(this);
}

guihuan::~guihuan()
{
    delete ui;
}

void guihuan::on_pushButton_clicked()
{
    users *win = new users;//创建登录界面
    win->show();//显示登录界面
   this->close();//把主界面删除
}
