/********************************************************************************
** Form generated from reading UI file 'leaderboard.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEADERBOARD_H
#define UI_LEADERBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_Leaderboard
{
public:
    QTableWidget *tableWidget;

    void setupUi(QDialog *Leaderboard)
    {
        if (Leaderboard->objectName().isEmpty())
            Leaderboard->setObjectName("Leaderboard");
        Leaderboard->resize(1238, 704);
        tableWidget = new QTableWidget(Leaderboard);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(350, 180, 411, 171));

        retranslateUi(Leaderboard);

        QMetaObject::connectSlotsByName(Leaderboard);
    } // setupUi

    void retranslateUi(QDialog *Leaderboard)
    {
        Leaderboard->setWindowTitle(QCoreApplication::translate("Leaderboard", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Leaderboard: public Ui_Leaderboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEADERBOARD_H
