/****************************************************************************
** Meta object code from reading C++ file 'users.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../users.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'users.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_users_t {
    QByteArrayData data[12];
    char stringdata0[127];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_users_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_users_t qt_meta_stringdata_users = {
    {
QT_MOC_LITERAL(0, 0, 5), // "users"
QT_MOC_LITERAL(1, 6, 4), // "back"
QT_MOC_LITERAL(2, 11, 0), // ""
QT_MOC_LITERAL(3, 12, 4), // "edit"
QT_MOC_LITERAL(4, 17, 7), // "senddel"
QT_MOC_LITERAL(5, 25, 14), // "sendReqForEdit"
QT_MOC_LITERAL(6, 40, 6), // "action"
QT_MOC_LITERAL(7, 47, 9), // "send_data"
QT_MOC_LITERAL(8, 57, 17), // "on_create_clicked"
QT_MOC_LITERAL(9, 75, 15), // "on_edit_clicked"
QT_MOC_LITERAL(10, 91, 19), // "on_delete_2_clicked"
QT_MOC_LITERAL(11, 111, 15) // "on_back_clicked"

    },
    "users\0back\0\0edit\0senddel\0sendReqForEdit\0"
    "action\0send_data\0on_create_clicked\0"
    "on_edit_clicked\0on_delete_2_clicked\0"
    "on_back_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_users[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    1,   60,    2, 0x06 /* Public */,
       4,    1,   63,    2, 0x06 /* Public */,
       5,    1,   66,    2, 0x06 /* Public */,
       7,    6,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   82,    2, 0x08 /* Private */,
       9,    0,   83,    2, 0x08 /* Private */,
      10,    0,   84,    2, 0x08 /* Private */,
      11,    0,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonDocument,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    2,    2,    2,    2,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void users::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<users *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->back(); break;
        case 1: _t->edit((*reinterpret_cast< QJsonDocument(*)>(_a[1]))); break;
        case 2: _t->senddel((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->sendReqForEdit((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->send_data((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6]))); break;
        case 5: _t->on_create_clicked(); break;
        case 6: _t->on_edit_clicked(); break;
        case 7: _t->on_delete_2_clicked(); break;
        case 8: _t->on_back_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (users::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&users::back)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (users::*)(QJsonDocument );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&users::edit)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (users::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&users::senddel)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (users::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&users::sendReqForEdit)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (users::*)(QString , QString , QString , QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&users::send_data)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject users::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_users.data,
    qt_meta_data_users,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *users::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *users::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_users.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int users::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void users::back()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void users::edit(QJsonDocument _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void users::senddel(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void users::sendReqForEdit(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void users::send_data(QString _t1, QString _t2, QString _t3, QString _t4, QString _t5, QString _t6)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
