#ifndef RENT_H
#define RENT_H

#include <QWidget>
#include<QFile>
namespace Ui {
class rent;
}

class rent : public QWidget
{
    Q_OBJECT

public:
    explicit rent(QWidget *parent = nullptr);
    ~rent();

private:
    Ui::rent *ui;
};

#endif // RENT_H
