#ifndef ENROLL_H
#define ENROLL_H

#include <QDialog>

namespace Ui {
class enroll;
}

class enroll : public QDialog
{
    Q_OBJECT

public:
    explicit enroll(QWidget *parent = nullptr);
    ~enroll();

private slots:
    void on_pbt_enroll_clicked();

private:
    Ui::enroll *ui;
};

#endif // ENROLL_H
