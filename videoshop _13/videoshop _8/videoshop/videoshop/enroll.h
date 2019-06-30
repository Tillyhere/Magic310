#ifndef ENROLL_H
#define ENROLL_H

#include <QDialog>
#include<QFile>
namespace Ui {
class enroll;
}

class enroll : public QDialog
{
    Q_OBJECT

public:
    explicit enroll(QWidget *parent = nullptr);
    ~enroll();

private:
    Ui::enroll *ui;
signals:
    void display(int number);

private slots:
    void on_pbt_enroll_clicked();
};

#endif // ENROLL_H
