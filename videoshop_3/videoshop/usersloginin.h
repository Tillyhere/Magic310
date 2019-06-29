#ifndef USERSLOGININ_H
#define USERSLOGININ_H

#include <QDialog>

namespace Ui {
class usersloginin;
}

class usersloginin : public QDialog
{
    Q_OBJECT

public:
    explicit usersloginin(QWidget *parent = nullptr);
    ~usersloginin();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::usersloginin *ui;
};

#endif // USERSLOGININ_H
