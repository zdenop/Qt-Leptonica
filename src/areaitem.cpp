#include "areaitem.h"

AreaItem::AreaItem(QGraphicsItem *parent)
    : QGraphicsItem(parent)
{
    _mousePress = false;
    _areaRect = QRectF();
    grabMouse();
}

AreaItem::~AreaItem()
{
}

void AreaItem::setAreaRect(QRectF rectF){
    _areaRect = QRectF(rectF);
}

QRectF AreaItem::areaRect (void) const {
    return(_areaRect);
}

QRectF AreaItem::boundingRect (void) const {
    return(parentItem()->boundingRect());
}

void AreaItem::paint (QPainter *painter,
                                const QStyleOptionGraphicsItem *option,
                                QWidget *widget)
{
    Q_UNUSED(widget)

    painter->save();

    QPainterPath areaPath;
    areaPath.addRect(_areaRect);

    QPainterPath windowPath;
    windowPath.addRect(option->rect);
    windowPath -= areaPath;

    // Draw Alpha-Black Background.
    painter->fillPath(windowPath, QColor(0x33, 0x33, 0x33, 0xcc));

    // Draw Area Rect
    painter->setPen(QPen(QColor(0xff, 0x00, 0x00), 1));
    painter->drawPath(areaPath);

    int topRightX = _areaRect.x() + _areaRect.width();
    int bottomY = _areaRect.y() + _areaRect.height();

    // Draw Grid if mouse is Pressed
    if (_mousePress) {
        qreal f = 1.0f / AREA_GRID_SIZE;
        qreal hsize = _areaRect.height() * f;
        qreal wsize = _areaRect.width() * f;

        QPainterPath gridPath;
        for (uint i = 1; i < AREA_GRID_SIZE; ++i) {
            qreal y = _areaRect.y() + i * hsize;
            gridPath.moveTo(_areaRect.x(), y);
            gridPath.lineTo(topRightX, y);

            for (uint j = 1; j < AREA_GRID_SIZE; ++j) {
                qreal x = _areaRect.x() + j * wsize;
                gridPath.moveTo(x, _areaRect.y());
                gridPath.lineTo(x, bottomY);
            }
        }

        // Draw Grid Path
        painter->setPen(QPen(QColor(0x99, 0x99, 0x99, 0x80), 1));
        painter->drawPath(gridPath);
    }

    QPainterPath borderPath;
    // Top-Left Corner
    borderPath.moveTo(_areaRect.x(), _areaRect.y());
    borderPath.lineTo(_areaRect.x() + AREA_BORDER_LINE, _areaRect.y());
    borderPath.moveTo(_areaRect.x(), _areaRect.y());
    borderPath.lineTo(_areaRect.x(), _areaRect.y() + AREA_BORDER_LINE);

    // Top-Right Corner
    borderPath.moveTo(topRightX - AREA_BORDER_LINE, _areaRect.y());
    borderPath.lineTo(topRightX, _areaRect.y());
    borderPath.moveTo(topRightX, _areaRect.y());
    borderPath.lineTo(topRightX, _areaRect.y() + AREA_BORDER_LINE);

    // Bottom-Left Corner
    borderPath.moveTo(_areaRect.x(), bottomY);
    borderPath.lineTo(_areaRect.x() + AREA_BORDER_LINE, bottomY);
    borderPath.moveTo(_areaRect.x(), bottomY - AREA_BORDER_LINE);
    borderPath.lineTo(_areaRect.x(), bottomY);

    // Bottom-Left Corner
    borderPath.moveTo(topRightX, bottomY);
    borderPath.lineTo(topRightX - AREA_BORDER_LINE, bottomY);
    borderPath.moveTo(topRightX, bottomY - AREA_BORDER_LINE);
    borderPath.lineTo(topRightX, bottomY);

    // Draw Border Path
    painter->setPen(QPen(QColor(0x00, 0x00, 0xee), 3));
    painter->drawPath(borderPath);

    painter->restore();
}

void AreaItem::mousePressEvent (QGraphicsSceneMouseEvent *event) {
    QGraphicsItem::mousePressEvent(event);

    _mousePress = true;
    _areaResize = AreaItemResizeNone;
    if (event->buttons() & Qt::LeftButton) {
        int lthreshold = (AREA_BORDER_LINE >> 1);
        int rthreshold = AREA_BORDER_LINE;
        int size = AREA_BORDER_LINE << 1;

        int rightX = _areaRect.x() + _areaRect.width() - rthreshold;
        int leftX = _areaRect.x() - lthreshold;

        int bottomY = _areaRect.y() + _areaRect.height() - rthreshold;
        int topY = _areaRect.y() - lthreshold;

        QRectF bottomRightCorner(rightX, bottomY, size, size);
        QRectF bottomLeftCorner(leftX, bottomY, size, size);
        QRectF topRightCorner(rightX, topY, size, size);
        QRectF topLeftCorner(leftX, topY, size, size);

        if (bottomRightCorner.contains(event->pos()))
            _areaResize = AreaItemResizeBottomRight;
        else if (bottomLeftCorner.contains(event->pos()))
            _areaResize = AreaItemResizeBottomLeft;
        else if (topRightCorner.contains(event->pos()))
            _areaResize = AreaItemResizeTopRight;
        else if (topLeftCorner.contains(event->pos()))
            _areaResize = AreaItemResizeTopLeft;
    }

    update();
}

void AreaItem::mouseReleaseEvent (QGraphicsSceneMouseEvent *event) {
    QGraphicsItem::mouseReleaseEvent(event);

    _areaResize = AreaItemResizeNone;
    _mousePress = false;

    update();
}

void AreaItem::mouseMoveEvent (QGraphicsSceneMouseEvent *event) {
    QGraphicsItem::mouseMoveEvent(event);

    qreal minSize = 4 + (AREA_BORDER_LINE << 1);

    QPointF delta = event->pos() - event->lastPos();
    switch (_areaResize) {
    case AreaItemResizeNone:
        if (!_areaRect.contains(event->pos()))
            return;

        if (!(event->buttons() & Qt::LeftButton))
            return;

        _areaRect.translate(delta);
        break;
    case AreaItemResizeTopLeft:
        delta.setY(qMin(_areaRect.height() - minSize, delta.y()));
        delta.setX(qMin(_areaRect.width() - minSize, delta.x()));
        _areaRect.setHeight(_areaRect.height() - delta.y());
        _areaRect.setWidth(_areaRect.width() - delta.x());
        _areaRect.translate(delta);
        break;
    case AreaItemResizeTopRight:
        delta.setY(qMin(_areaRect.height() - minSize, delta.y()));
        _areaRect.setWidth(_areaRect.width() + delta.x());
        _areaRect.setHeight(_areaRect.height() - delta.y());
        _areaRect.translate(0, delta.y());
        break;
    case AreaItemResizeBottomLeft:
        delta.setX(qMin(_areaRect.width() - minSize, delta.x()));
        _areaRect.setHeight(_areaRect.height() + delta.y());
        _areaRect.setWidth(_areaRect.width() - delta.x());
        _areaRect.translate(delta.x(), 0);
        break;
    case AreaItemResizeBottomRight:
        _areaRect.setWidth(_areaRect.width() + delta.x());
        _areaRect.setHeight(_areaRect.height() + delta.y());
        break;
    }

    if (_areaRect.width() < minSize) _areaRect.setWidth(minSize);
    if (_areaRect.height() < minSize) _areaRect.setHeight(minSize);

    update();
}
