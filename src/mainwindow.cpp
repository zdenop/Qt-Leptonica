#include <QMimeData>
#include <QUrl>

#include "mainwindow.h"
#include "settings.h"
#include "dialogs/dpidialog.h"

MainWindow::MainWindow(QWidget *parent, const QString &fileName)
  : QMainWindow(parent) {
  setupUi(this);

  _zoom = new QLabel();
  _zoom->setToolTip(QString("Zoom factor"));
  _zoom->setFrameStyle(QFrame::Sunken);
  _zoom->setAlignment(Qt::AlignHCenter);
  _zoom->setMaximumWidth(50);
  this->statusBar()->addPermanentWidget(_zoom, 1);

  setAcceptDrops(true);

  fileWatcher = 0;
  imageItem = 0;

  gViewResult->viewport()->setGeometry(QRect(0,0,0,0));
  imageScene = new Scene();
  connect(imageScene, SIGNAL(dropedFilename(QString)),
          this, SLOT(openImage(QString)));
  connect(imageScene, SIGNAL(sceneScaleChanged(qreal)),
          this, SLOT(changeSceneScale(qreal)));
  connect(imageScene, SIGNAL(rotateImage(int)),
          this, SLOT(rotate(int)));
  connect(imageScene, SIGNAL(imageInfoTriggered()), this, SLOT(imageInfo()));
  connect(imageScene, SIGNAL(detectOrientationSignal()), this,
          SLOT(detectOrientation()));

  gViewResult->setScene(imageScene);
  gViewResult->setRenderHint(QPainter::Antialiasing);
  gViewResult->setCacheMode(QGraphicsView::CacheBackground);
  gViewResult->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
  gViewResult->setOptimizationFlags(QGraphicsView::DontSavePainterState | QGraphicsView::DontAdjustForAntialiasing);
  gViewResult->viewport()->setSizeIncrement(gViewResult->sceneRect().width(),gViewResult->sceneRect().height());
  gViewResult->viewport()->setSizeIncrement(gViewResult->sceneRect().width(),gViewResult->sceneRect().height());

  connect(actionAbout, SIGNAL(triggered()), this, SLOT(about()));
  connect(actionAbout_Qt, SIGNAL(triggered()), this, SLOT(aboutQt()));

  for (int i = 0; i < MaxRecentFiles; ++i) {
    recentFileActs[i] = new QAction(this);
    recentFileActs[i]->setVisible(false);
    connect(recentFileActs[i], SIGNAL(triggered()),
            this, SLOT(openRecentFile()));
  }

  fSeparatorAct = menuFile->addSeparator();
  for (int i = 0; i < MaxRecentFiles; ++i)
    menuFile->addAction(recentFileActs[i]);
  updateRecentFileActions();

  readSettings(true);
  if (fileName.isEmpty()) {
    // Open last file on init if there was no argument
    recentFile = recentFileActs[0]->data().toString();
  } else {
    recentFile = fileName;
    setZoom(1.0);
  }
  if (!recentFile.isEmpty())
    openImage(recentFile);
}

void MainWindow::updateRecentFileActions() {
  QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                     SETTING_ORGANIZATION, SETTING_APPLICATION);
  QStringList files = settings.value("recentFileList").toStringList();

  int numRecentFiles = qMin(files.size(), static_cast<int>(MaxRecentFiles));

  for (int i = 0; i < numRecentFiles; ++i) {
    QString text = tr("&%1 %2").arg(i + 1).arg(QFileInfo(files[i]).fileName());

    recentFileActs[i]->setText(text);
    recentFileActs[i]->setData(files[i]);
    recentFileActs[i]->setVisible(true);
  }
  for (int j = numRecentFiles; j < MaxRecentFiles; ++j)
    recentFileActs[j]->setVisible(false);

  fSeparatorAct->setVisible(numRecentFiles > 0);
}

void MainWindow::openRecentFile() {
  QAction* action = qobject_cast<QAction*>(sender());

  if (action)
    openImage(action->data().toString());
}

