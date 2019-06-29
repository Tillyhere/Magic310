#ifndef RETURN_H
#define RETURN_H

#include <QWidget>

namespace Ui {
class return;
}

class return : public QWidget
{
    Q_OBJECT

public:
    explicit return(QWidget *parent = nullptr);
    ~return();

private:
    Ui::return *ui;
};

#endif // RETURN_H
