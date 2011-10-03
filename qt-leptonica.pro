#-------------------------------------------------
#
# Project created by QtCreator 2011-05-03T21:08:15
#
#-------------------------------------------------

QT          += core gui

TARGET      = qt-leptonica
TEMPLATE    = app

unix:INCLUDEPATH += /usr/include/leptonica /usr/local/include/leptonica
unix:LIBS        += -L/usr/lib64 -L/usr/local/lib64 -llept
win32:INCLUDEPATH += $$quote(c:/usr/projects/BuildFolder/include/leptonica)
win32:LIBS        += -Lc:\\usr\\projects\\BuildFolder\\lib -lliblept168

OBJECTS_DIR += temp
MOC_DIR     += temp
UI_DIR      += temp
RCC_DIR     += temp

SOURCES += src/main.cpp\
        src/mainwindow.cpp

HEADERS += src/mainwindow.h

FORMS   += src/mainwindow.ui

win32: {
    DESTDIR = ./
    DIR_SEPARATOR = \
}