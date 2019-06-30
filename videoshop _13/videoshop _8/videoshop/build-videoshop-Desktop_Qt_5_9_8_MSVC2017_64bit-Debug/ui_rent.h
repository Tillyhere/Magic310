/********************************************************************************
** Form generated from reading UI file 'rent.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENT_H
#define UI_RENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rent
{
public:
    QPushButton *pushButton;
    QFrame *line;
    QLabel *label;
    QLabel *label_2;
    QFrame *line_2;

    void setupUi(QWidget *rent)
    {
        if (rent->objectName().isEmpty())
            rent->setObjectName(QStringLiteral("rent"));
        rent->resize(703, 300);
        pushButton = new QPushButton(rent);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(290, 260, 75, 23));
        line = new QFrame(rent);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 10, 118, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(rent);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 20, 54, 12));
        label_2 = new QLabel(rent);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(470, 20, 54, 12));
        line_2 = new QFrame(rent);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(440, 10, 118, 3));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        retranslateUi(rent);

        QMetaObject::connectSlotsByName(rent);
    } // setupUi

    void retranslateUi(QWidget *rent)
    {
        rent->setWindowTitle(QApplication::translate("rent", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("rent", "\350\277\224\345\233\236", Q_NULLPTR));
        label->setText(QApplication::translate("rent", "\345\275\261\347\211\207\345\220\215", Q_NULLPTR));
        label_2->setText(QApplication::translate("rent", "\346\230\257\345\220\246\347\247\237\345\200\237", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class rent: public Ui_rent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENT_H
