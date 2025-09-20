/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.13)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.13. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[55];
    char stringdata0[1043];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 11), // "PixToQImage"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 4), // "PIX*"
QT_MOC_LITERAL(4, 29, 4), // "pixs"
QT_MOC_LITERAL(5, 34, 11), // "QImageToPIX"
QT_MOC_LITERAL(6, 46, 6), // "qImage"
QT_MOC_LITERAL(7, 53, 27), // "on_actionOpenFile_triggered"
QT_MOC_LITERAL(8, 81, 29), // "on_actionReloadFile_triggered"
QT_MOC_LITERAL(9, 111, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(10, 135, 25), // "on_actionSaveAs_triggered"
QT_MOC_LITERAL(11, 161, 35), // "on_actionZoom_to_original_tri..."
QT_MOC_LITERAL(12, 197, 26), // "on_actionZoom_in_triggered"
QT_MOC_LITERAL(13, 224, 27), // "on_actionZoom_out_triggered"
QT_MOC_LITERAL(14, 252, 32), // "on_actionFit_to_window_triggered"
QT_MOC_LITERAL(15, 285, 32), // "on_actionFit_to_height_triggered"
QT_MOC_LITERAL(16, 318, 31), // "on_actionFit_to_width_triggered"
QT_MOC_LITERAL(17, 350, 16), // "changeSceneScale"
QT_MOC_LITERAL(18, 367, 5), // "scale"
QT_MOC_LITERAL(19, 373, 6), // "rotate"
QT_MOC_LITERAL(20, 380, 5), // "quads"
QT_MOC_LITERAL(21, 386, 4), // "crop"
QT_MOC_LITERAL(22, 391, 4), // "rect"
QT_MOC_LITERAL(23, 396, 27), // "on_actionRotateCW_triggered"
QT_MOC_LITERAL(24, 424, 28), // "on_actionRotateCCW_triggered"
QT_MOC_LITERAL(25, 453, 28), // "on_actionRotate180_triggered"
QT_MOC_LITERAL(26, 482, 36), // "on_actionDetectOrientation_tr..."
QT_MOC_LITERAL(27, 519, 23), // "on_actionCopy_triggered"
QT_MOC_LITERAL(28, 543, 24), // "on_actionPaste_triggered"
QT_MOC_LITERAL(29, 568, 36), // "on_actionChange_resolution_tr..."
QT_MOC_LITERAL(30, 605, 28), // "on_actionSetFormat_triggered"
QT_MOC_LITERAL(31, 634, 31), // "on_actionBinarizeUnIl_triggered"
QT_MOC_LITERAL(32, 666, 25), // "on_actionDewarp_triggered"
QT_MOC_LITERAL(33, 692, 25), // "on_actionDeskew_triggered"
QT_MOC_LITERAL(34, 718, 38), // "on_actionCleanDarkBackground_..."
QT_MOC_LITERAL(35, 757, 23), // "slotCleanDarkBackground"
QT_MOC_LITERAL(36, 781, 8), // "blackval"
QT_MOC_LITERAL(37, 790, 8), // "whiteval"
QT_MOC_LITERAL(38, 799, 6), // "thresh"
QT_MOC_LITERAL(39, 806, 26), // "previewCleanDarkBackground"
QT_MOC_LITERAL(40, 833, 22), // "tmpCleanDarkBackground"
QT_MOC_LITERAL(41, 856, 30), // "on_actionRemovelines_triggered"
QT_MOC_LITERAL(42, 887, 29), // "on_actionConvert2GS_triggered"
QT_MOC_LITERAL(43, 917, 8), // "pix_undo"
QT_MOC_LITERAL(44, 926, 8), // "pix_redo"
QT_MOC_LITERAL(45, 935, 12), // "storeUndoPIX"
QT_MOC_LITERAL(46, 948, 6), // "newPix"
QT_MOC_LITERAL(47, 955, 9), // "imageInfo"
QT_MOC_LITERAL(48, 965, 14), // "openRecentFile"
QT_MOC_LITERAL(49, 980, 9), // "openImage"
QT_MOC_LITERAL(50, 990, 13), // "imageFileName"
QT_MOC_LITERAL(51, 1004, 15), // "slotfileChanged"
QT_MOC_LITERAL(52, 1020, 8), // "fileName"
QT_MOC_LITERAL(53, 1029, 5), // "about"
QT_MOC_LITERAL(54, 1035, 7) // "aboutQt"

    },
    "MainWindow\0PixToQImage\0\0PIX*\0pixs\0"
    "QImageToPIX\0qImage\0on_actionOpenFile_triggered\0"
    "on_actionReloadFile_triggered\0"
    "on_actionSave_triggered\0"
    "on_actionSaveAs_triggered\0"
    "on_actionZoom_to_original_triggered\0"
    "on_actionZoom_in_triggered\0"
    "on_actionZoom_out_triggered\0"
    "on_actionFit_to_window_triggered\0"
    "on_actionFit_to_height_triggered\0"
    "on_actionFit_to_width_triggered\0"
    "changeSceneScale\0scale\0rotate\0quads\0"
    "crop\0rect\0on_actionRotateCW_triggered\0"
    "on_actionRotateCCW_triggered\0"
    "on_actionRotate180_triggered\0"
    "on_actionDetectOrientation_triggered\0"
    "on_actionCopy_triggered\0"
    "on_actionPaste_triggered\0"
    "on_actionChange_resolution_triggered\0"
    "on_actionSetFormat_triggered\0"
    "on_actionBinarizeUnIl_triggered\0"
    "on_actionDewarp_triggered\0"
    "on_actionDeskew_triggered\0"
    "on_actionCleanDarkBackground_triggered\0"
    "slotCleanDarkBackground\0blackval\0"
    "whiteval\0thresh\0previewCleanDarkBackground\0"
    "tmpCleanDarkBackground\0"
    "on_actionRemovelines_triggered\0"
    "on_actionConvert2GS_triggered\0pix_undo\0"
    "pix_redo\0storeUndoPIX\0newPix\0imageInfo\0"
    "openRecentFile\0openImage\0imageFileName\0"
    "slotfileChanged\0fileName\0about\0aboutQt"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      41,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  219,    2, 0x0a /* Public */,
       5,    1,  222,    2, 0x0a /* Public */,
       7,    0,  225,    2, 0x08 /* Private */,
       8,    0,  226,    2, 0x08 /* Private */,
       9,    0,  227,    2, 0x08 /* Private */,
      10,    0,  228,    2, 0x08 /* Private */,
      11,    0,  229,    2, 0x08 /* Private */,
      12,    0,  230,    2, 0x08 /* Private */,
      13,    0,  231,    2, 0x08 /* Private */,
      14,    0,  232,    2, 0x08 /* Private */,
      15,    0,  233,    2, 0x08 /* Private */,
      16,    0,  234,    2, 0x08 /* Private */,
      17,    1,  235,    2, 0x08 /* Private */,
      19,    1,  238,    2, 0x08 /* Private */,
      21,    1,  241,    2, 0x08 /* Private */,
      23,    0,  244,    2, 0x08 /* Private */,
      24,    0,  245,    2, 0x08 /* Private */,
      25,    0,  246,    2, 0x08 /* Private */,
      26,    0,  247,    2, 0x08 /* Private */,
      27,    0,  248,    2, 0x08 /* Private */,
      28,    0,  249,    2, 0x08 /* Private */,
      29,    0,  250,    2, 0x08 /* Private */,
      30,    0,  251,    2, 0x08 /* Private */,
      31,    0,  252,    2, 0x08 /* Private */,
      32,    0,  253,    2, 0x08 /* Private */,
      33,    0,  254,    2, 0x08 /* Private */,
      34,    0,  255,    2, 0x08 /* Private */,
      35,    3,  256,    2, 0x08 /* Private */,
      39,    2,  263,    2, 0x08 /* Private */,
      40,    1,  268,    2, 0x08 /* Private */,
      41,    0,  271,    2, 0x08 /* Private */,
      42,    0,  272,    2, 0x08 /* Private */,
      43,    0,  273,    2, 0x08 /* Private */,
      44,    0,  274,    2, 0x08 /* Private */,
      45,    1,  275,    2, 0x08 /* Private */,
      47,    0,  278,    2, 0x08 /* Private */,
      48,    0,  279,    2, 0x08 /* Private */,
      49,    1,  280,    2, 0x08 /* Private */,
      51,    1,  283,    2, 0x08 /* Private */,
      53,    0,  286,    2, 0x08 /* Private */,
      54,    0,  287,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::QImage, 0x80000000 | 3,    4,
    0x80000000 | 3, QMetaType::QImage,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QReal,   18,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::QRectF,   22,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int,   36,   37,   38,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   36,   37,
    QMetaType::Void, QMetaType::Int,   38,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,   46,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   50,
    QMetaType::Void, QMetaType::QString,   52,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: { QImage _r = _t->PixToQImage((*reinterpret_cast< PIX*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QImage*>(_a[0]) = std::move(_r); }  break;
        case 1: { PIX* _r = _t->QImageToPIX((*reinterpret_cast< const QImage(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< PIX**>(_a[0]) = std::move(_r); }  break;
        case 2: _t->on_actionOpenFile_triggered(); break;
        case 3: _t->on_actionReloadFile_triggered(); break;
        case 4: _t->on_actionSave_triggered(); break;
        case 5: _t->on_actionSaveAs_triggered(); break;
        case 6: _t->on_actionZoom_to_original_triggered(); break;
        case 7: _t->on_actionZoom_in_triggered(); break;
        case 8: _t->on_actionZoom_out_triggered(); break;
        case 9: _t->on_actionFit_to_window_triggered(); break;
        case 10: _t->on_actionFit_to_height_triggered(); break;
        case 11: _t->on_actionFit_to_width_triggered(); break;
        case 12: _t->changeSceneScale((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 13: _t->rotate((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->crop((*reinterpret_cast< QRectF(*)>(_a[1]))); break;
        case 15: _t->on_actionRotateCW_triggered(); break;
        case 16: _t->on_actionRotateCCW_triggered(); break;
        case 17: _t->on_actionRotate180_triggered(); break;
        case 18: _t->on_actionDetectOrientation_triggered(); break;
        case 19: _t->on_actionCopy_triggered(); break;
        case 20: _t->on_actionPaste_triggered(); break;
        case 21: _t->on_actionChange_resolution_triggered(); break;
        case 22: _t->on_actionSetFormat_triggered(); break;
        case 23: _t->on_actionBinarizeUnIl_triggered(); break;
        case 24: _t->on_actionDewarp_triggered(); break;
        case 25: _t->on_actionDeskew_triggered(); break;
        case 26: _t->on_actionCleanDarkBackground_triggered(); break;
        case 27: _t->slotCleanDarkBackground((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 28: _t->previewCleanDarkBackground((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 29: _t->tmpCleanDarkBackground((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->on_actionRemovelines_triggered(); break;
        case 31: _t->on_actionConvert2GS_triggered(); break;
        case 32: _t->pix_undo(); break;
        case 33: _t->pix_redo(); break;
        case 34: _t->storeUndoPIX((*reinterpret_cast< PIX*(*)>(_a[1]))); break;
        case 35: _t->imageInfo(); break;
        case 36: _t->openRecentFile(); break;
        case 37: _t->openImage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 38: _t->slotfileChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 39: _t->about(); break;
        case 40: _t->aboutQt(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::MainWindow"))
        return static_cast< Ui::MainWindow*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 41)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 41;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 41)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 41;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
