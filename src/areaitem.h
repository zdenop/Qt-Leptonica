/*
 * Copyright (C) 2010 Matteo Bertozzi, Zdenko Podobný (C) 2017
 * based on http://th30z.blogspot.sk/2010/01/qt4-image-crop-item_1065.html
 */

#ifndef AREAITEM_H
#define AREAITEM_H

#include <QtWidgets>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QApplication>
#include <QPainter>

#define AREA_BORDER_LINE        10
#define AREA_GRID_SIZE           3

class AreaItem : public QGraphicsItem {
  public:
    explicit AreaItem(QGraphicsItem *parent);
    ~AreaItem();
    QRectF areaRect (void) const;
    void setAreaRect(QRectF rectf);
    QRectF boundingRect (void) const ;
    virtual void paint (QPainter *painter,
                        const QStyleOptionGraphicsItem *option,
                        QWidget *widget = 0);

  protected:
    void mousePressEvent (QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent (QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent (QGraphicsSceneMouseEvent *event);

  private:
    enum AreaItemResize {
        AreaItemResizeNone,
        AreaItemResizeTopLeft,
        AreaItemResizeTopRight,
        AreaItemResizeBottomLeft,
        AreaItemResizeBottomRight,
    };

  private:
    AreaItemResize _areaResize;
    QRectF _areaRect;
    bool _mousePress;
};

#endif // AREAITEM_H
