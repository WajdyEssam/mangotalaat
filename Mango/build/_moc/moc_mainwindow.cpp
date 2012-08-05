/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sun Aug 5 01:23:22 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ui/mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      25,   12,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      71,   11,   11,   11, 0x08,
      86,   11,   11,   11, 0x08,
     119,  106,   11,   11, 0x08,
     145,   11,   11,   11, 0x08,
     165,   11,   11,   11, 0x08,
     185,   11,   11,   11, 0x08,
     209,   11,   11,   11, 0x08,
     245,  234,   11,   11, 0x08,
     276,  269,   11,   11, 0x08,
     309,  296,   11,   11, 0x08,
     335,   11,   11,   11, 0x08,
     371,  369,   11,   11, 0x08,
     427,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0orderDetails\0"
    "orderDetailUpdated(QList<Model::OrderDetail>)\0"
    "ShowHomePage()\0reportClickedSlot()\0"
    "orderIndexId\0orderItemClicked(QString)\0"
    "systemClickedSlot()\0logoutClickedSlot()\0"
    "applyOrderClickedSlot()\0"
    "cancelOrderClickedSlot()\0categoryId\0"
    "selectCategorySlot(int)\0itemId\0"
    "selectItemSlot(int)\0itemDetialId\0"
    "selectItemDetialSlot(int)\0"
    "addItemToCart(Model::OrderDetail)\0,\0"
    "updateItemInCart(Model::OrderDetail,Model::OrderDetail)\0"
    "removeItemFromCart(Model::OrderDetail)\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->orderDetailUpdated((*reinterpret_cast< QList<Model::OrderDetail>(*)>(_a[1]))); break;
        case 1: _t->ShowHomePage(); break;
        case 2: _t->reportClickedSlot(); break;
        case 3: _t->orderItemClicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->systemClickedSlot(); break;
        case 5: _t->logoutClickedSlot(); break;
        case 6: _t->applyOrderClickedSlot(); break;
        case 7: _t->cancelOrderClickedSlot(); break;
        case 8: _t->selectCategorySlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->selectItemSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->selectItemDetialSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->addItemToCart((*reinterpret_cast< Model::OrderDetail(*)>(_a[1]))); break;
        case 12: _t->updateItemInCart((*reinterpret_cast< Model::OrderDetail(*)>(_a[1])),(*reinterpret_cast< Model::OrderDetail(*)>(_a[2]))); break;
        case 13: _t->removeItemFromCart((*reinterpret_cast< Model::OrderDetail(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::orderDetailUpdated(QList<Model::OrderDetail> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
