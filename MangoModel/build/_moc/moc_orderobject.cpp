/****************************************************************************
** Meta object code from reading C++ file 'orderobject.h'
**
** Created: Sun Aug 5 00:05:09 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../orderobject.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'orderobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_OrderObject[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       6,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
      16,   12, 0x02095001,
      32,   24, 0x0a095001,
      45,   24, 0x0a095001,
      55,   24, 0x0a095001,
      72,   24, 0x0a095001,
      82,   12, 0x02095001,

       0        // eod
};

static const char qt_meta_stringdata_OrderObject[] = {
    "OrderObject\0int\0orderId\0QString\0"
    "orderIndexId\0orderName\0orderDescription\0"
    "orderCost\0orderCategory\0"
};

void OrderObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData OrderObject::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject OrderObject::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_OrderObject,
      qt_meta_data_OrderObject, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OrderObject::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OrderObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OrderObject::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OrderObject))
        return static_cast<void*>(const_cast< OrderObject*>(this));
    return QObject::qt_metacast(_clname);
}

int OrderObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = orderId(); break;
        case 1: *reinterpret_cast< QString*>(_v) = orderIndexId(); break;
        case 2: *reinterpret_cast< QString*>(_v) = orderName(); break;
        case 3: *reinterpret_cast< QString*>(_v) = orderDescription(); break;
        case 4: *reinterpret_cast< QString*>(_v) = orderCost(); break;
        case 5: *reinterpret_cast< int*>(_v) = orderCategory(); break;
        }
        _id -= 6;
    } else if (_c == QMetaObject::WriteProperty) {
        _id -= 6;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
