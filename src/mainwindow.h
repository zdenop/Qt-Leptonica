#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui/QImage>
#include <QFileDialog>
#include <QMessageBox>
#include <QSettings>
#include <QDebug>

#include "allheaders.h"
#include "ui_mainwindow.h"


class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QImage* image;

public slots:
    QImage PixToQImage(PIX *pixs);

protected:
  QGraphicsScene* imageScene;
};

#endif // MAINWINDOW_H
