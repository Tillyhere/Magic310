#include "return.h"
#include "ui_return.h"

return::return(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::return)
{
    ui->setupUi(this);
}

return::~return()
{
delete ui;
}
