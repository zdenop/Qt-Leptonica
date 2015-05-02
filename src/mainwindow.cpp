#include "mainwindow.h"
#include "settings.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    setupUi(this);
    readSettings(true);
    setAcceptDrops(true);

    fileWatcher = 0;
    imageItem = 0;

    gViewResult->viewport()->setGeometry(QRect(0,0,0,0));
    imageScene = new QGraphicsScene;

    qDebug() << "_image2 rect:" << imageScene->sceneRect();
    gViewResult->setScene(imageScene);

    gViewResult->setRenderHint(QPainter::Antialiasing);
    gViewResult->setCacheMode(QGraphicsView::CacheBackground);
    gViewResult->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    gViewResult->setOptimizationFlags( QGraphicsView::DontSavePainterState | QGraphicsView::DontAdjustForAntialiasing);

    qDebug() << "gViewResult size..." << gViewResult->sceneRect().size().toSize();
    gViewResult->viewport()->setSizeIncrement(gViewResult->sceneRect().width(),gViewResult->sceneRect().height());
    gViewResult->viewport()->setSizeIncrement(gViewResult->sceneRect().width(),gViewResult->sceneRect().height());
    qDebug() << "viewport size..." << gViewResult->viewport()->size();
    qDebug() << "gViewResult geometry..." << gViewResult->geometry();
    qDebug() << "gViewResult zoom_fa..." << gViewResult->transform().m11();
    qDebug() << "gViewResult frameGeometry..." << gViewResult->frameGeometry();
    qDebug() << "sceneRect size..." << gViewResult->sceneRect().size();
    openImage("test/building.jpg");
}

QImage MainWindow::PixToQImage(PIX *pixs)
{
    // TODO: first check if pixs is PIX ;-) inputFormat(pix)

    // create color tables
    QVector<QRgb> _bwCT;
    _bwCT.append(qRgb(255,255,255));
    _bwCT.append(qRgb(0,0,0));

    QVector<QRgb> _grayscaleCT(256);
    for (int i = 0; i < 256; i++)  {
        _grayscaleCT.append(qRgb(i, i, i));
       }

    l_uint32 * s_data = pixGetData(pixEndianByteSwapNew(pixs));

    int width = pixGetWidth(pixs);
    int height = pixGetHeight(pixs);
    int depth = pixGetDepth(pixs);
    int bytesPerLine = pixGetWpl(pixs) * 4;

    qDebug() << "  depth:" << depth;
    QImage::Format format;
    if (depth == 1)
            format = QImage::Format_Mono;
    else if (depth == 8)
            format = QImage::Format_Indexed8;
    else
            format = QImage::Format_RGB32;

    qDebug() << "format:" << format;

    qDebug() << "Creating QImage...";
    QImage result((uchar*)s_data, width, height, bytesPerLine, format);
    if (depth == 1) {
        result.setColorTable(_bwCT);
        qDebug() << "  setting B&W palette...";
    }  else if (depth == 8)  {
        result.setColorTable(_grayscaleCT);
        qDebug() << "  setting _grayscaleCT palette...";
    } else {
        result.setColorTable(_grayscaleCT);
        qDebug() << "  setting palette...";
    }

    if (result.isNull())
    {
        static QImage none(0,0,QImage::Format_Invalid);
        qDebug() << "***Invalid format!!!";
        return none;
    }

    qDebug() << "pix->qimage:";
    qDebug() << "W x H:" << result.width() << " x " <<  result.height();
    qDebug() << "format:" << result.format();
    qDebug() << "bytesPerLine: " << result.bytesPerLine();

    QRgb *line = (QRgb*)(result.scanLine(0));
    qDebug() << "line 0: " << line;

    qDebug() << "pixel 0,0 : " << result.pixel(0,0);
    QColor color = QColor::fromRgb(result.pixel(0,0));
    qDebug() << "color pixel 0,0: " << color;

    return result.rgbSwapped();
}

MainWindow::~MainWindow()
{
}

/*
 * QString to const char
 */
const char *MainWindow::qString2Char(QString string) {
    QByteArray byteArray = string.toUtf8();
    const char * constChar = byteArray.data();
    return constChar;
}

/*
 * openImage with leptonica
 */
void MainWindow::openImage(const QString& imageFileName) {
    if (!imageFileName.isEmpty()) {
        QString canonicalImageFileName =
                QFileInfo(imageFileName).canonicalFilePath();

        PIX *pixs;
        pixs = pixRead(qString2Char(imageFileName));
        if (!pixs) {
            this->statusBar()->showMessage(
                        tr("Cannot open input file: %1").arg(imageFileName),
                        4000);
            return;
        }

        if (imageItem) {
            imageScene->removeItem(static_cast<QGraphicsItem*>(imageItem));
            delete imageItem;
        }
        QImage image = PixToQImage(pixs);
        imageItem = imageScene->addPixmap(QPixmap::fromImage(image));
        this->setWindowTitle(canonicalImageFileName);
        modified = false;
        setFileWatcher(imageFileName);
        pixDestroy(&pixs);
    }
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event) {
  if (event->mimeData()->hasFormat("text/uri-list")) {
    event->acceptProposedAction();
  }
}

void MainWindow::dropEvent(QDropEvent *event) {
  QList<QUrl> urls = event->mimeData()->urls();
  if (urls.count()) {
    QString filename = urls[0].toLocalFile();
    openImage(filename);
    event->acceptProposedAction();
  }
}

/*
 * monitor opened file
 */
void MainWindow::setFileWatcher(const QString & fileName) {
  if (fileWatcher) {
    fileWatcher->removePaths(fileWatcher->files());
  } else {
    fileWatcher = new QFileSystemWatcher(this);
    connect(fileWatcher, SIGNAL(fileChanged(const QString &)),
            this, SLOT(slotfileChanged(const QString &)));
  }
  fileWatcher->addPath(fileName);
}

/*
 * reload if file was changed
 */
void MainWindow::slotfileChanged(const QString &fileName) {
    if (!modified) {
        this->statusBar()->showMessage(
                    tr("Source image was modified! Reloading..."), 4000);
        openImage(fileName);
    }
}

/*
 * Read settings
 */
void MainWindow::readSettings(bool init) {
    QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                       SETTING_ORGANIZATION, SETTING_APPLICATION);

    // run this section only during initializaiton time
    if (init) {
        settings.beginGroup("mainWindow");
        restoreGeometry(settings.value("geometry").toByteArray());
        restoreState(settings.value("state").toByteArray());
        settings.endGroup();
    }
}

/*
 * Write settings
 */
void MainWindow::writeSettings() {
    QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                       SETTING_ORGANIZATION, SETTING_APPLICATION);

    settings.beginGroup("mainWindow");
    settings.setValue("geometry", saveGeometry());
    settings.setValue("state", saveState());
    settings.endGroup();
}

void MainWindow::closeEvent(QCloseEvent* event) {
    writeSettings();
    event->accept();
}
