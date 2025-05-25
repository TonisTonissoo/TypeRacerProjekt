#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "startwindow.h"

#include "functions.hpp"
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <QMessageBox>
#include <fstream>
#include <QDate>

MainWindow::MainWindow(const QString& kasutajaNimi, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , kasutaja(kasutajaNimi)
{
    ui->setupUi(this);

    srand(time(0));
    laused = loeLaused("pikemad_laused.txt");

    if (laused.empty()) {
        ui->labelLaused->setText("Lausefail tühi või puudub!");
    } else {
        connect(ui->lineEditSisestus, &QLineEdit::returnPressed, this, &MainWindow::kontrolliSisestus);
        connect(ui->pushButtonUusLause, &QPushButton::clicked, this, &MainWindow::uusLause);
        connect(ui->pushButtonLopeta, &QPushButton::clicked, this, &MainWindow::lopetaMang);

        uusLause();
    }

    setWindowTitle("Tere, " + kasutaja + "!");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::uusLause() {
    lause = laused[rand() % laused.size()];
    ui->labelLaused->setText(QString::fromStdString(lause));
    ui->lineEditSisestus->clear();
    ui->labelTulemus->clear();
    ui->lineEditSisestus->setEnabled(true);
    start = std::chrono::high_resolution_clock::now();
}

void MainWindow::kontrolliSisestus() {
    auto lõpp = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> kestus = lõpp - start;

    std::string sisestus = ui->lineEditSisestus->text().toStdString();
    double märgiTäpsus = arvutaTäpsus(lause, sisestus);
    double sõnaTäpsus = arvutaSõnaTäpsus(lause, sisestus);
    double wpm = arvutaWPM(sisestus, kestus.count());
    std::string analüüs = analyysiTekst(lause, sisestus);

    QString tulemus = QString("Aeg: %1 s\nTähemärgitäpsus: %2%\nSõnatäpsus: %3%\nWPM: %4\n\n%5")
                          .arg(kestus.count(), 0, 'f', 2)
                          .arg(märgiTäpsus, 0, 'f', 1)
                          .arg(sõnaTäpsus, 0, 'f', 1)
                          .arg(wpm, 0, 'f', 1)
                          .arg(QString::fromStdString(analüüs));

    ui->labelTulemus->setText(tulemus);
    ui->lineEditSisestus->setEnabled(false);

    // Salvesta tulemus faili
    std::ofstream fail("tulemused.txt", std::ios::app);
    if (fail.is_open()) {
        QString kuupäev = QDate::currentDate().toString("dd.MM.yyyy");
        fail << kasutaja.toStdString() << ";" << wpm << ";" << kestus.count() << ";" << kuupäev.toStdString() << "\n";
        fail.close();
    }
}

void MainWindow::lopetaMang() {
    QMessageBox::StandardButton vastus;
    vastus = QMessageBox::question(this, "Kinnitus", "Kas soovid mängu lõpetada?",
                                   QMessageBox::Yes|QMessageBox::No);
    if (vastus == QMessageBox::Yes) {
        this->close();

        StartWindow *start = new StartWindow();
        start->show();
    }
}
