#ifndef GUIHUAN_H
#define GUIHUAN_H

#include <QWidget>

namespace Ui {
class guihuan;
}

class guihuan : public QWidget
{
    Q_OBJECT

public:
    explicit guihuan(QWidget *parent = nullptr);
    ~guihuan();

private slots:
    void on_pushButton_clicked();

private:
    Ui::guihuan *ui;
};

#endif // GUIHUAN_H
