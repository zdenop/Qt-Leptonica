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
  void imageInfoTriggered();
  void rotateImage(int);
  void detectOrientationSignal();

 protected:
  virtual void dragEnterEvent(QGraphicsSceneDragDropEvent * event);
  virtual void dragLeaveEvent(QGraphicsSceneDragDropEvent * event);
  virtual void dragMoveEvent(QGraphicsSceneDragDropEvent * event);
  virtual void dropEvent(QGraphicsSceneDragDropEvent * event);
  virtual void contextMenuEvent(QGraphicsSceneContextMenuEvent * event);

  virtual bool eventFilter(QObject* object, QEvent* event);

 private slots:
  void imageInfo();
  void rotateCW();
  void rotateCCW();
  void rotateHalf();
  void detectOrientation();

};

#endif // SCENE_H

