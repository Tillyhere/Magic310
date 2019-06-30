/********************************************************************************
** Form generated from reading UI file 'usersloginin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERSLOGININ_H
#define UI_USERSLOGININ_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_usersloginin
{
public:
    QLabel *label;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *usersloginin)
    {
        if (usersloginin->objectName().isEmpty())
            usersloginin->setObjectName(QStringLiteral("usersloginin"));
        usersloginin->resize(500, 400);
        usersloginin->setMinimumSize(QSize(500, 400));
        usersloginin->setMaximumSize(QSize(500, 400));
        label = new QLabel(usersloginin);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 500, 150));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\345\260\221\345\204\277\347\256\200\344\275\223"));
        font.setPointSize(24);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("font: 24pt \"\346\226\271\346\255\243\345\260\221\345\204\277\347\256\200\344\275\223\";\n"
"font-color:rgb(255, 224, 99)"));
        label->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(usersloginin);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 250, 100, 30));
        QFont font1;
        font1.setPointSize(10);
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);
        lineEdit_2 = new QLineEdit(usersloginin);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(150, 250, 300, 30));
        lineEdit_2->setEchoMode(QLineEdit::Password);
        label_2 = new QLabel(usersloginin);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(35, 180, 115, 30));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        lineEdit = new QLineEdit(usersloginin);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(150, 180, 300, 30));
        lineEdit->setFont(font1);
        pushButton = new QPushButton(usersloginin);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 330, 100, 30));
        pushButton->setFont(font1);
        pushButton_2 = new QPushButton(usersloginin);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(350, 330, 100, 30));
        pushButton_2->setFont(font1);

        retranslateUi(usersloginin);

        QMetaObject::connectSlotsByName(usersloginin);
    } // setupUi

    void retranslateUi(QDialog *usersloginin)
    {
        usersloginin->setWindowTitle(QApplication::translate("usersloginin", "\347\224\250\346\210\267\347\231\273\345\275\225", Q_NULLPTR));
        label->setText(QApplication::translate("usersloginin", "\345\275\261\345\203\217\347\263\273\347\273\237\347\231\273\345\275\225", Q_NULLPTR));
        label_3->setText(QApplication::translate("usersloginin", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("usersloginin", "\347\224\250\346\210\267\345\220\215\346\210\226ID\357\274\232", Q_NULLPTR));
        lineEdit->setPlaceholderText(QApplication::translate("usersloginin", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\220\215\346\210\226\344\274\232\345\221\230\345\215\241ID", Q_NULLPTR));
        pushButton->setText(QApplication::translate("usersloginin", "\347\231\273\345\275\225", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("usersloginin", "\346\263\250\345\206\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class usersloginin: public Ui_usersloginin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERSLOGININ_H
