/****************************************************************************
** Meta object code from reading C++ file 'keypaddialog.h'
**
** Created: Sun Aug 5 00:06:29 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ui/keypaddialog.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'keypaddialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_KeypadDialog[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      26,   13,   13,   13, 0x08,
      45,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_KeypadDialog[] = {
    "KeypadDialog\0\0appned(int)\0backspaceClicked()\0"
    "clearClicked()\0"
};

void KeypadDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        KeypadDialog *_t = static_cast<KeypadDialog *>(_o);
        switch (_id) {
        case 0: _t->appned((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->backspaceClicked(); break;
        case 2: _t->clearClicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData KeypadDialog::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject KeypadDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_KeypadDialog,
      qt_meta_data_KeypadDialog, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &KeypadDialog::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *KeypadDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *KeypadDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_KeypadDialog))
        return static_cast<void*>(const_cast< KeypadDialog*>(this));
    return QDialog::qt_metacast(_clname);
}

int KeypadDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
