#include "mainwindow.h"
#include "leaderboard.h"   // lisa see kindlasti, kui sul on Leaderboard klass defineeritud

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow mainWin;
    mainWin.show();

    Leaderboard lbWin;
    lbWin.show();

    return a.exec();
}
