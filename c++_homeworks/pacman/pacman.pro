QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
INCLUDEPATH += .

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    sources/enemy.cpp \
    sources/entity.cpp \
    sources/gamemap.cpp \
    sources/direction.cpp \
    sources/gametimer.cpp \
    sources/gamemanager.cpp \
    sources/main.cpp \
    sources/pacman.cpp

HEADERS += \
    headers/direction.h \
    headers/gametimer.h \
    headers/square.h \
    headers/point.h \
    headers/gamemanager.h \
    headers/config.h \
    headers/enemy.h \
    headers/entity.h \
    headers/gamemap.h \
    headers/pacman.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    resources/blue-ghost.png \
    resources/orange-ghost.png \
    resources/pacman-down.png \
    resources/pacman-left.png \
    resources/pacman-right.png \
    resources/pacman-up.png \
    resources/point1.png \
    resources/point2.png \
    resources/red-ghost.png \
    resources/white-ghost.png
