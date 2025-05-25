#include "leaderboard.h"
#include "ui_leaderboard.h"

Leaderboard::Leaderboard(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Leaderboard)
{
    ui->setupUi(this);

    // Siin lisame tabeli veerud ja andmed
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels({"Name", "AVG WPM", "Time", "Date"});

    ui->tableWidget->setRowCount(3);
    ui->tableWidget->setItem(0, 0, new QTableWidgetItem("Mari"));
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem("192.22"));
    ui->tableWidget->setItem(0, 2, new QTableWidgetItem("33.2s"));
    ui->tableWidget->setItem(0, 3, new QTableWidgetItem("25.05"));


    ui->tableWidget->setItem(1, 0, new QTableWidgetItem("Madiz"));
    ui->tableWidget->setItem(1, 1, new QTableWidgetItem("152.2"));
    ui->tableWidget->setItem(1, 2, new QTableWidgetItem("592s"));
    ui->tableWidget->setItem(1, 3, new QTableWidgetItem("25.05"));

}

Leaderboard::~Leaderboard()
{
    delete ui;
}
