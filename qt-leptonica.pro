#-------------------------------------------------
#
# Project created by QtCreator 2011-05-03T21:08:15
#
#-------------------------------------------------

QT          += core gui svg

greaterThan(QT_MAJOR_VERSION, 4) {
    message(Qt $$[QT_VERSION] was detected.)
    QT += widgets
#    unix:INCLUDEPATH += /opt/include/
#    unix:LIBS        += -L/opt/lib
}

TARGET      = qt-leptonica
TEMPLATE    = app


OBJECTS_DIR += temp
MOC_DIR     += temp
UI_DIR      += temp
RCC_DIR     += temp

SOURCES += src/main.cpp\
           src/mainwindow.cpp \
           src/scene.cpp \
           src/areaitem.cpp \
           src/qleptonica.cpp \
           dialogs/dpidialog.cpp \
           dialogs/cdbdialog.cpp \
           dialogs/combodialog.cpp

HEADERS += src/mainwindow.h \
           src/settings.h \
           src/scene.h \
           src/areaitem.h \
           src/qleptonica.h \
           dialogs/dpidialog.h \
           dialogs/cdbdialog.h \
           dialogs/combodialog.h

FORMS   += dialogs/mainwindow.ui \
           dialogs/dpidialog.ui \
           dialogs/cdbdialog.ui \
           dialogs/combodialog.ui

RESOURCES += resources/application.qrc

unix: {
    INCLUDEPATH += /usr/include /usr/local/include
    LIBS        += -L/usr/lib64 -L/usr/local/lib64 -llept
}

win32:CONFIG(release, debug|release): LIBS += -L"c:\Program Files (x86)\leptonica\lib" -lleptonica-1.74.2
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../lib/ -lliblept171d

win32: {
    DESTDIR = ./win32
    CONFIG += release embed_manifest_exe
    RC_FILE = resources/win.rc
    INCLUDEPATH += "c:\Program Files (x86)\leptonica\include"
    }
