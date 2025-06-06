QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    leaderboard.cpp \
    main.cpp \
    mainwindow.cpp \
    functions.cpp \
    startwindow.cpp

HEADERS += \
    leaderboard.h \
    mainwindow.h \
    functions.hpp \
    startwindow.h

FORMS += \
    mainwindow.ui \
    startwindow.ui \
    leaderboard.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
