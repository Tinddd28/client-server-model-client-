/****************************************************************************
** Meta object code from reading C++ file 'dataout.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../dataout.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dataout.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_dataout_t {
    QByteArrayData data[13];
    char stringdata0[165];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_dataout_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_dataout_t qt_meta_stringdata_dataout = {
    {
QT_MOC_LITERAL(0, 0, 7), // "dataout"
QT_MOC_LITERAL(1, 8, 5), // "backb"
QT_MOC_LITERAL(2, 14, 0), // ""
QT_MOC_LITERAL(3, 15, 8), // "GetItems"
QT_MOC_LITERAL(4, 24, 10), // "GetClients"
QT_MOC_LITERAL(5, 35, 9), // "GetOrders"
QT_MOC_LITERAL(6, 45, 11), // "GetMessages"
QT_MOC_LITERAL(7, 57, 16), // "on_items_clicked"
QT_MOC_LITERAL(8, 74, 18), // "on_clients_clicked"
QT_MOC_LITERAL(9, 93, 17), // "on_orders_clicked"
QT_MOC_LITERAL(10, 111, 19), // "on_messages_clicked"
QT_MOC_LITERAL(11, 131, 16), // "on_sales_clicked"
QT_MOC_LITERAL(12, 148, 16) // "on_backb_clicked"

    },
    "dataout\0backb\0\0GetItems\0GetClients\0"
    "GetOrders\0GetMessages\0on_items_clicked\0"
    "on_clients_clicked\0on_orders_clicked\0"
    "on_messages_clicked\0on_sales_clicked\0"
    "on_backb_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_dataout[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    1,   70,    2, 0x06 /* Public */,
       4,    1,   73,    2, 0x06 /* Public */,
       5,    1,   76,    2, 0x06 /* Public */,
       6,    1,   79,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   82,    2, 0x08 /* Private */,
       8,    0,   83,    2, 0x08 /* Private */,
       9,    0,   84,    2, 0x08 /* Private */,
      10,    0,   85,    2, 0x08 /* Private */,
      11,    0,   86,    2, 0x08 /* Private */,
      12,    0,   87,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QJsonDocument,    2,
    QMetaType::Void, QMetaType::QJsonDocument,    2,
    QMetaType::Void, QMetaType::QJsonDocument,    2,
    QMetaType::Void, QMetaType::QJsonDocument,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void dataout::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<dataout *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->backb(); break;
        case 1: _t->GetItems((*reinterpret_cast< QJsonDocument(*)>(_a[1]))); break;
        case 2: _t->GetClients((*reinterpret_cast< QJsonDocument(*)>(_a[1]))); break;
        case 3: _t->GetOrders((*reinterpret_cast< QJsonDocument(*)>(_a[1]))); break;
        case 4: _t->GetMessages((*reinterpret_cast< QJsonDocument(*)>(_a[1]))); break;
        case 5: _t->on_items_clicked(); break;
        case 6: _t->on_clients_clicked(); break;
        case 7: _t->on_orders_clicked(); break;
        case 8: _t->on_messages_clicked(); break;
        case 9: _t->on_sales_clicked(); break;
        case 10: _t->on_backb_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (dataout::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&dataout::backb)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (dataout::*)(QJsonDocument );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&dataout::GetItems)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (dataout::*)(QJsonDocument );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&dataout::GetClients)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (dataout::*)(QJsonDocument );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&dataout::GetOrders)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (dataout::*)(QJsonDocument );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&dataout::GetMessages)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject dataout::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_dataout.data,
    qt_meta_data_dataout,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *dataout::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *dataout::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_dataout.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int dataout::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void dataout::backb()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void dataout::GetItems(QJsonDocument _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void dataout::GetClients(QJsonDocument _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void dataout::GetOrders(QJsonDocument _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void dataout::GetMessages(QJsonDocument _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
