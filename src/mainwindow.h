#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QDragEnterEvent>
#include <QFileDialog>
#include <QFileSystemWatcher>
#include <QGraphicsItem>
#include <QMainWindow>
#include <QMessageBox>
#include <QSettings>

#include <leptonica/allheaders.h>
#include "ui_mainwindow.h"

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
#include <QGuiApplication>
#endif

class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    static const char *qString2Char(QString string);

public slots:
    QImage PixToQImage(PIX *pixs);

protected:
    QGraphicsScene *imageScene;
    QGraphicsItem *imageItem;
    bool modified;
    void dragEnterEvent(QDragEnterEvent* event);
    void dropEvent(QDropEvent* event);
    void closeEvent(QCloseEvent* event);

private:
    QFileSystemWatcher *fileWatcher;
    void setFileWatcher(const QString & fileName);
    void readSettings(bool init);
    void writeSettings();

    void addToResentFiles(QString filename);
    void updateRecentFileActions();
    enum { MaxRecentFiles = 8 };
    QAction* fSeparatorAct;
    QAction* recentFileActs[MaxRecentFiles];
    QString recentFile;
    PIX *pixs;

private Q_SLOTS:
    void on_actionOpenFile_triggered();
    void on_actionSave_triggered();
    void on_actionSaveAs_triggered();

private slots:
    void openRecentFile();
    void openImage(const QString& imageFileName);
    void slotfileChanged(const QString& fileName);
    void about();
    void aboutQt();
};

#endif // MAINWINDOW_H
