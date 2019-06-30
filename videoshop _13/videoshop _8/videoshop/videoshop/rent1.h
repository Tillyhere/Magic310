#ifndef RENT1_H
#define RENT1_H

#include <QWidget>

namespace Ui {
class rent1;
}

class rent1 : public QWidget
{
    Q_OBJECT

public:
    explicit rent1(QWidget *parent = nullptr);
    ~rent1();
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::rent1 *ui;
};

#endif // RENT1_H
