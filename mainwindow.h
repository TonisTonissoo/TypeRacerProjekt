#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <string>
#include <chrono>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(const QString& kasutajaNimi, QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    std::vector<std::string> laused;
    std::string lause;
    QString kasutaja; // <-- kasutaja nimi
    std::chrono::time_point<std::chrono::high_resolution_clock> start;

    void uusLause();
    void kontrolliSisestus();
    void lopetaMang();
};

#endif // MAINWINDOW_H
