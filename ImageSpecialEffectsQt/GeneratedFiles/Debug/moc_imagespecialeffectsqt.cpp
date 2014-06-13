/****************************************************************************
** Meta object code from reading C++ file 'imagespecialeffectsqt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../../../ÎÄµµ/¹¤³Ì/VC/ImageSpecialEffectsQt/ImageSpecialEffectsQt/imagespecialeffectsqt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imagespecialeffectsqt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ImageSpecialEffectsQt_t {
    QByteArrayData data[11];
    char stringdata[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ImageSpecialEffectsQt_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ImageSpecialEffectsQt_t qt_meta_stringdata_ImageSpecialEffectsQt = {
    {
QT_MOC_LITERAL(0, 0, 21),
QT_MOC_LITERAL(1, 22, 10),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 5),
QT_MOC_LITERAL(4, 40, 9),
QT_MOC_LITERAL(5, 50, 8),
QT_MOC_LITERAL(6, 59, 8),
QT_MOC_LITERAL(7, 68, 4),
QT_MOC_LITERAL(8, 73, 8),
QT_MOC_LITERAL(9, 82, 17),
QT_MOC_LITERAL(10, 100, 19)
    },
    "ImageSpecialEffectsQt\0updateSize\0\0"
    "coeff\0transform\0openFile\0saveFile\0"
    "gray\0undoZoom\0openBalanceDialog\0"
    "openTextImageDialog\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageSpecialEffectsQt[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x0a,
       4,    1,   62,    2, 0x0a,
       4,    0,   65,    2, 0x2a,
       5,    0,   66,    2, 0x0a,
       6,    0,   67,    2, 0x0a,
       7,    0,   68,    2, 0x0a,
       8,    0,   69,    2, 0x0a,
       9,    0,   70,    2, 0x0a,
      10,    0,   71,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ImageSpecialEffectsQt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ImageSpecialEffectsQt *_t = static_cast<ImageSpecialEffectsQt *>(_o);
        switch (_id) {
        case 0: _t->updateSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->transform((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->transform(); break;
        case 3: _t->openFile(); break;
        case 4: _t->saveFile(); break;
        case 5: _t->gray(); break;
        case 6: _t->undoZoom(); break;
        case 7: _t->openBalanceDialog(); break;
        case 8: _t->openTextImageDialog(); break;
        default: ;
        }
    }
}

const QMetaObject ImageSpecialEffectsQt::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ImageSpecialEffectsQt.data,
      qt_meta_data_ImageSpecialEffectsQt,  qt_static_metacall, 0, 0}
};


const QMetaObject *ImageSpecialEffectsQt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageSpecialEffectsQt::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ImageSpecialEffectsQt.stringdata))
        return static_cast<void*>(const_cast< ImageSpecialEffectsQt*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ImageSpecialEffectsQt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
