#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>

class Scene: public QGraphicsScene {
    Q_OBJECT

 public:
  Scene();

 signals:
  void dropedFilename(QString filename);
  void sceneScaleChanged(qreal scale);

 protected:
  virtual void dragEnterEvent(QGraphicsSceneDragDropEvent * event);
  virtual void dragLeaveEvent(QGraphicsSceneDragDropEvent * event);
  virtual void dragMoveEvent(QGraphicsSceneDragDropEvent * event);
  virtual void dropEvent(QGraphicsSceneDragDropEvent * event);

  virtual bool eventFilter(QObject* object, QEvent* event);
};

#endif // SCENE_H

