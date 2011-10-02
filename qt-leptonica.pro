#-------------------------------------------------
#
# Project created by QtCreator 2011-05-03T21:08:15
#
#-------------------------------------------------

QT       += core gui

TARGET = qt-leptonica
TEMPLATE = app

LIBS        += -L/usr/lib64 -L/usr/local/lib64 -llept
INCLUDEPATH += /usr/include/leptonica /usr/local/include/leptonica

OBJECTS_DIR += temp
MOC_DIR += temp
UI_DIR += temp
RCC_DIR += temp

CONFIG += release

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
