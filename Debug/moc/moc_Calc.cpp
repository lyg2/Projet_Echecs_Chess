/****************************************************************************
** Meta object code from reading C++ file 'Calc.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Calc.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Calc.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Calc_t {
    QByteArrayData data[15];
    char stringdata0[184];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Calc_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Calc_t qt_meta_stringdata_Calc = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Calc"
QT_MOC_LITERAL(1, 5, 13), // "valeurChangee"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 6), // "valeur"
QT_MOC_LITERAL(4, 27, 13), // "changerValeur"
QT_MOC_LITERAL(5, 41, 7), // "effacer"
QT_MOC_LITERAL(6, 49, 14), // "ajouterChiffre"
QT_MOC_LITERAL(7, 64, 7), // "chiffre"
QT_MOC_LITERAL(8, 72, 16), // "changerOperation"
QT_MOC_LITERAL(9, 89, 22), // "function<int(int,int)>"
QT_MOC_LITERAL(10, 112, 9), // "operation"
QT_MOC_LITERAL(11, 122, 13), // "operationPlus"
QT_MOC_LITERAL(12, 136, 14), // "operationMoins"
QT_MOC_LITERAL(13, 151, 13), // "operationEgal"
QT_MOC_LITERAL(14, 165, 18) // "effectuerOperation"

    },
    "Calc\0valeurChangee\0\0valeur\0changerValeur\0"
    "effacer\0ajouterChiffre\0chiffre\0"
    "changerOperation\0function<int(int,int)>\0"
    "operation\0operationPlus\0operationMoins\0"
    "operationEgal\0effectuerOperation"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Calc[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   62,    2, 0x0a /* Public */,
       5,    0,   65,    2, 0x0a /* Public */,
       6,    1,   66,    2, 0x0a /* Public */,
       8,    1,   69,    2, 0x0a /* Public */,
      11,    0,   72,    2, 0x0a /* Public */,
      12,    0,   73,    2, 0x0a /* Public */,
      13,    0,   74,    2, 0x0a /* Public */,
      14,    0,   75,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Calc::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Calc *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valeurChangee((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->changerValeur((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->effacer(); break;
        case 3: _t->ajouterChiffre((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->changerOperation((*reinterpret_cast< const function<int(int,int)>(*)>(_a[1]))); break;
        case 5: _t->operationPlus(); break;
        case 6: _t->operationMoins(); break;
        case 7: _t->operationEgal(); break;
        case 8: _t->effectuerOperation(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Calc::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Calc::valeurChangee)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Calc::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Calc.data,
    qt_meta_data_Calc,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Calc::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Calc::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Calc.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Calc::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
void Calc::valeurChangee(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
