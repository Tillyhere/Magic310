#ifndef RENT_H
#define RENT_H

#include <QWidget>

namespace Ui {
class rent;
}

class rent : public QWidget
{
    Q_OBJECT

public:
    explicit rent(QWidget *parent = nullptr);
    ~rent();

private slots:
    void on_pushButton_clicked();

private:
    Ui::rent *ui;
};

#endif // RENT_H
