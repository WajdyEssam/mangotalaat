/****************************************************************************
** Meta object code from reading C++ file 'orderwidget.h'
**
** Created: Sun Aug 5 00:06:24 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ui/orderwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'orderwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_OrderWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      37,   12,   12,   12, 0x05,
      52,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      68,   12,   12,   12, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_OrderWidget[] = {
    "OrderWidget\0\0orderItemClick(QString)\0"
    "applyClicked()\0cancelClicked()\0"
    "updateOrderDetails(QList<Model::OrderDetail>)\0"
};

void OrderWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        OrderWidget *_t = static_cast<OrderWidget *>(_o);
        switch (_id) {
        case 0: _t->orderItemClick((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->applyClicked(); break;
        case 2: _t->cancelClicked(); break;
        case 3: _t->updateOrderDetails((*reinterpret_cast< QList<Model::OrderDetail>(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData OrderWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject OrderWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_OrderWidget,
      qt_meta_data_OrderWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &OrderWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *OrderWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *OrderWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_OrderWidget))
        return static_cast<void*>(const_cast< OrderWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int OrderWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void OrderWidget::orderItemClick(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void OrderWidget::applyClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void OrderWidget::cancelClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
