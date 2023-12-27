#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <leptonica/allheaders.h>

#include <QDebug>
#include <QDragEnterEvent>
#include <QFileDialog>
#include <QFileSystemWatcher>
#include <QGraphicsItem>
#include <QLabel>
#include <QMainWindow>
#include <QMessageBox>
#include <QSettings>
#include <stack>

#include "ui_mainwindow.h"

#if QT_VERSION >= QT_VERSION_CHECK(5, 0, 0)
#include <QGuiApplication>
#endif

#include "scene.h"

class MainWindow : public QMainWindow, public Ui::MainWindow {
    Q_OBJECT

   public:
    explicit MainWindow(QWidget *parent = 0,
                        const QString &fileName = QString());
    ~MainWindow();
    static const char *qString2Char(QString string);

   public slots:
    QImage PixToQImage(PIX *pixs);
    PIX *QImageToPIX(const QImage &qImage);

   protected:
    Scene *imageScene;
    bool modified;
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
    void closeEvent(QCloseEvent *event);

   private:
    QFileSystemWatcher *fileWatcher;
    void setFileWatcher(const QString &fileName);
    void readSettings(bool init);
    void writeSettings();
    void updateTitle();

    void addToResentFiles(QString filename);
    void updateRecentFileActions();
    enum { MaxRecentFiles = 8 };
    QAction *fSeparatorAct;
    QAction *recentFileActs[MaxRecentFiles];
    QString recentFile;
    PIX *pixs;
    std::stack<PIX *> undoPixStack;
    std::stack<PIX *> redoPixStack;

    QLabel *_zoom;
    void zoomOriginal();
    void zoomIn();
    void zoomOut();
    void zoomToSelection();
    void zoomToFit();
    void zoomToHeight();
    void zoomToWidth();
    void setZoomStatus();
    void setZoom(float scale);
    bool setPixToScene();
    bool setPixToScene(PIX *lep_pix);
    PIX *cleanDarkBackground(int blackval, int whiteval, int thresh);
    int blackval, whiteval, thresh;
    void createUndoStackAndActions();
    void cleanUndoStack();

   private Q_SLOTS:
    void on_actionOpenFile_triggered();
    void on_actionReloadFile_triggered();
    void on_actionSave_triggered();
    void on_actionSaveAs_triggered();

    void on_actionZoom_to_original_triggered();
    void on_actionZoom_in_triggered();
    void on_actionZoom_out_triggered();
    void on_actionFit_to_window_triggered();
    void on_actionFit_to_height_triggered();
    void on_actionFit_to_width_triggered();
    void changeSceneScale(qreal scale);
    void rotate(int quads);
    void crop(QRectF rect);
    void on_actionRotateCW_triggered();
    void on_actionRotateCCW_triggered();
    void on_actionRotate180_triggered();
    void on_actionDetectOrientation_triggered();

    void on_actionPaste_triggered();
    void on_actionChange_resolution_triggered();
    void on_actionSetFormat_triggered();
    void on_actionBinarizeUnIl_triggered();
    void on_actionDewarp_triggered();
    void on_actionDeskew_triggered();
    void on_actionCleanDarkBackground_triggered();
    void slotCleanDarkBackground(int blackval, int whiteval, int thresh);
    void on_actionRemovelines_triggered();
    void on_actionConvert2GS_triggered();

   private slots:
    void pix_undo();
    void pix_redo();
    void storeUndoPIX(PIX *newPix);
    void imageInfo();
    void openRecentFile();
    void openImage(const QString &imageFileName);
    void slotfileChanged(const QString &fileName);
    void about();
    void aboutQt();
};

#endif  // MAINWINDOW_H
