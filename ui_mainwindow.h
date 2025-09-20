/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QAction *actionOpenFile;
    QAction *actionSave;
    QAction *actionSaveAs;
    QAction *actionQuit;
    QAction *actionFit_to_window;
    QAction *actionFit_to_height;
    QAction *actionFit_to_width;
    QAction *actionZoom_in;
    QAction *actionZoom_out;
    QAction *actionZoom_to_original;
    QAction *actionBinarizeUnIl;
    QAction *actionChange_resolution;
    QAction *actionDewarp;
    QAction *actionDetectOrientation;
    QAction *actionDeskew;
    QAction *actionCleanDarkBackground;
    QAction *actionReloadFile;
    QAction *actionRotateCW;
    QAction *actionRotateCCW;
    QAction *actionRotate180;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionFixPasteFromPDF;
    QAction *actionSetFormat;
    QAction *actionRemovelines;
    QAction *actionConvert2GS;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionShowLogger;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGraphicsView *gViewResult;
    QMenuBar *menubar;
    QMenu *menuAbout;
    QMenu *menuFile;
    QMenu *menuView;
    QMenu *menuEdit;
    QStatusBar *statusbar;
    QToolBar *viewBar;
    QToolBar *editBar;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout;
    QTextEdit *textEdit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(731, 505);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/binary-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/about"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout->setIcon(icon1);
        actionAbout_Qt = new QAction(MainWindow);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/info.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout_Qt->setIcon(icon2);
        actionOpenFile = new QAction(MainWindow);
        actionOpenFile->setObjectName(QString::fromUtf8("actionOpenFile"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/open"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpenFile->setIcon(icon3);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/save"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon4);
        actionSaveAs = new QAction(MainWindow);
        actionSaveAs->setObjectName(QString::fromUtf8("actionSaveAs"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/saveAs"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveAs->setIcon(icon5);
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/quit"), QSize(), QIcon::Normal, QIcon::Off);
        actionQuit->setIcon(icon6);
        actionFit_to_window = new QAction(MainWindow);
        actionFit_to_window->setObjectName(QString::fromUtf8("actionFit_to_window"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/images/zoom-fit-best.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionFit_to_window->setIcon(icon7);
        actionFit_to_height = new QAction(MainWindow);
        actionFit_to_height->setObjectName(QString::fromUtf8("actionFit_to_height"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/images/zoom-fit-height.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionFit_to_height->setIcon(icon8);
        actionFit_to_width = new QAction(MainWindow);
        actionFit_to_width->setObjectName(QString::fromUtf8("actionFit_to_width"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/images/zoom-fit-width.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionFit_to_width->setIcon(icon9);
        actionZoom_in = new QAction(MainWindow);
        actionZoom_in->setObjectName(QString::fromUtf8("actionZoom_in"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/images/zoom-in.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoom_in->setIcon(icon10);
        actionZoom_out = new QAction(MainWindow);
        actionZoom_out->setObjectName(QString::fromUtf8("actionZoom_out"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/images/zoom-out.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoom_out->setIcon(icon11);
        actionZoom_to_original = new QAction(MainWindow);
        actionZoom_to_original->setObjectName(QString::fromUtf8("actionZoom_to_original"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/images/zoom-original.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoom_to_original->setIcon(icon12);
        actionBinarizeUnIl = new QAction(MainWindow);
        actionBinarizeUnIl->setObjectName(QString::fromUtf8("actionBinarizeUnIl"));
        actionBinarizeUnIl->setIcon(icon);
        actionChange_resolution = new QAction(MainWindow);
        actionChange_resolution->setObjectName(QString::fromUtf8("actionChange_resolution"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/images/change_dpi.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionChange_resolution->setIcon(icon13);
        actionDewarp = new QAction(MainWindow);
        actionDewarp->setObjectName(QString::fromUtf8("actionDewarp"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/images/dewarp.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDewarp->setIcon(icon14);
        actionDetectOrientation = new QAction(MainWindow);
        actionDetectOrientation->setObjectName(QString::fromUtf8("actionDetectOrientation"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/orientation.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionDetectOrientation->setIcon(icon15);
        actionDeskew = new QAction(MainWindow);
        actionDeskew->setObjectName(QString::fromUtf8("actionDeskew"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/deskew.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionDeskew->setIcon(icon16);
        actionCleanDarkBackground = new QAction(MainWindow);
        actionCleanDarkBackground->setObjectName(QString::fromUtf8("actionCleanDarkBackground"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/images/clean_background.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionCleanDarkBackground->setIcon(icon17);
        actionReloadFile = new QAction(MainWindow);
        actionReloadFile->setObjectName(QString::fromUtf8("actionReloadFile"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/reload"), QSize(), QIcon::Normal, QIcon::Off);
        actionReloadFile->setIcon(icon18);
        actionRotateCW = new QAction(MainWindow);
        actionRotateCW->setObjectName(QString::fromUtf8("actionRotateCW"));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/rotateCW.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionRotateCW->setIcon(icon19);
        actionRotateCCW = new QAction(MainWindow);
        actionRotateCCW->setObjectName(QString::fromUtf8("actionRotateCCW"));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/rotateCCW.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionRotateCCW->setIcon(icon20);
        actionRotate180 = new QAction(MainWindow);
        actionRotate180->setObjectName(QString::fromUtf8("actionRotate180"));
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/rotate_180"), QSize(), QIcon::Normal, QIcon::Off);
        actionRotate180->setIcon(icon21);
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/copy"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon22);
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        QIcon icon23;
        icon23.addFile(QString::fromUtf8(":/paste"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon23);
        actionFixPasteFromPDF = new QAction(MainWindow);
        actionFixPasteFromPDF->setObjectName(QString::fromUtf8("actionFixPasteFromPDF"));
        actionFixPasteFromPDF->setCheckable(true);
        actionFixPasteFromPDF->setChecked(true);
        actionSetFormat = new QAction(MainWindow);
        actionSetFormat->setObjectName(QString::fromUtf8("actionSetFormat"));
        QIcon icon24;
        icon24.addFile(QString::fromUtf8(":/properties"), QSize(), QIcon::Normal, QIcon::Off);
        actionSetFormat->setIcon(icon24);
        actionRemovelines = new QAction(MainWindow);
        actionRemovelines->setObjectName(QString::fromUtf8("actionRemovelines"));
        QIcon icon25;
        icon25.addFile(QString::fromUtf8(":/images/remove-line.svg"), QSize(), QIcon::Normal, QIcon::Off);
        actionRemovelines->setIcon(icon25);
        actionConvert2GS = new QAction(MainWindow);
        actionConvert2GS->setObjectName(QString::fromUtf8("actionConvert2GS"));
        QIcon icon26;
        icon26.addFile(QString::fromUtf8(":/grayscale"), QSize(), QIcon::Normal, QIcon::Off);
        actionConvert2GS->setIcon(icon26);
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName(QString::fromUtf8("actionUndo"));
        QIcon icon27;
        icon27.addFile(QString::fromUtf8(":/undo"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon27);
        actionRedo = new QAction(MainWindow);
        actionRedo->setObjectName(QString::fromUtf8("actionRedo"));
        QIcon icon28;
        icon28.addFile(QString::fromUtf8(":/redo"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon28);
        actionShowLogger = new QAction(MainWindow);
        actionShowLogger->setObjectName(QString::fromUtf8("actionShowLogger"));
        actionShowLogger->setCheckable(true);
        actionShowLogger->setChecked(true);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gViewResult = new QGraphicsView(centralwidget);
        gViewResult->setObjectName(QString::fromUtf8("gViewResult"));

        verticalLayout->addWidget(gViewResult);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 731, 22));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        viewBar = new QToolBar(MainWindow);
        viewBar->setObjectName(QString::fromUtf8("viewBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, viewBar);
        editBar = new QToolBar(MainWindow);
        editBar->setObjectName(QString::fromUtf8("editBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, editBar);
        dockWidget = new QDockWidget(MainWindow);
        dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
        dockWidget->setBaseSize(QSize(89, 113));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        gridLayout = new QGridLayout(dockWidgetContents);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textEdit = new QTextEdit(dockWidgetContents);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setAcceptDrops(false);
        textEdit->setReadOnly(true);

        gridLayout->addWidget(textEdit, 0, 0, 1, 1);

        dockWidget->setWidget(dockWidgetContents);
        MainWindow->addDockWidget(Qt::BottomDockWidgetArea, dockWidget);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuAbout->addAction(actionAbout);
        menuAbout->addAction(actionAbout_Qt);
        menuFile->addAction(actionOpenFile);
        menuFile->addAction(actionReloadFile);
        menuFile->addSeparator();
        menuFile->addAction(actionSetFormat);
        menuFile->addAction(actionChange_resolution);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSaveAs);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuView->addAction(actionFit_to_window);
        menuView->addAction(actionFit_to_height);
        menuView->addAction(actionFit_to_width);
        menuView->addSeparator();
        menuView->addAction(actionZoom_to_original);
        menuView->addAction(actionZoom_in);
        menuView->addAction(actionZoom_out);
        menuView->addSeparator();
        menuView->addAction(actionShowLogger);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionFixPasteFromPDF);
        menuEdit->addSeparator();
        menuEdit->addAction(actionRotateCW);
        menuEdit->addAction(actionRotateCCW);
        menuEdit->addAction(actionRotate180);
        menuEdit->addAction(actionDetectOrientation);
        menuEdit->addSeparator();
        menuEdit->addAction(actionDewarp);
        menuEdit->addAction(actionDeskew);
        menuEdit->addSeparator();
        menuEdit->addAction(actionBinarizeUnIl);
        menuEdit->addAction(actionCleanDarkBackground);
        menuEdit->addAction(actionRemovelines);
        menuEdit->addAction(actionConvert2GS);
        viewBar->addAction(actionFit_to_window);
        viewBar->addAction(actionFit_to_height);
        viewBar->addAction(actionFit_to_width);
        viewBar->addSeparator();
        viewBar->addAction(actionZoom_to_original);
        viewBar->addAction(actionZoom_in);
        viewBar->addAction(actionZoom_out);
        editBar->addAction(actionUndo);
        editBar->addAction(actionRedo);
        editBar->addSeparator();
        editBar->addAction(actionChange_resolution);
        editBar->addAction(actionDetectOrientation);
        editBar->addAction(actionBinarizeUnIl);
        editBar->addAction(actionDewarp);
        editBar->addAction(actionDeskew);
        editBar->addAction(actionCleanDarkBackground);
        editBar->addAction(actionRemovelines);
        editBar->addAction(actionConvert2GS);

        retranslateUi(MainWindow);
        QObject::connect(actionQuit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(actionShowLogger, SIGNAL(toggled(bool)), dockWidget, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "QT-leptonica", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About...", nullptr));
        actionAbout_Qt->setText(QCoreApplication::translate("MainWindow", "About Qt", nullptr));
        actionOpenFile->setText(QCoreApplication::translate("MainWindow", "Open File...", nullptr));
#if QT_CONFIG(shortcut)
        actionOpenFile->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSaveAs->setText(QCoreApplication::translate("MainWindow", "Save as...", nullptr));
#if QT_CONFIG(shortcut)
        actionSaveAs->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
#if QT_CONFIG(shortcut)
        actionQuit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFit_to_window->setText(QCoreApplication::translate("MainWindow", "Fit to window", nullptr));
#if QT_CONFIG(shortcut)
        actionFit_to_window->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFit_to_height->setText(QCoreApplication::translate("MainWindow", "Fit to height", nullptr));
        actionFit_to_width->setText(QCoreApplication::translate("MainWindow", "Fit to width", nullptr));
        actionZoom_in->setText(QCoreApplication::translate("MainWindow", "Zoom in", nullptr));
#if QT_CONFIG(shortcut)
        actionZoom_in->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl++", nullptr));
#endif // QT_CONFIG(shortcut)
        actionZoom_out->setText(QCoreApplication::translate("MainWindow", "Zoom out", nullptr));
#if QT_CONFIG(shortcut)
        actionZoom_out->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+-", nullptr));
#endif // QT_CONFIG(shortcut)
        actionZoom_to_original->setText(QCoreApplication::translate("MainWindow", "Zoom to original", nullptr));
#if QT_CONFIG(shortcut)
        actionZoom_to_original->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+*", nullptr));
#endif // QT_CONFIG(shortcut)
        actionBinarizeUnIl->setText(QCoreApplication::translate("MainWindow", "Binarize and fix illumination", nullptr));
#if QT_CONFIG(tooltip)
        actionBinarizeUnIl->setToolTip(QCoreApplication::translate("MainWindow", "Binarize and fix uneven illumination", nullptr));
#endif // QT_CONFIG(tooltip)
        actionChange_resolution->setText(QCoreApplication::translate("MainWindow", "Change resolution (DPI)...", nullptr));
        actionDewarp->setText(QCoreApplication::translate("MainWindow", "Dewarp", nullptr));
        actionDetectOrientation->setText(QCoreApplication::translate("MainWindow", "Detect Orientation...", nullptr));
        actionDeskew->setText(QCoreApplication::translate("MainWindow", "Deskew", nullptr));
        actionCleanDarkBackground->setText(QCoreApplication::translate("MainWindow", "Clean dark background", nullptr));
        actionReloadFile->setText(QCoreApplication::translate("MainWindow", "Reload file", nullptr));
#if QT_CONFIG(shortcut)
        actionReloadFile->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRotateCW->setText(QCoreApplication::translate("MainWindow", "Rotate 90\302\260 CW", nullptr));
#if QT_CONFIG(shortcut)
        actionRotateCW->setShortcut(QCoreApplication::translate("MainWindow", "R", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRotateCCW->setText(QCoreApplication::translate("MainWindow", "Rotate 90\302\260 CCW", nullptr));
#if QT_CONFIG(shortcut)
        actionRotateCCW->setShortcut(QCoreApplication::translate("MainWindow", "L", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRotate180->setText(QCoreApplication::translate("MainWindow", "Rotate 180\302\260", nullptr));
#if QT_CONFIG(shortcut)
        actionRotate180->setShortcut(QCoreApplication::translate("MainWindow", "U", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCopy->setText(QCoreApplication::translate("MainWindow", "Copy", nullptr));
        actionPaste->setText(QCoreApplication::translate("MainWindow", "Paste", nullptr));
#if QT_CONFIG(shortcut)
        actionPaste->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFixPasteFromPDF->setText(QCoreApplication::translate("MainWindow", "Fix paste from pdf", nullptr));
#if QT_CONFIG(shortcut)
        actionFixPasteFromPDF->setShortcut(QCoreApplication::translate("MainWindow", "Meta+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSetFormat->setText(QCoreApplication::translate("MainWindow", "Set fileformat...", nullptr));
        actionRemovelines->setText(QCoreApplication::translate("MainWindow", "Remove lines", nullptr));
        actionConvert2GS->setText(QCoreApplication::translate("MainWindow", "Convert to GrayScale", nullptr));
        actionUndo->setText(QCoreApplication::translate("MainWindow", "Undo", nullptr));
        actionRedo->setText(QCoreApplication::translate("MainWindow", "Redo", nullptr));
        actionShowLogger->setText(QCoreApplication::translate("MainWindow", "Show/Hide Logger", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "About", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        viewBar->setWindowTitle(QCoreApplication::translate("MainWindow", "ViewTools", nullptr));
        editBar->setWindowTitle(QCoreApplication::translate("MainWindow", "editBar", nullptr));
        dockWidget->setWindowTitle(QCoreApplication::translate("MainWindow", "Logger", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
