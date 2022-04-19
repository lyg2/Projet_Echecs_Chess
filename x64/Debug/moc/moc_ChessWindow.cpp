/****************************************************************************
** Meta object code from reading C++ file 'ChessWindow.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../ChessWindow.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ChessWindow.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ChessWindow_t {
    QByteArrayData data[21];
    char stringdata0[309];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ChessWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ChessWindow_t qt_meta_stringdata_ChessWindow = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ChessWindow"
QT_MOC_LITERAL(1, 12, 13), // "squareClicked"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 12), // "QPushButton*"
QT_MOC_LITERAL(4, 40, 6), // "button"
QT_MOC_LITERAL(5, 47, 4), // "posX"
QT_MOC_LITERAL(6, 52, 4), // "posY"
QT_MOC_LITERAL(7, 57, 18), // "nameOfTheGameTyped"
QT_MOC_LITERAL(8, 76, 4), // "name"
QT_MOC_LITERAL(9, 81, 11), // "checkSquare"
QT_MOC_LITERAL(10, 93, 12), // "drawNewPiece"
QT_MOC_LITERAL(11, 106, 17), // "updateColorSquare"
QT_MOC_LITERAL(12, 124, 16), // "updatePlayerTurn"
QT_MOC_LITERAL(13, 141, 4), // "turn"
QT_MOC_LITERAL(14, 146, 22), // "invalidMovementWarning"
QT_MOC_LITERAL(15, 169, 31), // "on_actionPhilidor1777_triggered"
QT_MOC_LITERAL(16, 201, 33), // "on_actionTD6_Q2_3_Kings_trigg..."
QT_MOC_LITERAL(17, 235, 45), // "on_actionKnights_Of_The_Round..."
QT_MOC_LITERAL(18, 281, 10), // "showWinner"
QT_MOC_LITERAL(19, 292, 4), // "side"
QT_MOC_LITERAL(20, 297, 11) // "warningKing"

    },
    "ChessWindow\0squareClicked\0\0QPushButton*\0"
    "button\0posX\0posY\0nameOfTheGameTyped\0"
    "name\0checkSquare\0drawNewPiece\0"
    "updateColorSquare\0updatePlayerTurn\0"
    "turn\0invalidMovementWarning\0"
    "on_actionPhilidor1777_triggered\0"
    "on_actionTD6_Q2_3_Kings_triggered\0"
    "on_actionKnights_Of_The_Round_Table_triggered\0"
    "showWinner\0side\0warningKing"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ChessWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   74,    2, 0x06 /* Public */,
       7,    1,   81,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   84,    2, 0x08 /* Private */,
      10,    3,   85,    2, 0x08 /* Private */,
      11,    3,   92,    2, 0x08 /* Private */,
      12,    1,   99,    2, 0x08 /* Private */,
      14,    0,  102,    2, 0x08 /* Private */,
      15,    0,  103,    2, 0x08 /* Private */,
      16,    0,  104,    2, 0x08 /* Private */,
      17,    0,  105,    2, 0x08 /* Private */,
      18,    1,  106,    2, 0x08 /* Private */,
      20,    0,  109,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int,    4,    5,    6,
    QMetaType::Void, QMetaType::QString,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,    8,    5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Bool,    5,    6,    2,
    QMetaType::Void, QMetaType::Bool,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void,

       0        // eod
};

void ChessWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChessWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->squareClicked((*reinterpret_cast< QPushButton*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->nameOfTheGameTyped((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->checkSquare(); break;
        case 3: _t->drawNewPiece((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->updateColorSquare((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 5: _t->updatePlayerTurn((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->invalidMovementWarning(); break;
        case 7: _t->on_actionPhilidor1777_triggered(); break;
        case 8: _t->on_actionTD6_Q2_3_Kings_triggered(); break;
        case 9: _t->on_actionKnights_Of_The_Round_Table_triggered(); break;
        case 10: _t->showWinner((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->warningKing(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
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
            using _t = void (ChessWindow::*)(QPushButton * , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChessWindow::squareClicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ChessWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChessWindow::nameOfTheGameTyped)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ChessWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_ChessWindow.data,
    qt_meta_data_ChessWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ChessWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ChessWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ChessWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int ChessWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void ChessWindow::squareClicked(QPushButton * _t1, int _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ChessWindow::nameOfTheGameTyped(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
