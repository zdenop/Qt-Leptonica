#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>

class Scene: public QGraphicsScene {
    Q_OBJECT

 public:
  Scene();

 signals:
  void dropedFilename(QString filename);

 protected:
  virtual void dragEnterEvent(QGraphicsSceneDragDropEvent * event);
  virtual void dragLeaveEvent(QGraphicsSceneDragDropEvent * event);
  virtual void dragMoveEvent(QGraphicsSceneDragDropEvent * event);
  virtual void dropEvent(QGraphicsSceneDragDropEvent * event);
};

#endif // SCENE_H

