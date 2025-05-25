#include "leaderboard.h"
#include "ui_leaderboard.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

struct Tulemus {
    QString nimi;
    double wpm;
    double aeg;
    QString kuupaev;
};

Leaderboard::Leaderboard(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Leaderboard)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels({"Nimi", "WPM", "Aeg (s)", "Kuupäev"});

    std::ifstream fail("tulemused.txt");
    std::string rida;
    std::vector<Tulemus> tulemused;

    while (std::getline(fail, rida)) {
        std::istringstream ss(rida);
        std::string nimi, wpmStr, aegStr, kp;
        if (std::getline(ss, nimi, ';') &&
            std::getline(ss, wpmStr, ';') &&
            std::getline(ss, aegStr, ';') &&
            std::getline(ss, kp)) {
            Tulemus t;
            t.nimi = QString::fromStdString(nimi);
            t.wpm = std::stod(wpmStr);
            t.aeg = std::stod(aegStr);
            t.kuupaev = QString::fromStdString(kp);
            tulemused.push_back(t);
        }
    }

    std::sort(tulemused.begin(), tulemused.end(), [](const Tulemus &a, const Tulemus &b) {
        return a.wpm > b.wpm;
    });

    ui->tableWidget->setRowCount(std::min(5, static_cast<int>(tulemused.size())));
    for (int i = 0; i < ui->tableWidget->rowCount(); ++i) {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(tulemused[i].nimi));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(tulemused[i].wpm, 'f', 1)));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(QString::number(tulemused[i].aeg, 'f', 2)));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(tulemused[i].kuupaev));
    }
}

Leaderboard::~Leaderboard()
{
    delete ui;
}
