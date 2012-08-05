/****************************************************************************
** Meta object code from reading C++ file 'SlidingStackedWidget.h'
**
** Created: Sun Aug 5 00:06:25 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ui/SlidingStackedWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SlidingStackedWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SlidingStackedWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x05,

 // slots: signature, parameters, type, tag, flags
      48,   42,   21,   21, 0x0a,
      76,   62,   21,   21, 0x0a,
     118,  109,   21,   21, 0x0a,
     140,   21,   21,   21, 0x2a,
     163,  158,   21,   21, 0x0a,
     177,   21,   21,   21, 0x0a,
     191,   21,   21,   21, 0x0a,
     219,  205,   21,   21, 0x0a,
     251,  247,   21,   21, 0x2a,
     267,   21,   21,   21, 0x09,

       0        // eod
};

static const char qt_meta_stringdata_SlidingStackedWidget[] = {
    "SlidingStackedWidget\0\0animationFinished()\0"
    "speed\0setSpeed(int)\0animationtype\0"
    "setAnimation(QEasingCurve::Type)\0"
    "vertical\0setVerticalMode(bool)\0"
    "setVerticalMode()\0wrap\0setWrap(bool)\0"
    "slideInNext()\0slideInPrev()\0idx,direction\0"
    "slideInIdx(int,t_direction)\0idx\0"
    "slideInIdx(int)\0animationDoneSlot()\0"
};

void SlidingStackedWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SlidingStackedWidget *_t = static_cast<SlidingStackedWidget *>(_o);
        switch (_id) {
        case 0: _t->animationFinished(); break;
        case 1: _t->setSpeed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setAnimation((*reinterpret_cast< QEasingCurve::Type(*)>(_a[1]))); break;
        case 3: _t->setVerticalMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->setVerticalMode(); break;
        case 5: _t->setWrap((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->slideInNext(); break;
        case 7: _t->slideInPrev(); break;
        case 8: _t->slideInIdx((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< t_direction(*)>(_a[2]))); break;
        case 9: _t->slideInIdx((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->animationDoneSlot(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SlidingStackedWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SlidingStackedWidget::staticMetaObject = {
    { &QStackedWidget::staticMetaObject, qt_meta_stringdata_SlidingStackedWidget,
      qt_meta_data_SlidingStackedWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SlidingStackedWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SlidingStackedWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SlidingStackedWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SlidingStackedWidget))
        return static_cast<void*>(const_cast< SlidingStackedWidget*>(this));
    return QStackedWidget::qt_metacast(_clname);
}

int SlidingStackedWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStackedWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void SlidingStackedWidget::animationFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
