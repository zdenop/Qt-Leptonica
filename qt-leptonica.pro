#-------------------------------------------------
#
# Project created by QtCreator 2011-05-03T21:08:15
#
#-------------------------------------------------

QT          += core gui

greaterThan(QT_MAJOR_VERSION, 4) {
    message(Qt $$[QT_VERSION] was detected.)
    QT += widgets
    unix:INCLUDEPATH += /opt/include/
    unix:LIBS        += -L/opt/lib
}

TARGET      = qt-leptonica
TEMPLATE    = app


OBJECTS_DIR += temp
MOC_DIR     += temp
UI_DIR      += temp
RCC_DIR     += temp

SOURCES += src/main.cpp\
           src/mainwindow.cpp \
           src/scene.cpp

HEADERS += src/mainwindow.h \
           src/settings.h \
           src/scene.h

FORMS   += src/mainwindow.ui

unix: {
    INCLUDEPATH += /usr/include /usr/local/include
    LIBS        += -L/usr/lib64 -L/usr/local/lib64 -llept
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../lib/ -lliblept168
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../lib/ -lliblept168d

win32: {
    INCLUDEPATH += $$PWD/../include
    }
