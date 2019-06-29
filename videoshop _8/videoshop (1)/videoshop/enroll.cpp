#include "enroll.h"
#include "ui_enroll.h"
#include "usersloginin.h"
enroll::enroll(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::enroll)
{
    ui->setupUi(this);
    QPixmap pixmap = QPixmap(":/back/userslogin_bk.jpg").scaled(this->size());//设置背景
    QPalette  palette (this->palette());
    palette .setBrush(QPalette::Background, QBrush(pixmap));
    this-> setPalette( palette );
}

enroll::~enroll()
{
    delete ui;
}


void enroll::on_pbt_enroll_clicked()
{
    usersloginin *win = new usersloginin;//创建登录界面
    win->show();//显示登录界面
    this->close();//把主界面删除
}
