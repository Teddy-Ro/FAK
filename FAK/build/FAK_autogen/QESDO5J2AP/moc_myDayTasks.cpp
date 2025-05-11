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
    uint offsetsAndSizes[26];
    char stringdata0[11];
    char stringdata1[27];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[11];
    char stringdata5[22];
    char stringdata6[22];
    char stringdata7[21];
    char stringdata8[8];
    char stringdata9[24];
    char stringdata10[19];
    char stringdata11[16];
    char stringdata12[20];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MyDayTasks_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MyDayTasks_t qt_meta_stringdata_MyDayTasks = {
    {
        QT_MOC_LITERAL(0, 10),  // "MyDayTasks"
        QT_MOC_LITERAL(11, 26),  // "showDeadlinePanelRequested"
        QT_MOC_LITERAL(38, 0),  // ""
        QT_MOC_LITERAL(39, 8),  // "QWidget*"
        QT_MOC_LITERAL(48, 10),  // "taskWidget"
        QT_MOC_LITERAL(59, 21),  // "createButtonFromInput"
        QT_MOC_LITERAL(81, 21),  // "handleTaskButtonClick"
        QT_MOC_LITERAL(103, 20),  // "handleCheckboxToggle"
        QT_MOC_LITERAL(124, 7),  // "checked"
        QT_MOC_LITERAL(132, 23),  // "handleDeleteButtonClick"
        QT_MOC_LITERAL(156, 18),  // "showTaskProperties"
        QT_MOC_LITERAL(175, 15),  // "setTaskDeadline"
        QT_MOC_LITERAL(191, 19)   // "showDeadlineOptions"
    },
    "MyDayTasks",
    "showDeadlinePanelRequested",
    "",
    "QWidget*",
    "taskWidget",
    "createButtonFromInput",
    "handleTaskButtonClick",
    "handleCheckboxToggle",
    "checked",
    "handleDeleteButtonClick",
    "showTaskProperties",
    "setTaskDeadline",
    "showDeadlineOptions"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MyDayTasks[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   65,    2, 0x08,    3 /* Private */,
       6,    0,   66,    2, 0x08,    4 /* Private */,
       7,    1,   67,    2, 0x08,    5 /* Private */,
       9,    0,   70,    2, 0x08,    7 /* Private */,
      10,    0,   71,    2, 0x08,    8 /* Private */,
      11,    0,   72,    2, 0x08,    9 /* Private */,
      12,    0,   73,    2, 0x08,   10 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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
        // method 'showDeadlinePanelRequested'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QWidget *, std::false_type>,
        // method 'createButtonFromInput'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleTaskButtonClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleCheckboxToggle'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'handleDeleteButtonClick'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showTaskProperties'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'setTaskDeadline'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showDeadlineOptions'
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
        case 0: _t->showDeadlinePanelRequested((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1]))); break;
        case 1: _t->createButtonFromInput(); break;
        case 2: _t->handleTaskButtonClick(); break;
        case 3: _t->handleCheckboxToggle((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 4: _t->handleDeleteButtonClick(); break;
        case 5: _t->showTaskProperties(); break;
        case 6: _t->setTaskDeadline(); break;
        case 7: _t->showDeadlineOptions(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QWidget* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyDayTasks::*)(QWidget * );
            if (_t _q_method = &MyDayTasks::showDeadlinePanelRequested; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
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
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void MyDayTasks::showDeadlinePanelRequested(QWidget * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
