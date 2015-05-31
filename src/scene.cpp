#include "scene.h"

#include <QAction>
#include <QGraphicsSceneMouseEvent>
#include <QMenu>
#include <QMimeData>
#include <QUrl>
#include <QWidget>
#include <QDebug>

Scene::Scene() {
  setBackgroundBrush(Qt::gray);
  this->installEventFilter(this);
}

void Scene::imageInfo() {
  emit imageInfoTriggered();
}

void Scene::rotateCW() {
  emit rotateImage(1);
}

void Scene::rotateCCW() {
  emit rotateImage(3);
}

void Scene::rotateHalf() {
  emit rotateImage(2);
}

void Scene::dragEnterEvent(QGraphicsSceneDragDropEvent * event) {
  event->acceptProposedAction();
}

void Scene::dragLeaveEvent(QGraphicsSceneDragDropEvent * event) {
  event->acceptProposedAction();
}

void Scene::dragMoveEvent(QGraphicsSceneDragDropEvent * event) {
  event->acceptProposedAction();
}

void Scene::dropEvent(QGraphicsSceneDragDropEvent * event) {
  QList<QUrl> urls = event->mimeData()->urls();
  if (urls.count()) {
    QString filename = urls[0].toLocalFile();
    emit dropedFilename(filename);
    event->acceptProposedAction();
  }
}

bool Scene::eventFilter(QObject* object, QEvent* event) {
  if (event->type() == QEvent::GraphicsSceneWheel) {
    QGraphicsSceneWheelEvent *wheelEvent =
      static_cast<QGraphicsSceneWheelEvent*>(event);
    if (wheelEvent->modifiers().testFlag(Qt::ControlModifier)) {
      int delta = wheelEvent->delta();
      qreal scale = 1.00;
      if (delta > 0) {
        scale = 1.10;
      } else {
        scale = 1/1.10;
      }
      emit sceneScaleChanged(scale);
      wheelEvent->accept();
      return true;
    }
  }

  return false;
}

void Scene::contextMenuEvent(QGraphicsSceneContextMenuEvent * event) {
  event->accept();
  QMenu* menu = new QMenu();
  QAction *ImageInfoAction = menu->addAction(QIcon(":/info.svg"),
                             tr("Image info"));
  connect(ImageInfoAction, SIGNAL(triggered()), this, SLOT(imageInfo()));
  menu->addSeparator();

  QAction* rotateCWAction = menu->addAction(QIcon(":/rotateCW.svg"),
                            tr("Rotate CW"));
  connect(rotateCWAction, SIGNAL(triggered()), this, SLOT(rotateCW()));

  QAction* rotateCCWAction = menu->addAction(QIcon(":/rotateCCW.svg"),
                             tr("Rotate CCW"));
  connect(rotateCCWAction, SIGNAL(triggered()), this, SLOT(rotateCCW()));

  QAction* rotateHalfAction = menu->addAction(QIcon(":/rotateCCW.svg"),
                              tr("Rotate 180"));
  connect(rotateHalfAction, SIGNAL(triggered()), this, SLOT(rotateHalf()));
  menu->exec(event->screenPos());
  menu->deleteLater();
}
