#include "startwindow.h"
#include "ui_startwindow.h"
#include "mainwindow.h"
#include <QMessageBox>

StartWindow::StartWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::StartWindow)
{
    ui->setupUi(this);
    connect(ui->pushButtonStart, &QPushButton::clicked, this, &StartWindow::alustaMang);
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

    MainWindow *mang = new MainWindow(nimi);  // <-- edastame nime konstruktorisse
    mang->show();
    this->close();
}
