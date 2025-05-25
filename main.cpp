#include <QApplication>
#include "startwindow.h"
#include <QFile>
#include <QDebug>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QFile styleFile("style.qss");
    if (styleFile.open(QFile::ReadOnly)) {
        QString style = QLatin1String(styleFile.readAll());
        a.setStyleSheet(style);
        qDebug() << "QSS loaded!";
    } else {
        qDebug() << "QSS load failed!";
    }

    StartWindow w;
    w.show();
    return a.exec();
}
