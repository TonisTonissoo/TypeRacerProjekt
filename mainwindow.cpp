#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "functions.hpp"
#include <chrono>
#include <cstdlib>
#include <ctime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    srand(time(0));
    laused = loeLaused("pikemad_laused.txt");

    if (laused.empty()) {
        ui->labelLaused->setText("Lausefail tühi või puudub!");
    } else {
        connect(ui->lineEditSisestus, &QLineEdit::returnPressed, this, &MainWindow::kontrolliSisestus);
        connect(ui->pushButtonUusLause, &QPushButton::clicked, this, &MainWindow::uusLause);
        uusLause();
    }
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
    // Ei kutsu automaatselt uusLause() – kasutaja vajutab nuppu
}
