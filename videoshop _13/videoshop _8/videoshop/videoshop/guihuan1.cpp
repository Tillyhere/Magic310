#include "guihuan1.h"
#include "ui_guihuan1.h"
#include "users.h"
#include"guihuan.h"
#include<QAbstractAnimation>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include<QString>
guihuan1::guihuan1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::guihuan1)
{
    ui->setupUi(this);
    QPixmap pixmap = QPixmap(":/back/userslogin_bk.jpg").scaled(this->size());//设置背景
    QPalette  palette (this->palette());
    palette .setBrush(QPalette::Background, QBrush(pixmap));
    this-> setPalette( palette );
}

guihuan1::~guihuan1()
{
    delete ui;
}

void guihuan1::on_pushButton_2_clicked()
{
    users *win = new users;//创建登录界面
    win->show();//显示登录界面
   this->close();//把主界面删除
}

void guihuan1::on_pushButton_clicked()
{
    QString choose = ui->comboBox->currentText();
    QString information=ui->lineEdit->text();
    QFile file("user.txt") ;
    int len_information=information.length();
    bool flag=0;
    if(!file.open(QFile::ReadOnly|QFile::Text))
    {
        QMessageBox::warning(this,tr("Error"),tr("read file user.txt error:%1").arg(file.errorString()));//
    }
    QTextStream in(&file);//
    QString line=in.readLine();
   if(ui->comboBox->currentText()=="name")
       {
       while(!line.isNull())
       {


           QString temp=line.mid(0,len_information);
           if((temp==information)&&(!information.isEmpty()))
           {
               flag=1;
  QMessageBox::information(this,"back","succees！",QMessageBox::Yes);
           }


           line=in.readLine();
       }
       if(flag!=1)
       {
           QMessageBox::warning(this,"warning","defeat",QMessageBox::Yes);
       }
   }
   if(ui->comboBox->currentText()=="id")
   {
       while(!line.isNull())
       {
           int length=line.length();
           int count=1;
           int i=0;
           while(length>=0&&count>0)
           {

               if(line[i]==" ")
               {
                   count--;
               }
               i++;
           }
           QString temp=line.mid(i,len_information);
           if((temp==information)&&(!information.isEmpty()))
           {
               flag=1;
               QMessageBox::information(this,"back","succees！",QMessageBox::Yes);
           }


           line=in.readLine();
       }
       if(flag!=1)
       {
           QMessageBox::warning(this,"warning","defeat！",QMessageBox::Yes);
       }
   }
}
