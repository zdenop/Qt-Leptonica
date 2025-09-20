/****************************************************************************
** Meta object code from reading C++ file 'scene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/scene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Scene_t {
    QByteArrayData data[17];
    char stringdata0[202];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Scene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Scene_t qt_meta_stringdata_Scene = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Scene"
QT_MOC_LITERAL(1, 6, 14), // "dropedFilename"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 8), // "filename"
QT_MOC_LITERAL(4, 31, 17), // "sceneScaleChanged"
QT_MOC_LITERAL(5, 49, 5), // "scale"
QT_MOC_LITERAL(6, 55, 18), // "imageInfoTriggered"
QT_MOC_LITERAL(7, 74, 11), // "rotateImage"
QT_MOC_LITERAL(8, 86, 23), // "detectOrientationSignal"
QT_MOC_LITERAL(9, 110, 18), // "imageCropTriggered"
QT_MOC_LITERAL(10, 129, 4), // "rect"
QT_MOC_LITERAL(11, 134, 9), // "imageCrop"
QT_MOC_LITERAL(12, 144, 9), // "imageInfo"
QT_MOC_LITERAL(13, 154, 8), // "rotateCW"
QT_MOC_LITERAL(14, 163, 9), // "rotateCCW"
QT_MOC_LITERAL(15, 173, 10), // "rotateHalf"
QT_MOC_LITERAL(16, 184, 17) // "detectOrientation"

    },
    "Scene\0dropedFilename\0\0filename\0"
    "sceneScaleChanged\0scale\0imageInfoTriggered\0"
    "rotateImage\0detectOrientationSignal\0"
    "imageCropTriggered\0rect\0imageCrop\0"
    "imageInfo\0rotateCW\0rotateCCW\0rotateHalf\0"
    "detectOrientation"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Scene[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       4,    1,   77,    2, 0x06 /* Public */,
       6,    0,   80,    2, 0x06 /* Public */,
       7,    1,   81,    2, 0x06 /* Public */,
       8,    0,   84,    2, 0x06 /* Public */,
       9,    1,   85,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   88,    2, 0x08 /* Private */,
      12,    0,   89,    2, 0x08 /* Private */,
      13,    0,   90,    2, 0x08 /* Private */,
      14,    0,   91,    2, 0x08 /* Private */,
      15,    0,   92,    2, 0x08 /* Private */,
      16,    0,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QReal,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QRectF,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Scene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Scene *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->dropedFilename((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->sceneScaleChanged((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 2: _t->imageInfoTriggered(); break;
        case 3: _t->rotateImage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->detectOrientationSignal(); break;
        case 5: _t->imageCropTriggered((*reinterpret_cast< const QRectF(*)>(_a[1]))); break;
        case 6: _t->imageCrop(); break;
        case 7: _t->imageInfo(); break;
        case 8: _t->rotateCW(); break;
        case 9: _t->rotateCCW(); break;
        case 10: _t->rotateHalf(); break;
        case 11: _t->detectOrientation(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Scene::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Scene::dropedFilename)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Scene::*)(qreal );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Scene::sceneScaleChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Scene::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Scene::imageInfoTriggered)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Scene::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Scene::rotateImage)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Scene::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Scene::detectOrientationSignal)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Scene::*)(const QRectF & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Scene::imageCropTriggered)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Scene::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsScene::staticMetaObject>(),
    qt_meta_stringdata_Scene.data,
    qt_meta_data_Scene,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Scene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Scene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Scene.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsScene::qt_metacast(_clname);
}

int Scene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void Scene::dropedFilename(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Scene::sceneScaleChanged(qreal _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Scene::imageInfoTriggered()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Scene::rotateImage(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Scene::detectOrientationSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Scene::imageCropTriggered(const QRectF & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
