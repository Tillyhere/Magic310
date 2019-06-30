#ifndef USERS_H
#define USERS_H

#include <QWidget>

namespace Ui {
class users;
}

class users : public QWidget
{
    Q_OBJECT

public:
    explicit users(QWidget *parent = nullptr);
    ~users();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::users *ui;
};

#endif // USERS_H
