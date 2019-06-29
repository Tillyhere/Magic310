/********************************************************************************
** Form generated from reading UI file 'guihuan.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIHUAN_H
#define UI_GUIHUAN_H

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

class Ui_guihuan
{
public:
    QPushButton *pushButton;
    QFrame *line;
    QLabel *label;
    QFrame *line_2;
    QLabel *label_2;
    QFrame *line_3;
    QLabel *label_3;

    void setupUi(QWidget *guihuan)
    {
        if (guihuan->objectName().isEmpty())
            guihuan->setObjectName(QStringLiteral("guihuan"));
        guihuan->resize(400, 300);
        pushButton = new QPushButton(guihuan);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(290, 260, 75, 23));
        line = new QFrame(guihuan);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(10, 10, 118, 3));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(guihuan);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 10, 54, 12));
        line_2 = new QFrame(guihuan);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(140, 10, 118, 3));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(guihuan);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(160, 10, 54, 12));
        line_3 = new QFrame(guihuan);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(270, 10, 118, 3));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        label_3 = new QLabel(guihuan);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(290, 10, 54, 12));

        retranslateUi(guihuan);

        QMetaObject::connectSlotsByName(guihuan);
    } // setupUi

    void retranslateUi(QWidget *guihuan)
    {
        guihuan->setWindowTitle(QApplication::translate("guihuan", "Form", Q_NULLPTR));
        pushButton->setText(QApplication::translate("guihuan", "\350\277\224\345\233\236", Q_NULLPTR));
        label->setText(QApplication::translate("guihuan", "\345\275\261\347\211\207\345\220\215", Q_NULLPTR));
        label_2->setText(QApplication::translate("guihuan", "\345\275\222\350\277\230\346\203\205\345\206\265", Q_NULLPTR));
        label_3->setText(QApplication::translate("guihuan", "\346\230\257\345\220\246\345\275\222\350\277\230", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class guihuan: public Ui_guihuan {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIHUAN_H
