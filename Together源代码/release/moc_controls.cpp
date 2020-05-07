/****************************************************************************
** Meta object code from reading C++ file 'controls.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../controls.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controls.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Controls_t {
    QByteArrayData data[14];
    char stringdata0[240];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Controls_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Controls_t qt_meta_stringdata_Controls = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Controls"
QT_MOC_LITERAL(1, 9, 22), // "uploadBtnClickedSignal"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 20), // "openBtnClickedSignal"
QT_MOC_LITERAL(4, 54, 23), // "receiveBtnClickedSignal"
QT_MOC_LITERAL(5, 78, 20), // "playBtnClickedSignal"
QT_MOC_LITERAL(6, 99, 20), // "stopBtnClickedSignal"
QT_MOC_LITERAL(7, 120, 22), // "volumeBtnClickedSignal"
QT_MOC_LITERAL(8, 143, 16), // "uploadBtnClicked"
QT_MOC_LITERAL(9, 160, 14), // "openBtnClicked"
QT_MOC_LITERAL(10, 175, 17), // "receiveBtnClicked"
QT_MOC_LITERAL(11, 193, 14), // "playBtnClicked"
QT_MOC_LITERAL(12, 208, 14), // "stopBtnClicked"
QT_MOC_LITERAL(13, 223, 16) // "volumeBtnClicked"

    },
    "Controls\0uploadBtnClickedSignal\0\0"
    "openBtnClickedSignal\0receiveBtnClickedSignal\0"
    "playBtnClickedSignal\0stopBtnClickedSignal\0"
    "volumeBtnClickedSignal\0uploadBtnClicked\0"
    "openBtnClicked\0receiveBtnClicked\0"
    "playBtnClicked\0stopBtnClicked\0"
    "volumeBtnClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Controls[] = {

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
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,
       4,    0,   76,    2, 0x06 /* Public */,
       5,    0,   77,    2, 0x06 /* Public */,
       6,    0,   78,    2, 0x06 /* Public */,
       7,    0,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   80,    2, 0x0a /* Public */,
       9,    0,   81,    2, 0x0a /* Public */,
      10,    0,   82,    2, 0x0a /* Public */,
      11,    0,   83,    2, 0x0a /* Public */,
      12,    0,   84,    2, 0x0a /* Public */,
      13,    0,   85,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Controls::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Controls *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->uploadBtnClickedSignal(); break;
        case 1: _t->openBtnClickedSignal(); break;
        case 2: _t->receiveBtnClickedSignal(); break;
        case 3: _t->playBtnClickedSignal(); break;
        case 4: _t->stopBtnClickedSignal(); break;
        case 5: _t->volumeBtnClickedSignal(); break;
        case 6: _t->uploadBtnClicked(); break;
        case 7: _t->openBtnClicked(); break;
        case 8: _t->receiveBtnClicked(); break;
        case 9: _t->playBtnClicked(); break;
        case 10: _t->stopBtnClicked(); break;
        case 11: _t->volumeBtnClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Controls::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controls::uploadBtnClickedSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Controls::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controls::openBtnClickedSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Controls::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controls::receiveBtnClickedSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Controls::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controls::playBtnClickedSignal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Controls::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controls::stopBtnClickedSignal)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Controls::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controls::volumeBtnClickedSignal)) {
                *result = 5;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Controls::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Controls.data,
    qt_meta_data_Controls,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Controls::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controls::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Controls.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Controls::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void Controls::uploadBtnClickedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Controls::openBtnClickedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Controls::receiveBtnClickedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Controls::playBtnClickedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Controls::stopBtnClickedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Controls::volumeBtnClickedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