QImage MainWindow::PixToQImage(PIX *pixs) {
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

  QImage::Format format;
  if (depth == 1)
    format = QImage::Format_Mono;
  else if (depth == 8)
    format = QImage::Format_Indexed8;
  else
    format = QImage::Format_RGB32;

  QImage result((uchar*)s_data, width, height, bytesPerLine, format);
  if (depth == 1) {
    result.setColorTable(_bwCT);
  }  else if (depth == 8)  {
    result.setColorTable(_grayscaleCT);
  } else {
    result.setColorTable(_grayscaleCT);
  }

  if (result.isNull()) {
    static QImage none(0,0,QImage::Format_Invalid);
    qDebug() << "***Invalid format!!!";
    return none;
  }

  // QRgb *line = (QRgb*)(result.scanLine(0));
  // QColor color = QColor::fromRgb(result.pixel(0,0));
  return result.rgbSwapped();
}

MainWindow::~MainWindow() {
}

/*
 * Provide information about application
 */
void MainWindow::about() {
  QString abouttext =
    tr("<h1>%1 %2</h1>").arg(SETTING_APPLICATION).arg(VERSION);

  abouttext.append(tr("<p>playground for leptonica and "));
  abouttext.append(tr("<a href=\"http://www.qt.io/\">Qt</a></p>"));
  abouttext.append(tr("<p><b>Leptonica version:</b><br/> %1<br/>").arg(
                     getLeptonicaVersion()));
  abouttext.append(tr("<b>Image libraries in Leptonica:</b><br/> %1</p>").arg(
                     getImagelibVersions()));
  abouttext.append(tr("<p>Project page: <a href=%1>%2</a></p>").
                   arg(PROJECT_URL).arg(PROJECT_URL_NAME));
  abouttext.append(tr("Copyright 2015 Zdenko Podobný</p>"));
  abouttext.append(tr("<p>This software is released under "
                      "<a href=\"http://www.apache.org/licenses/LICENSE-2.0\"" \
                      ">Apache License 2.0</a></p>"));
  QMessageBox::about(this, tr("About application"), abouttext);
}

/*
 * Provide information about Qt version
 */
void MainWindow::aboutQt() {
  QMessageBox::aboutQt(this, tr("About Qt"));
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
 * Add "*" to filename if file was modified, otherwise windows title is set to
 * filename
 */
void MainWindow::updateTitle() {
  QString title = recentFile;
  if (modified)
    title += " *";
  this->setWindowTitle(title);
}

/*
 * openImage with leptonica
 */
void MainWindow::openImage(const QString& imageFileName) {
  if (!imageFileName.isEmpty()) {
    pixs = pixRead(qString2Char(imageFileName));
    if (!pixs) {
      this->statusBar()->showMessage(
        tr("Cannot open input file: %1").arg(imageFileName),
        4000);
      return;
    }
  }

  if (setPixToScene()) {
    addToResentFiles(imageFileName);
    modified = false;
  }
}

bool MainWindow::setPixToScene() {
    if (imageItem) {
      imageScene->removeItem(static_cast<QGraphicsItem*>(imageItem));
      delete imageItem;
    }
    QImage image = PixToQImage(pixs);
    imageItem = imageScene->addPixmap(QPixmap::fromImage(image));
    on_actionZoom_to_original_triggered();
    setZoomStatus();
    return true;
}

void MainWindow::addToResentFiles(QString filename) {
  recentFile = filename;
  setFileWatcher(filename);
  updateTitle();

  QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                     SETTING_ORGANIZATION, SETTING_APPLICATION);
  QStringList files = settings.value("recentFileList").toStringList();
  files.removeAll(filename);
  files.prepend(filename);
  while (files.size() > MaxRecentFiles)
    files.removeLast();

  settings.setValue("recentFileList", files);
  updateRecentFileActions();
}

void MainWindow::on_actionOpenFile_triggered() {
  QString filetype = "Image files (*.bmp *.png *.jpeg *.jpg *.tif *.tiff);;";
  filetype += "Tiff files (*.tif *.tiff);;All files (*.*)";
  QString last_path = QFileInfo(recentFile).absolutePath();
  QString fileName = QFileDialog::getOpenFileName(
                       this,
                       tr("Select image file..."),
                       last_path,
                       filetype);
  if (!fileName.isEmpty()) {
    openImage(fileName);
  }
}

void MainWindow::on_actionSave_triggered() {
  l_int32  ret;
  l_int32 format = pixGetInputFormat(pixs);
  char * cFilename = recentFile.toLatin1().data();
  ret = pixWrite(cFilename, pixs, format);
  if (ret) {
    statusBar()->showMessage(tr("Saving failed with error code %1").arg(ret), 2000);
  } else {
    statusBar()->showMessage(tr("File saved"), 2000);
    modified = false;
    updateTitle();
  }
}

