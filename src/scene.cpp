#include "scene.h"

#include <QGraphicsSceneMouseEvent>
#include <QMimeData>
#include <QUrl>

Scene::Scene() {
  setBackgroundBrush(Qt::gray);
  this->installEventFilter(this);
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
