/****************************************************************************
** Meta object code from reading C++ file 'chatroom.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../chatroom.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'chatroom.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChatRoom_t {
    QByteArrayData data[19];
    char stringdata0[397];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChatRoom_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChatRoom_t qt_meta_stringdata_ChatRoom = {
    {
QT_MOC_LITERAL(0, 0, 8), // "ChatRoom"
QT_MOC_LITERAL(1, 9, 27), // "processPendingDatagramsSlot"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 15), // "getFileNameSlot"
QT_MOC_LITERAL(4, 54, 34), // "fontComboBoxCurrentFontChange..."
QT_MOC_LITERAL(5, 89, 1), // "f"
QT_MOC_LITERAL(6, 91, 35), // "sizeComboBoxCurrentIndexChang..."
QT_MOC_LITERAL(7, 127, 21), // "sendButtonClickedSlot"
QT_MOC_LITERAL(8, 149, 22), // "sendToolBtnClickedSlot"
QT_MOC_LITERAL(9, 172, 22), // "boldToolBtnClickedSlot"
QT_MOC_LITERAL(10, 195, 24), // "italicToolBtnClickedSlot"
QT_MOC_LITERAL(11, 220, 27), // "underlineToolBtnClickedSlot"
QT_MOC_LITERAL(12, 248, 23), // "colorToolBtnClickedSlot"
QT_MOC_LITERAL(13, 272, 22), // "saveToolBtnClickedSlot"
QT_MOC_LITERAL(14, 295, 23), // "clearToolBtnClickedSlot"
QT_MOC_LITERAL(15, 319, 24), // "currentFormatChangedSlot"
QT_MOC_LITERAL(16, 344, 15), // "QTextCharFormat"
QT_MOC_LITERAL(17, 360, 6), // "format"
QT_MOC_LITERAL(18, 367, 29) // "opacitySliderValueChangedSlot"

    },
    "ChatRoom\0processPendingDatagramsSlot\0"
    "\0getFileNameSlot\0fontComboBoxCurrentFontChangedSlot\0"
    "f\0sizeComboBoxCurrentIndexChangedSlot\0"
    "sendButtonClickedSlot\0sendToolBtnClickedSlot\0"
    "boldToolBtnClickedSlot\0italicToolBtnClickedSlot\0"
    "underlineToolBtnClickedSlot\0"
    "colorToolBtnClickedSlot\0saveToolBtnClickedSlot\0"
    "clearToolBtnClickedSlot\0"
    "currentFormatChangedSlot\0QTextCharFormat\0"
    "format\0opacitySliderValueChangedSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChatRoom[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    1,   85,    2, 0x08 /* Private */,
       4,    1,   88,    2, 0x08 /* Private */,
       6,    1,   91,    2, 0x08 /* Private */,
       7,    0,   94,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
       9,    0,   96,    2, 0x08 /* Private */,
      10,    0,   97,    2, 0x08 /* Private */,
      11,    0,   98,    2, 0x08 /* Private */,
      12,    0,   99,    2, 0x08 /* Private */,
      13,    0,  100,    2, 0x08 /* Private */,
      14,    0,  101,    2, 0x08 /* Private */,
      15,    1,  102,    2, 0x08 /* Private */,
      18,    0,  105,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QFont,    5,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void,

       0        // eod
};

void ChatRoom::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChatRoom *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->processPendingDatagramsSlot(); break;
        case 1: _t->getFileNameSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->fontComboBoxCurrentFontChangedSlot((*reinterpret_cast< QFont(*)>(_a[1]))); break;
        case 3: _t->sizeComboBoxCurrentIndexChangedSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->sendButtonClickedSlot(); break;
        case 5: _t->sendToolBtnClickedSlot(); break;
        case 6: _t->boldToolBtnClickedSlot(); break;
        case 7: _t->italicToolBtnClickedSlot(); break;
        case 8: _t->underlineToolBtnClickedSlot(); break;
        case 9: _t->colorToolBtnClickedSlot(); break;
        case 10: _t->saveToolBtnClickedSlot(); break;
        case 11: _t->clearToolBtnClickedSlot(); break;
        case 12: _t->currentFormatChangedSlot((*reinterpret_cast< const QTextCharFormat(*)>(_a[1]))); break;
        case 13: _t->opacitySliderValueChangedSlot(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ChatRoom::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_ChatRoom.data,
    qt_meta_data_ChatRoom,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ChatRoom::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChatRoom::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChatRoom.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ChatRoom::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