void MainWindow::on_actionSaveAs_triggered() {
  l_int32  ret;
  l_int32 format;
  QString fileName = QFileDialog::getSaveFileName(this,
                     tr("Save image as..."),
                     recentFile,
                     tr("All files (*)"));

  if (fileName.isEmpty())
    return;
  QStringList myOptions;
  myOptions << "bmp" << "jpg" << "png" << "tif" << "gif";
  QString ext = QFileInfo(fileName).suffix();
  switch (myOptions.indexOf(ext)) {
  case 0:
    format = IFF_BMP;
    break;
  case 1:
    format = IFF_JFIF_JPEG;
    break;
  case 2:
    format = IFF_PNG;
    break;
  case 3:
    format = IFF_TIFF_LZW;
    break;
  case 4:
    format = IFF_GIF;
    break;
  default:
    format = pixs->informat;
    break;
  }

  char * cFilename = fileName.toLatin1().data();
  ret = pixWrite(cFilename, pixs, format);
  if (ret) {
    statusBar()->showMessage(tr("Saving failed with error code %1").arg(ret), 2000);
  } else {
    statusBar()->showMessage(tr("File saved as %1").arg(fileName), 2000);
    addToResentFiles(fileName);
    modified = false;
    updateTitle();
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

void MainWindow::setZoom(float scale) {
  QTransform transform;
  transform.scale(scale, scale);
  gViewResult->setTransform(transform);
  setZoomStatus();
}

void MainWindow::changeSceneScale(qreal scale) {
  gViewResult->scale(scale, scale);
  setZoomStatus();
}

void MainWindow::on_actionZoom_to_original_triggered() {
  setZoom(1);
}

void MainWindow::on_actionZoom_in_triggered() {
  changeSceneScale(1.2);
}

void MainWindow::on_actionZoom_out_triggered() {
  changeSceneScale(1/1.2);
}

void MainWindow::on_actionFit_to_window_triggered() {
  float viewWidth = gViewResult->viewport()->width();
  float viewHeight = gViewResult->viewport()->height();
  float zoomFactor;
  float ratio = viewWidth / viewHeight;
  float aspectRatio = static_cast<float>(pixs->w / pixs->h);

  if (ratio > aspectRatio) {
    zoomFactor = viewHeight / pixs->h;
  } else {
    zoomFactor = viewWidth / pixs->w;
  }
  setZoom(zoomFactor);
}

void MainWindow::on_actionFit_to_height_triggered() {
  float viewHeight = gViewResult->viewport()->height();
  float zoomFactor = viewHeight / pixs->h;
  setZoom(zoomFactor);
}

void MainWindow::on_actionFit_to_width_triggered() {
  float viewWidth = gViewResult->viewport()->width();
  float zoomFactor = viewWidth / pixs->w;
  setZoom(zoomFactor);
}

void MainWindow::setZoomStatus() {
  qreal zoomratio = gViewResult->transform().m11();
  _zoom->setText(QString("%1%").arg(qRound(zoomratio * 100)));
}

void MainWindow::imageInfo() {
    QString aboutImage = tr("<h1>Image info</h1>");
    aboutImage.append(tr("<p style='color:blue'>"));
    aboutImage.append(tr("width in pixels: %1<br/>").arg(pixs->w));
    aboutImage.append(tr("height in pixels: %1<br/>").arg(pixs->h));
    aboutImage.append(tr("depth in bits (bpp): %1<br/>").arg(pixs->d));
    aboutImage.append(tr("number of samples per pixel [spp]: %1<br/>")
                      .arg(pixs->spp));
    aboutImage.append(tr("32-bit words/line [wpl]: %1<br/>").arg(pixs->wpl));
    aboutImage.append(tr("resolution: %1x%2<br/>").arg(pixs->xres)
                      .arg(pixs->yres));
    aboutImage.append(tr("input format: %1</p>").arg(pixGetInputFormat(pixs)));
    char *text = pixGetText(pixs);
    if (text)
      aboutImage.append(tr("text string associated with pix: %1</p>")
                        .arg(text));
    QMessageBox::about(this, tr("About image"), aboutImage);
}

/*
 * Rotate pixs by number of 90 degree cw rotations
 */
void MainWindow::rotate(int quads) {
    PIX *pixd;
    pixd = pixRotateOrth(pixs, quads);
    pixs = pixCopy(NULL, pixd);
    setPixToScene();
    pixDestroy(&pixd);
    modified = true;
    updateTitle();
}

/*
 * Page orientation detection (four 90 degree angles) Rasterop implementation
 */
void MainWindow::detectOrientation() {
    l_int32   orient, alt_rot;
    l_float32 upconf1, leftconf1;
    PIX       *fpixs;

    fpixs = pixConvertTo1(pixs, 130);
    pixOrientDetect(fpixs, &upconf1, &leftconf1, 0, 0);
    makeOrientDecision(upconf1, leftconf1, 0, 0, &orient, 1);

    if ((upconf1 > 1) && abs(upconf1) > abs(leftconf1)) alt_rot = 0;
    if ((leftconf1 > 1) && abs(leftconf1) > abs(upconf1)) alt_rot = 90;
    if ((upconf1 < -1) && abs(upconf1) > abs(leftconf1)) alt_rot = 180;
    if ((leftconf1 < -1) && abs(leftconf1) > abs(upconf1)) alt_rot = 270;

    if (orient == L_TEXT_ORIENT_UNKNOWN) {
        statusBar()->showMessage(
                    tr("Confidence is low; no determination is made. "
                       "But maybe there is %1 deg rotation.").arg(alt_rot),
                    4000);
    } else if (orient == L_TEXT_ORIENT_UP) {
        statusBar()->showMessage(tr("Text is rightside-up"), 4000);
        alt_rot = 0;
    } else if (orient == L_TEXT_ORIENT_LEFT) {
        statusBar()->showMessage(tr("Text is rotated 90 deg ccw"), 4000);
        alt_rot = 90;
    } else if (orient == L_TEXT_ORIENT_DOWN) {
        statusBar()->showMessage(tr("Text is upside-down"), 4000);
        alt_rot = 180;
    } else {  /* orient == L_TEXT_ORIENT_RIGHT */
        statusBar()->showMessage(tr("Text is rotated 90 deg cw"), 4000);
        alt_rot = 270;
    }
    pixDestroy(&fpixs);

    if (alt_rot) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, tr("Fix orientation?"),
                                      tr("Rotate image by %1 degrees?").
                                      arg(alt_rot),
                                      QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            rotate(alt_rot/90);
            qDebug() << "Yes was clicked " << alt_rot/90;
        }
    }
}

