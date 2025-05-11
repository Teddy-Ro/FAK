/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../mainwindow.h"
#include <QtGui/qtextcursor.h>
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
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[26];
    char stringdata0[11];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[9];
    char stringdata4[11];
    char stringdata5[18];
    char stringdata6[22];
    char stringdata7[9];
    char stringdata8[15];
    char stringdata9[6];
    char stringdata10[14];
    char stringdata11[9];
    char stringdata12[19];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 17),  // "showDeadlinePanel"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 8),  // "QWidget*"
        QT_MOC_LITERAL(39, 10),  // "taskWidget"
        QT_MOC_LITERAL(50, 17),  // "hideDeadlinePanel"
        QT_MOC_LITERAL(68, 21),  // "handleDeadlineApplied"
        QT_MOC_LITERAL(90, 8),  // "deadline"
        QT_MOC_LITERAL(99, 14),  // "loadTabContent"
        QT_MOC_LITERAL(114, 5),  // "index"
        QT_MOC_LITERAL(120, 13),  // "onTaskClicked"
        QT_MOC_LITERAL(134, 8),  // "taskData"
        QT_MOC_LITERAL(143, 18)   // "createNewTaskGroup"
    },
    "MainWindow",
    "showDeadlinePanel",
    "",
    "QWidget*",
    "taskWidget",
    "hideDeadlinePanel",
    "handleDeadlineApplied",
    "deadline",
    "loadTabContent",
    "index",
    "onTaskClicked",
    "taskData",
    "createNewTaskGroup"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   50,    2, 0x08,    1 /* Private */,
       5,    0,   53,    2, 0x08,    3 /* Private */,
       6,    1,   54,    2, 0x08,    4 /* Private */,
       8,    1,   57,    2, 0x08,    6 /* Private */,
      10,    1,   60,    2, 0x08,    8 /* Private */,
      12,    0,   63,    2, 0x08,   10 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QDateTime,    7,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'showDeadlinePanel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QWidget *, std::false_type>,
        // method 'hideDeadlinePanel'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleDeadlineApplied'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QDateTime &, std::false_type>,
        // method 'loadTabContent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onTaskClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'createNewTaskGroup'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->showDeadlinePanel((*reinterpret_cast< std::add_pointer_t<QWidget*>>(_a[1]))); break;
        case 1: _t->hideDeadlinePanel(); break;
        case 2: _t->handleDeadlineApplied((*reinterpret_cast< std::add_pointer_t<QDateTime>>(_a[1]))); break;
        case 3: _t->loadTabContent((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->onTaskClicked((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->createNewTaskGroup(); break;
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
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
