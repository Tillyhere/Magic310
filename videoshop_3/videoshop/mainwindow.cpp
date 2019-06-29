#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "manager.h"
#include "search.h"
#include "usersloginin.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pixmap = QPixmap(":/back/mainwindow_bg.png").scaled(this->size());//设置背景
    QPalette  palette (this->palette());
    palette .setBrush(QPalette::Background, QBrush(pixmap));
    this-> setPalette( palette );
}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionlogin_triggered()
{
    usersloginin a;
    a.exec();
}

void MainWindow::on_actionsearch_2_triggered()
{
    search b;
    b.exec();
}
