#include "scene.h"

#include <QAction>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QMenu>
#include <QMimeData>
#include <QUrl>
#include <QWidget>

Scene::Scene() : m_rubberBand(nullptr), m_image(nullptr), m_init(false) {
    setBackgroundBrush(Qt::gray);
    installEventFilter(this);
}

Scene::~Scene() = default;

void Scene::setImage(const QPixmap& pixmap) {
    m_image = addPixmap(pixmap);
}

void Scene::removeRubberBand() {
    if (m_rubberBand) {
        removeItem(m_rubberBand);
        m_rubberBand = nullptr;
    }
}

void Scene::removeImage() {
    removeRubberBand();
    if (m_image) {
        removeItem(m_image);
        m_image = nullptr;
    }
}

void Scene::imageCrop() {
    emit imageCropTriggered(m_rubberBand->areaRect());
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

void Scene::detectOrientation() {
    emit detectOrientationSignal();
}

void Scene::dragEnterEvent(QGraphicsSceneDragDropEvent* event) {
    event->acceptProposedAction();
}

void Scene::dragLeaveEvent(QGraphicsSceneDragDropEvent* event) {
    event->acceptProposedAction();
}

void Scene::dragMoveEvent(QGraphicsSceneDragDropEvent* event) {
    event->acceptProposedAction();
}

void Scene::dropEvent(QGraphicsSceneDragDropEvent* event) {
    const auto& urls = event->mimeData()->urls();
    if (!urls.isEmpty()) {
        emit dropedFilename(urls.first().toLocalFile());
        event->acceptProposedAction();
    }
}

bool Scene::eventFilter(QObject* object, QEvent* event) {
    if (event->type() == QEvent::GraphicsSceneWheel) {
        auto* wheelEvent = static_cast<QGraphicsSceneWheelEvent*>(event);
        if (wheelEvent->modifiers().testFlag(Qt::ControlModifier)) {
            const qreal scale = wheelEvent->delta() > 0 ? 1.10 : 1 / 1.10;
            emit sceneScaleChanged(scale);
            wheelEvent->accept();
            return true;
        }
    }
    return false;
}

void Scene::contextMenuEvent(QGraphicsSceneContextMenuEvent* event) {
    event->accept();
    auto menu = std::make_unique<QMenu>();

    if (m_rubberBand) {
        auto* imageCropAction = menu->addAction(QIcon(":/crop.svg"), tr("Crop area"));
        connect(imageCropAction, &QAction::triggered, this, &Scene::imageCrop);
    } else {
        auto* imageInfoAction = menu->addAction(QIcon(":/info.svg"), tr("Image info"));
        connect(imageInfoAction, &QAction::triggered, this, &Scene::imageInfo);
        menu->addSeparator();

        auto* rotateCWAction = menu->addAction(QIcon(":/rotateCW.svg"), tr("Rotate 90° CW"));
        connect(rotateCWAction, &QAction::triggered, this, &Scene::rotateCW);

        auto* rotateCCWAction = menu->addAction(QIcon(":/rotateCCW.svg"), tr("Rotate 90° CCW"));
        connect(rotateCCWAction, &QAction::triggered, this, &Scene::rotateCCW);

        auto* rotateHalfAction = menu->addAction(QIcon(":/rotate_180"), tr("Rotate 180°"));
        connect(rotateHalfAction, &QAction::triggered, this, &Scene::rotateHalf);

        auto* detectOrientationAction = menu->addAction(QIcon(":/orientation.svg"), tr("Detect orientation"));
        detectOrientationAction->setToolTip(tr("Page orientation detection (four 90 degree angles)"));
        connect(detectOrientationAction, &QAction::triggered, this, &Scene::detectOrientation);
    }

    menu->exec(event->screenPos());
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent* event) {
    if (event->modifiers() == Qt::ControlModifier && event->button() == Qt::LeftButton) {
        origPoint = event->scenePos();
    }
    QGraphicsScene::mousePressEvent(event);
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent* event) {
    if (!m_rubberBand && m_image && event->modifiers() == Qt::ControlModifier) {
        m_rubberBand = new AreaItem(m_image);
        m_rubberBand->setAreaRect(QRectF(origPoint, event->scenePos()));
        addItem(m_rubberBand);
        m_init = true;
    }
    if (m_init) {
        m_rubberBand->setAreaRect(QRectF(origPoint, event->scenePos()));
    }
    QGraphicsScene::mouseMoveEvent(event);
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent* event) {
    m_init = false;
    QGraphicsScene::mouseReleaseEvent(event);
}

void Scene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) {
    event->setAccepted(false);
    removeRubberBand();
    if (!event->isAccepted()) QGraphicsScene::mouseDoubleClickEvent(event);
}

void Scene::keyPressEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_Delete) {
        for (auto* item : selectedItems()) {
            removeItem(item);
            delete item;
        }
    } else {
        QGraphicsScene::keyPressEvent(event);
    }
}
