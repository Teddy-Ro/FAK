/****************************************************************************
** Meta object code from reading C++ file 'fieldgroup.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../fieldgroup.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fieldgroup.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_FieldGroup_t {
    uint offsetsAndSizes[28];
    char stringdata0[11];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[12];
    char stringdata4[9];
    char stringdata5[14];
    char stringdata6[19];
    char stringdata7[17];
    char stringdata8[13];
    char stringdata9[12];
    char stringdata10[20];
    char stringdata11[13];
    char stringdata12[9];
    char stringdata13[20];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_FieldGroup_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_FieldGroup_t qt_meta_stringdata_FieldGroup = {
    {
        QT_MOC_LITERAL(0, 10),  // "FieldGroup"
        QT_MOC_LITERAL(11, 17),  // "newGroupRequested"
        QT_MOC_LITERAL(29, 0),  // ""
        QT_MOC_LITERAL(30, 11),  // "taskClicked"
        QT_MOC_LITERAL(42, 8),  // "taskData"
        QT_MOC_LITERAL(51, 13),  // "toggle_fields"
        QT_MOC_LITERAL(65, 18),  // "create_input_field"
        QT_MOC_LITERAL(84, 16),  // "create_new_group"
        QT_MOC_LITERAL(101, 12),  // "delete_group"
        QT_MOC_LITERAL(114, 11),  // "update_name"
        QT_MOC_LITERAL(126, 19),  // "show_field_settings"
        QT_MOC_LITERAL(146, 12),  // "QPushButton*"
        QT_MOC_LITERAL(159, 8),  // "fieldBtn"
        QT_MOC_LITERAL(168, 19)   // "onTaskButtonClicked"
    },
    "FieldGroup",
    "newGroupRequested",
    "",
    "taskClicked",
    "taskData",
    "toggle_fields",
    "create_input_field",
    "create_new_group",
    "delete_group",
    "update_name",
    "show_field_settings",
    "QPushButton*",
    "fieldBtn",
    "onTaskButtonClicked"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_FieldGroup[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x06,    1 /* Public */,
       3,    1,   69,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   72,    2, 0x08,    4 /* Private */,
       6,    0,   73,    2, 0x08,    5 /* Private */,
       7,    0,   74,    2, 0x08,    6 /* Private */,
       8,    0,   75,    2, 0x08,    7 /* Private */,
       9,    0,   76,    2, 0x08,    8 /* Private */,
      10,    1,   77,    2, 0x08,    9 /* Private */,
      13,    0,   80,    2, 0x08,   11 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject FieldGroup::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_FieldGroup.offsetsAndSizes,
    qt_meta_data_FieldGroup,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_FieldGroup_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<FieldGroup, std::true_type>,
        // method 'newGroupRequested'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'taskClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'toggle_fields'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'create_input_field'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'create_new_group'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'delete_group'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'update_name'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'show_field_settings'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QPushButton *, std::false_type>,
        // method 'onTaskButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void FieldGroup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FieldGroup *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->newGroupRequested(); break;
        case 1: _t->taskClicked((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->toggle_fields(); break;
        case 3: _t->create_input_field(); break;
        case 4: _t->create_new_group(); break;
        case 5: _t->delete_group(); break;
        case 6: _t->update_name(); break;
        case 7: _t->show_field_settings((*reinterpret_cast< std::add_pointer_t<QPushButton*>>(_a[1]))); break;
        case 8: _t->onTaskButtonClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QPushButton* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FieldGroup::*)();
            if (_t _q_method = &FieldGroup::newGroupRequested; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FieldGroup::*)(const QString & );
            if (_t _q_method = &FieldGroup::taskClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *FieldGroup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FieldGroup::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FieldGroup.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FieldGroup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void FieldGroup::newGroupRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FieldGroup::taskClicked(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
