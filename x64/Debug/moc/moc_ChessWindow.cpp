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
    char stringdata0[279];
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
QT_MOC_LITERAL(7, 57, 14), // "newGameClicked"
QT_MOC_LITERAL(8, 72, 18), // "nameOfTheGameTyped"
QT_MOC_LITERAL(9, 91, 4), // "name"
QT_MOC_LITERAL(10, 96, 11), // "checkSquare"
QT_MOC_LITERAL(11, 108, 12), // "checkNewgame"
QT_MOC_LITERAL(12, 121, 12), // "drawNewPiece"
QT_MOC_LITERAL(13, 134, 17), // "updateColorSquare"
QT_MOC_LITERAL(14, 152, 16), // "updatePlayerTurn"
QT_MOC_LITERAL(15, 169, 4), // "turn"
QT_MOC_LITERAL(16, 174, 22), // "invalidMovementWarning"
QT_MOC_LITERAL(17, 197, 31), // "on_actionPhilidor1777_triggered"
QT_MOC_LITERAL(18, 229, 33), // "on_actionTD6_Q2_3_Kings_trigg..."
QT_MOC_LITERAL(19, 263, 10), // "showWinner"
QT_MOC_LITERAL(20, 274, 4) // "side"

    },
    "ChessWindow\0squareClicked\0\0QPushButton*\0"
    "button\0posX\0posY\0newGameClicked\0"
    "nameOfTheGameTyped\0name\0checkSquare\0"
    "checkNewgame\0drawNewPiece\0updateColorSquare\0"
    "updatePlayerTurn\0turn\0invalidMovementWarning\0"
    "on_actionPhilidor1777_triggered\0"
    "on_actionTD6_Q2_3_Kings_triggered\0"
    "showWinner\0side"
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
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   74,    2, 0x06 /* Public */,
       7,    0,   81,    2, 0x06 /* Public */,
       8,    1,   82,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   85,    2, 0x08 /* Private */,
      11,    0,   86,    2, 0x08 /* Private */,
      12,    3,   87,    2, 0x08 /* Private */,
      13,    3,   94,    2, 0x08 /* Private */,
      14,    1,  101,    2, 0x08 /* Private */,
      16,    0,  104,    2, 0x08 /* Private */,
      17,    0,  105,    2, 0x08 /* Private */,
      18,    0,  106,    2, 0x08 /* Private */,
      19,    1,  107,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int,    4,    5,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,    9,    5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Bool,    5,    6,    2,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   20,

       0        // eod
};

void ChessWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ChessWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->squareClicked((*reinterpret_cast< QPushButton*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->newGameClicked(); break;
        case 2: _t->nameOfTheGameTyped((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->checkSquare(); break;
        case 4: _t->checkNewgame(); break;
        case 5: _t->drawNewPiece((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->updateColorSquare((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 7: _t->updatePlayerTurn((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->invalidMovementWarning(); break;
        case 9: _t->on_actionPhilidor1777_triggered(); break;
        case 10: _t->on_actionTD6_Q2_3_Kings_triggered(); break;
        case 11: _t->showWinner((*reinterpret_cast< QString(*)>(_a[1]))); break;
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
            using _t = void (ChessWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChessWindow::newGameClicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ChessWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ChessWindow::nameOfTheGameTyped)) {
                *result = 2;
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
void ChessWindow::newGameClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ChessWindow::nameOfTheGameTyped(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
