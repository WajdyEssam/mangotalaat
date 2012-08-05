/****************************************************************************
** Meta object code from reading C++ file 'headerwidget.h'
**
** Created: Sun Aug 5 00:06:24 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ui/headerwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'headerwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_HeaderWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,
      28,   13,   13,   13, 0x05,
      44,   13,   13,   13, 0x05,
      60,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      79,   76,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_HeaderWidget[] = {
    "HeaderWidget\0\0homeClicked()\0reportClicked()\0"
    "systemClicked()\0logoutClicked()\0id\0"
    "emitSignal(int)\0"
};

void HeaderWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        HeaderWidget *_t = static_cast<HeaderWidget *>(_o);
        switch (_id) {
        case 0: _t->homeClicked(); break;
        case 1: _t->reportClicked(); break;
        case 2: _t->systemClicked(); break;
        case 3: _t->logoutClicked(); break;
        case 4: _t->emitSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData HeaderWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject HeaderWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_HeaderWidget,
      qt_meta_data_HeaderWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &HeaderWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *HeaderWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *HeaderWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_HeaderWidget))
        return static_cast<void*>(const_cast< HeaderWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int HeaderWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void HeaderWidget::homeClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void HeaderWidget::reportClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void HeaderWidget::systemClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void HeaderWidget::logoutClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}
QT_END_MOC_NAMESPACE
