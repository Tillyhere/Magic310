/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionsearch;
    QAction *actionusers;
    QAction *actionlogin;
    QAction *actionsearch_2;
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 700);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1000, 700));
        MainWindow->setMaximumSize(QSize(1000, 700));
        QFont font;
        font.setFamily(QStringLiteral("Gabriola"));
        MainWindow->setFont(font);
        actionsearch = new QAction(MainWindow);
        actionsearch->setObjectName(QStringLiteral("actionsearch"));
        actionusers = new QAction(MainWindow);
        actionusers->setObjectName(QStringLiteral("actionusers"));
        actionlogin = new QAction(MainWindow);
        actionlogin->setObjectName(QStringLiteral("actionlogin"));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("\347\224\250\346\210\267\347\231\273\345\275\225")));
        actionlogin->setIcon(icon);
        actionsearch_2 = new QAction(MainWindow);
        actionsearch_2->setObjectName(QStringLiteral("actionsearch_2"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(450, 150, 500, 100));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(25);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(750, 500, 200, 100));
        QFont font2;
        font2.setPointSize(25);
        font2.setItalic(true);
        label_2->setFont(font2);
        label_2->setTextFormat(Qt::RichText);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 17));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionlogin);
        menu->addAction(actionsearch_2);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\345\275\261\345\203\217\345\272\227\345\275\261\347\242\237\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
        actionsearch->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionsearch->setToolTip(QApplication::translate("MainWindow", "search", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        actionusers->setText(QApplication::translate("MainWindow", "\347\224\250\346\210\267\347\231\273\345\275\225", Q_NULLPTR));
        actionlogin->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225", Q_NULLPTR));
        actionsearch_2->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionsearch_2->setToolTip(QApplication::translate("MainWindow", "\346\237\245\350\257\242\345\275\261\345\203\217\344\277\241\346\201\257", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("MainWindow", "\346\254\242\350\277\216\344\275\277\347\224\250\345\275\261\345\203\217\347\256\241\347\220\206\347\263\273\347\273\237", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "By \345\210\233\351\200\240310", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWindow", "\345\212\237\350\203\275", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
