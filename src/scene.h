#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include "areaitem.h"

class Scene : public QGraphicsScene {
    Q_OBJECT

public:
    Scene();
    ~Scene() override;

    void setImage(const QPixmap& pixmap);
    void removeImage();

    QGraphicsItem* m_image = nullptr;

signals:
    void dropedFilename(const QString& filename);
    void sceneScaleChanged(qreal scale);
    void imageInfoTriggered();
    void rotateImage(int);
    void detectOrientationSignal();
    void imageCropTriggered(const QRectF& rect);

protected:
    void dragEnterEvent(QGraphicsSceneDragDropEvent* event) override;
    void dragLeaveEvent(QGraphicsSceneDragDropEvent* event) override;
    void dragMoveEvent(QGraphicsSceneDragDropEvent* event) override;
    void dropEvent(QGraphicsSceneDragDropEvent* event) override;
    void contextMenuEvent(QGraphicsSceneContextMenuEvent* event) override;
    bool eventFilter(QObject* object, QEvent* event) override;
    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;

private:
    QPointF origPoint;
    AreaItem* m_rubberBand = nullptr;
    bool m_init = false;

    void removeRubberBand();

private slots:
    void imageCrop();
    void imageInfo();
    void rotateCW();
    void rotateCCW();
    void rotateHalf();
    void detectOrientation();
};

#endif  // SCENE_H
