/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelLaused;
    QLineEdit *lineEditSisestus;
    QPushButton *pushButtonUusLause;
    QPushButton *pushButtonLopeta;
    QLabel *labelTulemus;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(562, 724);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(9, 20, 541, 661));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setSpacing(10);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(15, 15, 15, 15);
        labelLaused = new QLabel(verticalLayoutWidget);
        labelLaused->setObjectName("labelLaused");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(labelLaused->sizePolicy().hasHeightForWidth());
        labelLaused->setSizePolicy(sizePolicy);
        labelLaused->setMinimumSize(QSize(0, 60));
        labelLaused->setWordWrap(true);

        verticalLayout_3->addWidget(labelLaused);

        lineEditSisestus = new QLineEdit(verticalLayoutWidget);
        lineEditSisestus->setObjectName("lineEditSisestus");

        verticalLayout_3->addWidget(lineEditSisestus);

        pushButtonUusLause = new QPushButton(verticalLayoutWidget);
        pushButtonUusLause->setObjectName("pushButtonUusLause");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButtonUusLause->sizePolicy().hasHeightForWidth());
        pushButtonUusLause->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(pushButtonUusLause);

        pushButtonLopeta = new QPushButton(verticalLayoutWidget);
        pushButtonLopeta->setObjectName("pushButtonLopeta");
        sizePolicy1.setHeightForWidth(pushButtonLopeta->sizePolicy().hasHeightForWidth());
        pushButtonLopeta->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(pushButtonLopeta);

        labelTulemus = new QLabel(verticalLayoutWidget);
        labelTulemus->setObjectName("labelTulemus");
        sizePolicy.setHeightForWidth(labelTulemus->sizePolicy().hasHeightForWidth());
        labelTulemus->setSizePolicy(sizePolicy);
        labelTulemus->setMinimumSize(QSize(0, 200));
        labelTulemus->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);
        labelTulemus->setWordWrap(true);

        verticalLayout_3->addWidget(labelTulemus);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 562, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelLaused->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButtonUusLause->setText(QCoreApplication::translate("MainWindow", "M\303\244ngi uuesti", nullptr));
        pushButtonLopeta->setText(QCoreApplication::translate("MainWindow", "L\303\265peta m\303\244ng", nullptr));
        labelTulemus->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