void MainWindow::on_actionChange_resolution_triggered() {
    DPIDialog dpi_dialog(this, pixs->xres, pixs->yres);

    if (dpi_dialog.exec() == QDialog::Accepted) {
      int x_dpi = dpi_dialog.xDPI->value();
      int y_dpi = dpi_dialog.yDPI->value();
      if (x_dpi != pixs->xres || y_dpi != pixs->yres) {
          modified = true;
          pixSetResolution(pixs, x_dpi, y_dpi);
          updateTitle();
      }
    }
}

void MainWindow::on_actionToBinary_triggered() {
    PIX *pixc, *pixg, *pixb, *pixsg, *pixd;
    /* Convert the RGB image to grayscale. */
    pixsg = pixConvertRGBToLuminance(pixs);

    /* Remove the text in the fg. */
    pixc = pixCloseGray(pixsg, 25, 25);

    /* Smooth the bg with a convolution. */
    // pixsm = pixBlockconv(pixc, 15, 15);
    // pixDestroy(&pixsm);

    /* Normalize for uneven illumination on gray image. */
    pixBackgroundNormGrayArrayMorph(pixsg, NULL, 4, 5, 200, &pixg);
    pixc = pixApplyInvBackgroundGrayMap(pixsg, pixg, 4, 4);
    pixDestroy(&pixsg);
    pixDestroy(&pixg);

    /* Increase the dynamic range. */
    // make dark gray *black* and light gray *white*
    pixd = pixGammaTRC(NULL, pixc, 1.0, 50, 220);
    pixDestroy(&pixc);

    /* Threshold to 1 bpp. */
    pixs = pixThresholdToBinary(pixd, 120);
    pixDestroy(&pixd);

    //pixs = pixCopy(NULL, pixb);
    setPixToScene();
    pixDestroy(&pixb);

    modified = true;
    updateTitle();
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
    if (!recentFile.isEmpty())
        setZoom(settings.value("lastZoom").toFloat());
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
  settings.setValue("lastZoom", gViewResult->transform().m11());
  settings.endGroup();
}

void MainWindow::closeEvent(QCloseEvent* event) {
  writeSettings();
  event->accept();
}
