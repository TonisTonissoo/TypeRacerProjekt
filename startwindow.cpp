#include "startwindow.h"
#include "ui_startwindow.h"
#include "mainwindow.h"
#include "leaderboard.h"
#include <QMessageBox>

StartWindow::StartWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StartWindow)
{
    ui->setupUi(this);
    connect(ui->pushButtonStart, &QPushButton::clicked, this, &StartWindow::alustaMang);
    connect(ui->pushButtonEdetabel, &QPushButton::clicked, this, &StartWindow::avaEdetabel);
}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::alustaMang()
{
    QString nimi = ui->lineEditNimi->text().trimmed();
    if (nimi.isEmpty()) {
        QMessageBox::warning(this, "Viga", "Palun sisesta nimi.");
        return;
    }

    MainWindow *mang = new MainWindow(nimi);
    mang->show();
    this->close();
}

void StartWindow::avaEdetabel() {
    Leaderboard *edetabel = new Leaderboard(this);
    edetabel->exec();  // Kasutame exec() kuna Leaderboard on QDialog
}
