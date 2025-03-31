/****************************************************************************
** Meta object code from reading C++ file 'myDayTasks.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../classes/myDayTasks.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'myDayTasks.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_MyDayTasks_t {
    uint offsetsAndSizes[14];
    char stringdata0[11];
    char stringdata1[22];
    char stringdata2[1];
    char stringdata3[22];
    char stringdata4[21];
    char stringdata5[8];
    char stringdata6[24];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MyDayTasks_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MyDayTasks_t qt_meta_stringdata_MyDayTasks = {
    {
        QT_MOC_LITERAL(0, 10),  // "MyDayTasks"
        QT_MOC_LITERAL(11, 21),  // "createButtonFromInput"
        QT_MOC_LITERAL(33, 0),  // ""
        QT_MOC_LITERAL(34, 21),  // "handleTaskButtonClick"
        QT_MOC_LITERAL(56, 20),  // "handleCheckboxToggle"
        QT_MOC_LITERAL(77, 7),  // "checked"
        QT_MOC_LITERAL(85, 23)   // "handleDeleteButtonClick"
    },
    "MyDayTasks",
    "createButtonFromInput",
    "",
    "handleTaskButtonClick",
    "handleCheckboxToggle",
    "checked",
    "handleDeleteButtonClick"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MyDayTasks[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   38,    2, 0x08,    1 /* Private */,
       3,    0,   39,    2, 0x08,    2 /* Private */,
       4,    1,   40,    2, 0x08,    3 /* Private */,
       6,    0,   43,    2, 0x08,    5 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MyDayTasks::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_MyDayTasks.offsetsAndSizes,
    qt_meta_data_MyDayTasks,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MyDayTasks_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MyDayTasks, std::true_type>,
        // method 'createButtonFromInput'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleTaskButtonClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleCheckboxToggle'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'handleDeleteButtonClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MyDayTasks::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyDayTasks *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->createButtonFromInput(); break;
        case 1: _t->handleTaskButtonClick(); break;
        case 2: _t->handleCheckboxToggle((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 3: _t->handleDeleteButtonClick(); break;
        default: ;
        }
    }
}

const QMetaObject *MyDayTasks::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyDayTasks::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyDayTasks.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int MyDayTasks::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
