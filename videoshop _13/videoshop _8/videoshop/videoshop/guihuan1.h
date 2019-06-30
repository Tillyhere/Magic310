#ifndef GUIHUAN1_H
#define GUIHUAN1_H

#include <QWidget>

namespace Ui {
class guihuan1;
}

class guihuan1 : public QWidget
{
    Q_OBJECT

public:
    explicit guihuan1(QWidget *parent = nullptr);
    ~guihuan1();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::guihuan1 *ui;
};

#endif // GUIHUAN1_H
