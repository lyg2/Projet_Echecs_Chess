/****************************************************************************
** Meta object code from reading C++ file 'Controleur.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Controleur.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Controleur.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Controleur_t {
    QByteArrayData data[18];
    char stringdata0[184];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Controleur_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Controleur_t qt_meta_stringdata_Controleur = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Controleur"
QT_MOC_LITERAL(1, 11, 9), // "drawPiece"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 4), // "name"
QT_MOC_LITERAL(4, 27, 4), // "posX"
QT_MOC_LITERAL(5, 32, 4), // "posY"
QT_MOC_LITERAL(6, 37, 14), // "changeLocation"
QT_MOC_LITERAL(7, 52, 11), // "colorSquare"
QT_MOC_LITERAL(8, 64, 10), // "isSelected"
QT_MOC_LITERAL(9, 75, 10), // "playerTurn"
QT_MOC_LITERAL(10, 86, 15), // "invalidMovement"
QT_MOC_LITERAL(11, 102, 9), // "checkmate"
QT_MOC_LITERAL(12, 112, 4), // "side"
QT_MOC_LITERAL(13, 117, 13), // "squareClicker"
QT_MOC_LITERAL(14, 131, 12), // "QPushButton*"
QT_MOC_LITERAL(15, 144, 12), // "squareButton"
QT_MOC_LITERAL(16, 157, 14), // "newGameClicker"
QT_MOC_LITERAL(17, 172, 11) // "newGameMenu"

    },
    "Controleur\0drawPiece\0\0name\0posX\0posY\0"
    "changeLocation\0colorSquare\0isSelected\0"
    "playerTurn\0invalidMovement\0checkmate\0"
    "side\0squareClicker\0QPushButton*\0"
    "squareButton\0newGameClicker\0newGameMenu"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Controleur[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   59,    2, 0x06 /* Public */,
       6,    2,   66,    2, 0x06 /* Public */,
       7,    3,   71,    2, 0x06 /* Public */,
       9,    1,   78,    2, 0x06 /* Public */,
      10,    0,   81,    2, 0x06 /* Public */,
      11,    1,   82,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    3,   85,    2, 0x0a /* Public */,
      16,    0,   92,    2, 0x0a /* Public */,
      17,    1,   93,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,    3,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Bool,    4,    5,    8,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 14, QMetaType::Int, QMetaType::Int,   15,    4,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    3,

       0        // eod
};

void Controleur::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Controleur *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->drawPiece((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->changeLocation((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->colorSquare((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 3: _t->playerTurn((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->invalidMovement(); break;
        case 5: _t->checkmate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->squareClicker((*reinterpret_cast< QPushButton*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 7: _t->newGameClicker(); break;
        case 8: _t->newGameMenu((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QPushButton* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Controleur::*)(QString , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controleur::drawPiece)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Controleur::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controleur::changeLocation)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Controleur::*)(int , int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controleur::colorSquare)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Controleur::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controleur::playerTurn)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Controleur::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controleur::invalidMovement)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Controleur::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controleur::checkmate)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Controleur::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Controleur.data,
    qt_meta_data_Controleur,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Controleur::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controleur::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Controleur.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Controleur::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Controleur::drawPiece(QString _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Controleur::changeLocation(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Controleur::colorSquare(int _t1, int _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Controleur::playerTurn(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Controleur::invalidMovement()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Controleur::checkmate(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
