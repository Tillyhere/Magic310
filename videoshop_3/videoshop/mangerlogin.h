#ifndef MANGERLOGIN_H
#define MANGERLOGIN_H

#include <QDialog>

namespace Ui {
class mangerlogin;
}

class mangerlogin : public QDialog
{
    Q_OBJECT

public:
    explicit mangerlogin(QWidget *parent = nullptr);
    ~mangerlogin();

private:
    Ui::mangerlogin *ui;
};

#endif // MANGERLOGIN_H
