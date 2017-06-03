#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include "areaitem.h"

class Scene: public QGraphicsScene {
    Q_OBJECT

  public:
    Scene();
    ~Scene();
    void setImage(QPixmap pixmap);
    void removeImage();
    QGraphicsItem *m_image;

  signals:
    void dropedFilename(QString filename);
    void sceneScaleChanged(qreal scale);
    void imageInfoTriggered();
    void rotateImage(int);
    void detectOrientationSignal();
    void imageCropTriggered(QRectF rect);

  protected:
    AreaItem *m_rubberBand;
    virtual void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
    virtual void dragLeaveEvent(QGraphicsSceneDragDropEvent *event);
    virtual void dragMoveEvent(QGraphicsSceneDragDropEvent *event);
    virtual void dropEvent(QGraphicsSceneDragDropEvent *event);
    virtual void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);

    virtual bool eventFilter(QObject* object, QEvent* event);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);

  private:
    QPointF origPoint;
    QGraphicsLineItem* itemToDraw;
    bool m_init;
    void removeRubberBand();

  private slots:
    void imageCrop();
    void imageInfo();
    void rotateCW();
    void rotateCCW();
    void rotateHalf();
    void detectOrientation();
};

#endif // SCENE_H

