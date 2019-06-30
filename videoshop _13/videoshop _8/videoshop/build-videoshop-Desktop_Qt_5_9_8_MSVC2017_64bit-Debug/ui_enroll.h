/********************************************************************************
** Form generated from reading UI file 'enroll.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ENROLL_H
#define UI_ENROLL_H

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

class Ui_enroll
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *le_name;
    QLineEdit *le_conection;
    QLabel *label_5;
    QLineEdit *le_username;
    QLineEdit *le_password;
    QLineEdit *le_repassword;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *pbt_enroll;
    QLineEdit *le_sex;

    void setupUi(QDialog *enroll)
    {
        if (enroll->objectName().isEmpty())
            enroll->setObjectName(QStringLiteral("enroll"));
        enroll->resize(400, 400);
        enroll->setMinimumSize(QSize(400, 400));
        enroll->setMaximumSize(QSize(400, 400));
        label = new QLabel(enroll);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 20, 300, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\271\346\255\243\345\260\221\345\204\277\347\256\200\344\275\223"));
        font.setPointSize(25);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("font: 25pt \"\346\226\271\346\255\243\345\260\221\345\204\277\347\256\200\344\275\223\";"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(enroll);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 80, 100, 30));
        QFont font1;
        font1.setPointSize(10);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(enroll);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 120, 100, 30));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(enroll);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(50, 160, 100, 30));
        label_4->setAlignment(Qt::AlignCenter);
        le_name = new QLineEdit(enroll);
        le_name->setObjectName(QStringLiteral("le_name"));
        le_name->setGeometry(QRect(150, 80, 200, 30));
        le_conection = new QLineEdit(enroll);
        le_conection->setObjectName(QStringLiteral("le_conection"));
        le_conection->setGeometry(QRect(150, 160, 200, 30));
        label_5 = new QLabel(enroll);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(50, 200, 100, 30));
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);
        le_username = new QLineEdit(enroll);
        le_username->setObjectName(QStringLiteral("le_username"));
        le_username->setGeometry(QRect(150, 200, 200, 30));
        le_password = new QLineEdit(enroll);
        le_password->setObjectName(QStringLiteral("le_password"));
        le_password->setGeometry(QRect(150, 240, 200, 30));
        le_password->setEchoMode(QLineEdit::Password);
        le_repassword = new QLineEdit(enroll);
        le_repassword->setObjectName(QStringLiteral("le_repassword"));
        le_repassword->setGeometry(QRect(150, 280, 200, 30));
        le_repassword->setEchoMode(QLineEdit::Password);
        label_6 = new QLabel(enroll);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(50, 240, 100, 30));
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(enroll);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(50, 280, 100, 30));
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignCenter);
        pbt_enroll = new QPushButton(enroll);
        pbt_enroll->setObjectName(QStringLiteral("pbt_enroll"));
        pbt_enroll->setGeometry(QRect(170, 330, 60, 20));
        le_sex = new QLineEdit(enroll);
        le_sex->setObjectName(QStringLiteral("le_sex"));
        le_sex->setGeometry(QRect(150, 120, 201, 31));

        retranslateUi(enroll);

        QMetaObject::connectSlotsByName(enroll);
    } // setupUi

    void retranslateUi(QDialog *enroll)
    {
        enroll->setWindowTitle(QApplication::translate("enroll", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("enroll", "\347\224\250\346\210\267\346\263\250\345\206\214", Q_NULLPTR));
        label_2->setText(QApplication::translate("enroll", "\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("enroll", "\346\200\247\345\210\253\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("enroll", "\350\201\224\347\263\273\346\226\271\345\274\217\357\274\232", Q_NULLPTR));
        le_name->setPlaceholderText(QApplication::translate("enroll", "\350\257\267\350\276\223\345\205\245\344\275\240\347\232\204\347\234\237\345\256\236\345\247\223\345\220\215", Q_NULLPTR));
        le_conection->setPlaceholderText(QApplication::translate("enroll", "\351\202\256\347\256\261\346\210\226\347\224\265\350\257\235\345\217\267\347\240\201", Q_NULLPTR));
        label_5->setText(QApplication::translate("enroll", "\347\224\250\346\210\267\345\220\215\357\274\232", Q_NULLPTR));
        le_username->setPlaceholderText(QApplication::translate("enroll", "\350\213\261\346\226\207\345\255\227\346\257\215\357\274\214\346\225\260\345\255\227\346\210\226\347\211\271\346\256\212\347\254\246\345\217\267", Q_NULLPTR));
        le_password->setPlaceholderText(QApplication::translate("enroll", "\350\257\267\350\256\276\347\275\256\345\257\206\347\240\201", Q_NULLPTR));
        le_repassword->setPlaceholderText(QApplication::translate("enroll", "\350\257\267\351\207\215\346\226\260\350\276\223\345\205\245\345\257\206\347\240\201", Q_NULLPTR));
        label_6->setText(QApplication::translate("enroll", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        label_7->setText(QApplication::translate("enroll", "\347\241\256\350\256\244\345\257\206\347\240\201:", Q_NULLPTR));
        pbt_enroll->setText(QApplication::translate("enroll", "\346\263\250\345\206\214", Q_NULLPTR));
        le_sex->setPlaceholderText(QApplication::translate("enroll", "\350\257\267\350\276\223\345\205\245\344\275\240\347\232\204\346\200\247\345\210\253", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class enroll: public Ui_enroll {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ENROLL_H
