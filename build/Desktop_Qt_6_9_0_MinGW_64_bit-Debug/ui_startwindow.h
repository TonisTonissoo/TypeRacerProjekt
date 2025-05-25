/********************************************************************************
** Form generated from reading UI file 'startwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QLabel *labelTere;
    QLineEdit *lineEditNimi;
    QPushButton *pushButtonStart;
    QPushButton *pushButtonEdetabel;
    QMenuBar *menubar;
    QMenu *menuTypeRacer_Start;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StartWindow)
    {
        if (StartWindow->objectName().isEmpty())
            StartWindow->setObjectName("StartWindow");
        StartWindow->resize(562, 600);
        centralwidget = new QWidget(StartWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(29, 20, 471, 471));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setSpacing(10);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(15, 15, 15, 15);
        labelTere = new QLabel(verticalLayoutWidget);
        labelTere->setObjectName("labelTere");
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        labelTere->setFont(font);
        labelTere->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_3->addWidget(labelTere);

        lineEditNimi = new QLineEdit(verticalLayoutWidget);
        lineEditNimi->setObjectName("lineEditNimi");

        verticalLayout_3->addWidget(lineEditNimi);

        pushButtonStart = new QPushButton(verticalLayoutWidget);
        pushButtonStart->setObjectName("pushButtonStart");

        verticalLayout_3->addWidget(pushButtonStart);

        pushButtonEdetabel = new QPushButton(verticalLayoutWidget);
        pushButtonEdetabel->setObjectName("pushButtonEdetabel");

        verticalLayout_3->addWidget(pushButtonEdetabel);

        StartWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(StartWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 562, 22));
        menuTypeRacer_Start = new QMenu(menubar);
        menuTypeRacer_Start->setObjectName("menuTypeRacer_Start");
        StartWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(StartWindow);
        statusbar->setObjectName("statusbar");
        StartWindow->setStatusBar(statusbar);

        menubar->addAction(menuTypeRacer_Start->menuAction());

        retranslateUi(StartWindow);

        QMetaObject::connectSlotsByName(StartWindow);
    } // setupUi

    void retranslateUi(QMainWindow *StartWindow)
    {
        StartWindow->setWindowTitle(QCoreApplication::translate("StartWindow", "MainWindow", nullptr));
        labelTere->setText(QCoreApplication::translate("StartWindow", "Tere tulemast TypeRacerisse!", nullptr));
        lineEditNimi->setText(QString());
        lineEditNimi->setPlaceholderText(QCoreApplication::translate("StartWindow", "Sisesta oma nimi siia...", nullptr));
        pushButtonStart->setText(QCoreApplication::translate("StartWindow", "Alusta m\303\244ngu", nullptr));
        pushButtonEdetabel->setText(QCoreApplication::translate("StartWindow", "Vaata edetabelit", nullptr));
        menuTypeRacer_Start->setTitle(QCoreApplication::translate("StartWindow", "TypeRacer", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartWindow: public Ui_StartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
