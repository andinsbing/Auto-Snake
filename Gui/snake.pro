#-------------------------------------------------
#
# Project created by QtCreator 2017-10-11T00:24:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = snake
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    abstractautosnakestrategy.cpp \
    astarstrategy.cpp \
    astarstrategyfactor.cpp \
    autosnake.cpp \
    autosnakestrategyfactory.cpp \
    console.cpp \
    flagcontroller.cpp \
    gamecontroler.cpp \
    gamescene.cpp \
    gameview.cpp \
    greedstrategycpp.cpp \
    macro.cpp \
    map.cpp \
    snake.cpp \
    consoleproxy.cpp \
    game.cpp \
    gamegraphicsItem.cpp

HEADERS  += widget.h \
    abstractautosnakestrategy.h \
    astarstrategy.h \
    astarstrategyfactor.h \
    autosnake.h \
    autosnakestrategyfactory.h \
    console.h \
    flagcontroller.h \
    gamecontroler.h \
    gamescene.h \
    gameview.h \
    global.h \
    greedstrategy.h \
    macro.h \
    map.h \
    position.h \
    snake.h \
    timer.h \
    console_main.h \
    consoleproxy.h \
    game.h \
    gamegraphicsItem.h

FORMS    += widget.ui

DISTFILES += \
    snake.pro.user \
    config.ini \
    temp.ini
