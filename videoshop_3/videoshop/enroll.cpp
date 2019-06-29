#include "enroll.h"
#include "ui_enroll.h"
#include<QFile>
#include <QMessageBox>
#include<QTextStream>

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
void enroll::on_returnButton_clicked(){   //"主菜单"按钮点击
    emit display(0);
}
void enroll::on_pbt_enroll_clicked()
{  //"添加"按钮点击
     QString name = ui->le_name->text();
     QString sex=ui->le_sex->text();
     QString contact=ui->le_conection->text();
     QString  username=ui->le_username->text();
     QString code= ui->le_password->text();
     QString assured_code=ui->le_repassword->text();
     if(ui->le_name->text() == "" || ui->le_sex->text()==""||ui->le_conection->text()==""||ui->le_username->text() == ""
        ||ui->le_password->text() == ""||ui->le_repassword->text()==""||(code!=assured_code))
     {
         QMessageBox::about(this, "反馈", "注册失败");
     }

     else
     {
     QFile file("user.txt");
     file.open(QIODevice::WriteOnly|QIODevice::Text|QIODevice::Append);
     //open()可以用来打开文件这里QIODevice::WriteOnly代表将文件以只写的方式打开
     //QIODevice::Text代表我们打开的是文本文件，QIODevice::Text会对end-of-line结束符进行转译
     //QIODevice::Append以追加的方式打开，新增加的内容将被追加到文件末尾
     if(!file.isOpen())
     { //如果数据文件没有打开，弹出对话框提示用户
         QMessageBox::about(this, "反馈", "数据文件打开失败");
         return;
     }
     else
     {
     QTextStream out(&file);
     //QTextStream可以进行一些基本的文本读写，比如QString int char之类的数据QDataStream可以进行一个如QMap QPoint之类数据的读写。
     out << name << " " <<  sex << " " << contact << " " << username << " " << code <<" "<<assured_code<< endl;
     //将我们刚刚获取的数据写入文件
     file.close();
     QMessageBox::about(this, "反馈", "插入成功");
     }
     }
     ui->le_name->clear();
     ui->le_sex->clear();
     ui->le_conection->clear();
     ui->le_username->clear();
     ui->le_password->clear();
     ui->le_repassword->clear();
     //将用户输入的数据清空
}





