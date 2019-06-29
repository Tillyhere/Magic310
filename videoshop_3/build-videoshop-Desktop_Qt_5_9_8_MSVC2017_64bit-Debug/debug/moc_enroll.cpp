/****************************************************************************
** Meta object code from reading C++ file 'enroll.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../videoshop/enroll.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'enroll.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_enroll_t {
    QByteArrayData data[6];
    char stringdata0[69];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_enroll_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_enroll_t qt_meta_stringdata_enroll = {
    {
QT_MOC_LITERAL(0, 0, 6), // "enroll"
QT_MOC_LITERAL(1, 7, 7), // "display"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 6), // "number"
QT_MOC_LITERAL(4, 23, 23), // "on_returnButton_clicked"
QT_MOC_LITERAL(5, 47, 21) // "on_pbt_enroll_clicked"

    },
    "enroll\0display\0\0number\0on_returnButton_clicked\0"
    "on_pbt_enroll_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_enroll[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   32,    2, 0x08 /* Private */,
       5,    0,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void enroll::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        enroll *_t = static_cast<enroll *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->display((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_returnButton_clicked(); break;
        case 2: _t->on_pbt_enroll_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (enroll::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&enroll::display)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject enroll::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_enroll.data,
      qt_meta_data_enroll,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *enroll::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *enroll::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_enroll.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int enroll::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void enroll::display(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
