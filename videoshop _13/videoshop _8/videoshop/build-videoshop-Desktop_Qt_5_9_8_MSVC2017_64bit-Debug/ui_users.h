/********************************************************************************
** Form generated from reading UI file 'users.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERS_H
#define UI_USERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_users
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *users)
    {
        if (users->objectName().isEmpty())
            users->setObjectName(QStringLiteral("users"));
        users->resize(568, 297);
        gridLayout = new QGridLayout(users);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer_2 = new QSpacerItem(20, 70, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(137, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(users);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QLatin1String("font: 87 14pt \"Arial\";\n"
"font: 87 36pt \"Arial\";"));

        verticalLayout->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(users);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setStyleSheet(QStringLiteral("font: 87 14pt \"Arial Black\";"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(users);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setStyleSheet(QStringLiteral("font: 87 14pt \"Arial Black\";"));

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(137, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 91, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 1, 1, 1);


        retranslateUi(users);

        QMetaObject::connectSlotsByName(users);
    } // setupUi

    void retranslateUi(QWidget *users)
    {
        users->setWindowTitle(QApplication::translate("users", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("users", "----------------", Q_NULLPTR));
        pushButton->setText(QApplication::translate("users", "\347\247\237\345\200\237\345\212\237\350\203\275", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("users", "\345\275\222\350\277\230\345\212\237\350\203\275", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class users: public Ui_users {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERS_H
