#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QDragEnterEvent>
#include <QFileDialog>
#include <QtGui/QImage>
#include <QMainWindow>
#include <QMessageBox>
#include <QMimeData>
#include <QSettings>

#include "allheaders.h"
#include "ui_mainwindow.h"


class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QImage* image;
    static const char *qString2Char(QString string);
    void openImage(const QString& imageFileName);

public slots:
    QImage PixToQImage(PIX *pixs);

protected:
    QGraphicsScene* imageScene;
    void dragEnterEvent(QDragEnterEvent* event);
    void dropEvent(QDropEvent* event);
};

#endif // MAINWINDOW_H
