#include "usersloginin.h"
#include "ui_usersloginin.h"
#include "enroll.h"
#include<QAbstractAnimation>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QString>
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
    QString username = ui->lineEdit->text();
    QString code=ui->lineEdit_2->text();
    QFile file("user.txt") ;
    int len_name=username.length();
    int len_code=code.length();
    bool flag=0;
    if(!file.open(QFile::ReadOnly|QFile::Text))
    {
        QMessageBox::warning(this,tr("Error"),tr("read file user.txt error:%1").arg(file.errorString()));//
    }
    QTextStream in(&file);//
    QString line=in.readLine();

    while(!line.isNull())
    {
        int length=line.length();
        int count=3;
        int i=0;
        while(length>=0&&count>0)
        {

            if(line[i]==" ")
            {
                count--;
            }
            i++;
        }
        QString temp1=line.mid(i,len_name);
        QString temp2=line.mid(i+1+len_name,len_code);
        if((temp1==username)&&(temp2==code)&&(!username.isEmpty())&&(!code.isEmpty()))
        {
            flag=1;
            users *win = new users;//创建登录界面
            win->show();//显示登录界面
            this->close();//把主界面删除
            break;
        }


        line=in.readLine();
    }
    if(flag!=1)
    {
        QMessageBox::warning(this,"warning","can't find！",QMessageBox::Yes);
    }

}
