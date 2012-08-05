/****************************************************************************
** Meta object code from reading C++ file 'propertywidget.h'
**
** Created: Sun Aug 5 01:23:24 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ui/propertywidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'propertywidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PropertyWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,
      46,   44,   15,   15, 0x05,
      96,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
     158,  127,   15,   15, 0x0a,
     192,   15,   15,   15, 0x0a,
     217,   15,   15,   15, 0x0a,
     243,   15,   15,   15, 0x0a,
     260,   15,   15,   15, 0x0a,
     280,   15,   15,   15, 0x0a,
     300,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PropertyWidget[] = {
    "PropertyWidget\0\0addItem(Model::OrderDetail)\0"
    ",\0updateItem(Model::OrderDetail,Model::OrderDetail)\0"
    "removeItem(Model::OrderDetail)\0"
    "orderDetail,isOpenedInEditMode\0"
    "setOrder(Model::OrderDetail,bool)\0"
    "setCurrentComponent(int)\0"
    "setCurrentAdditional(int)\0addItemClicked()\0"
    "updateItemClicked()\0removeItemClicked()\0"
    "openKeypadDialog()\0"
};

void PropertyWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PropertyWidget *_t = static_cast<PropertyWidget *>(_o);
        switch (_id) {
        case 0: _t->addItem((*reinterpret_cast< Model::OrderDetail(*)>(_a[1]))); break;
        case 1: _t->updateItem((*reinterpret_cast< Model::OrderDetail(*)>(_a[1])),(*reinterpret_cast< Model::OrderDetail(*)>(_a[2]))); break;
        case 2: _t->removeItem((*reinterpret_cast< Model::OrderDetail(*)>(_a[1]))); break;
        case 3: _t->setOrder((*reinterpret_cast< Model::OrderDetail(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->setCurrentComponent((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setCurrentAdditional((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->addItemClicked(); break;
        case 7: _t->updateItemClicked(); break;
        case 8: _t->removeItemClicked(); break;
        case 9: _t->openKeypadDialog(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PropertyWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PropertyWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_PropertyWidget,
      qt_meta_data_PropertyWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PropertyWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PropertyWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PropertyWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PropertyWidget))
        return static_cast<void*>(const_cast< PropertyWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int PropertyWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void PropertyWidget::addItem(Model::OrderDetail _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PropertyWidget::updateItem(Model::OrderDetail _t1, Model::OrderDetail _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PropertyWidget::removeItem(Model::OrderDetail _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
