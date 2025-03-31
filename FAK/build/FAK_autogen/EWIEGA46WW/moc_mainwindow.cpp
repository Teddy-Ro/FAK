/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
<<<<<<< Updated upstream
<<<<<<<< Updated upstream:FAK/build/FAK_autogen/EWIEGA46WW/moc_mainwindow.cpp
#include "../../../mainwindow.h"
========
#include "../../../classes/myDayTasks.h"
>>>>>>>> Stashed changes:FAK/build/FAK_autogen/QESDO5J2AP/moc_myDayTasks.cpp
=======
#include "../../../mainwindow.h"
>>>>>>> Stashed changes
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
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
<<<<<<< Updated upstream
<<<<<<<< Updated upstream:FAK/build/FAK_autogen/EWIEGA46WW/moc_mainwindow.cpp
struct qt_meta_stringdata_MainWindow_t {
========
struct qt_meta_stringdata_MyDayTasks_t {
>>>>>>>> Stashed changes:FAK/build/FAK_autogen/QESDO5J2AP/moc_myDayTasks.cpp
    uint offsetsAndSizes[12];
    char stringdata0[11];
    char stringdata1[22];
    char stringdata2[1];
    char stringdata3[16];
    char stringdata4[21];
    char stringdata5[8];
};
#define QT_MOC_LITERAL(ofs, len) \
<<<<<<<< Updated upstream:FAK/build/FAK_autogen/EWIEGA46WW/moc_mainwindow.cpp
=======
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[8];
    char stringdata0[11];
    char stringdata1[15];
    char stringdata2[1];
    char stringdata3[6];
};
#define QT_MOC_LITERAL(ofs, len) \
>>>>>>> Stashed changes
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
<<<<<<< Updated upstream
========
    uint(sizeof(qt_meta_stringdata_MyDayTasks_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MyDayTasks_t qt_meta_stringdata_MyDayTasks = {
    {
        QT_MOC_LITERAL(0, 10),  // "MyDayTasks"
>>>>>>>> Stashed changes:FAK/build/FAK_autogen/QESDO5J2AP/moc_myDayTasks.cpp
        QT_MOC_LITERAL(11, 21),  // "createButtonFromInput"
        QT_MOC_LITERAL(33, 0),  // ""
        QT_MOC_LITERAL(34, 15),  // "handleNewButton"
        QT_MOC_LITERAL(50, 20),  // "handleCheckboxToggle"
        QT_MOC_LITERAL(71, 7)   // "checked"
    },
<<<<<<<< Updated upstream:FAK/build/FAK_autogen/EWIEGA46WW/moc_mainwindow.cpp
    "MainWindow",
========
    "MyDayTasks",
>>>>>>>> Stashed changes:FAK/build/FAK_autogen/QESDO5J2AP/moc_myDayTasks.cpp
    "createButtonFromInput",
    "",
    "handleNewButton",
    "handleCheckboxToggle",
    "checked"
=======
        QT_MOC_LITERAL(11, 14),  // "loadTabContent"
        QT_MOC_LITERAL(26, 0),  // ""
        QT_MOC_LITERAL(27, 5)   // "index"
    },
    "MainWindow",
    "loadTabContent",
    "",
    "index"
>>>>>>> Stashed changes
};
#undef QT_MOC_LITERAL
} // unnamed namespace

<<<<<<< Updated upstream
<<<<<<<< Updated upstream:FAK/build/FAK_autogen/EWIEGA46WW/moc_mainwindow.cpp
Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {
========
Q_CONSTINIT static const uint qt_meta_data_MyDayTasks[] = {
>>>>>>>> Stashed changes:FAK/build/FAK_autogen/QESDO5J2AP/moc_myDayTasks.cpp
=======
Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {
>>>>>>> Stashed changes

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
<<<<<<< Updated upstream
       3,   14, // methods
=======
       1,   14, // methods
>>>>>>> Stashed changes
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
<<<<<<< Updated upstream
       1,    0,   32,    2, 0x08,    1 /* Private */,
       3,    0,   33,    2, 0x08,    2 /* Private */,
       4,    1,   34,    2, 0x08,    3 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    5,
=======
       1,    1,   20,    2, 0x08,    1 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
>>>>>>> Stashed changes

       0        // eod
};

<<<<<<< Updated upstream
<<<<<<<< Updated upstream:FAK/build/FAK_autogen/EWIEGA46WW/moc_mainwindow.cpp
=======
>>>>>>> Stashed changes
Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
<<<<<<< Updated upstream
========
Q_CONSTINIT const QMetaObject MyDayTasks::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_MyDayTasks.offsetsAndSizes,
    qt_meta_data_MyDayTasks,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MyDayTasks_t,
>>>>>>>> Stashed changes:FAK/build/FAK_autogen/QESDO5J2AP/moc_myDayTasks.cpp
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'createButtonFromInput'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleNewButton'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleCheckboxToggle'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<bool, std::false_type>
=======
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'loadTabContent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
>>>>>>> Stashed changes
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
<<<<<<< Updated upstream
<<<<<<<< Updated upstream:FAK/build/FAK_autogen/EWIEGA46WW/moc_mainwindow.cpp
        auto *_t = static_cast<MainWindow *>(_o);
========
        auto *_t = static_cast<MyDayTasks *>(_o);
>>>>>>>> Stashed changes:FAK/build/FAK_autogen/QESDO5J2AP/moc_myDayTasks.cpp
        (void)_t;
        switch (_id) {
        case 0: _t->createButtonFromInput(); break;
        case 1: _t->handleNewButton(); break;
        case 2: _t->handleCheckboxToggle((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
=======
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->loadTabContent((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
>>>>>>> Stashed changes
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
<<<<<<< Updated upstream
<<<<<<<< Updated upstream:FAK/build/FAK_autogen/EWIEGA46WW/moc_mainwindow.cpp
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
========
    if (!strcmp(_clname, qt_meta_stringdata_MyDayTasks.stringdata0))
>>>>>>>> Stashed changes:FAK/build/FAK_autogen/QESDO5J2AP/moc_myDayTasks.cpp
=======
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
>>>>>>> Stashed changes
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
<<<<<<< Updated upstream
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
=======
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
>>>>>>> Stashed changes
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
