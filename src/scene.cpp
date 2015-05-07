#include "scene.h"

#include <QGraphicsSceneMouseEvent>
#include <QMimeData>
#include <QUrl>
#include <QtDebug>

Scene::Scene() {
  setBackgroundBrush(Qt::gray);
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
    qDebug() << "scene drop "  << filename;
    event->acceptProposedAction();
  }
}
