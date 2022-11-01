/****************************************************************************
** Meta object code from reading C++ file 'viewerappmain.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../viewer/viewerappmain.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'viewerappmain.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.0. It"
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
struct qt_meta_stringdata_ViewerAppMain_t {
    uint offsetsAndSizes[34];
    char stringdata0[14];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[11];
    char stringdata5[7];
    char stringdata6[8];
    char stringdata7[9];
    char stringdata8[12];
    char stringdata9[3];
    char stringdata10[17];
    char stringdata11[18];
    char stringdata12[14];
    char stringdata13[6];
    char stringdata14[11];
    char stringdata15[4];
    char stringdata16[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_ViewerAppMain_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_ViewerAppMain_t qt_meta_stringdata_ViewerAppMain = {
    {
        QT_MOC_LITERAL(0, 13),  // "ViewerAppMain"
        QT_MOC_LITERAL(14, 13),  // "sigUpdateData"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 4),  // "name"
        QT_MOC_LITERAL(34, 10),  // "assemScore"
        QT_MOC_LITERAL(45, 6),  // "cScore"
        QT_MOC_LITERAL(52, 7),  // "jsScore"
        QT_MOC_LITERAL(60, 8),  // "qmlScore"
        QT_MOC_LITERAL(69, 11),  // "openGlScore"
        QT_MOC_LITERAL(81, 2),  // "id"
        QT_MOC_LITERAL(84, 16),  // "onSigDataChanged"
        QT_MOC_LITERAL(101, 17),  // "onSigEmployeeData"
        QT_MOC_LITERAL(119, 13),  // "EmployeeGrade"
        QT_MOC_LITERAL(133, 5),  // "grade"
        QT_MOC_LITERAL(139, 10),  // "listSearch"
        QT_MOC_LITERAL(150, 3),  // "inp"
        QT_MOC_LITERAL(154, 9)   // "queryData"
    },
    "ViewerAppMain",
    "sigUpdateData",
    "",
    "name",
    "assemScore",
    "cScore",
    "jsScore",
    "qmlScore",
    "openGlScore",
    "id",
    "onSigDataChanged",
    "onSigEmployeeData",
    "EmployeeGrade",
    "grade",
    "listSearch",
    "inp",
    "queryData"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_ViewerAppMain[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    7,   44,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    0,   59,    2, 0x08,    9 /* Private */,
      11,    1,   60,    2, 0x08,   10 /* Private */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      14,    1,   63,    2, 0x02,   12 /* Public */,
      16,    1,   66,    2, 0x02,   14 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,    6,    7,    8,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::Int,    9,

       0        // eod
};

Q_CONSTINIT const QMetaObject ViewerAppMain::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ViewerAppMain.offsetsAndSizes,
    qt_meta_data_ViewerAppMain,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_ViewerAppMain_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<ViewerAppMain, std::true_type>,
        // method 'sigUpdateData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onSigDataChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSigEmployeeData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<EmployeeGrade, std::false_type>,
        // method 'listSearch'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'queryData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void ViewerAppMain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ViewerAppMain *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sigUpdateData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[7]))); break;
        case 1: _t->onSigDataChanged(); break;
        case 2: _t->onSigEmployeeData((*reinterpret_cast< std::add_pointer_t<EmployeeGrade>>(_a[1]))); break;
        case 3: _t->listSearch((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->queryData((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ViewerAppMain::*)(QString , int , int , int , int , int , int );
            if (_t _q_method = &ViewerAppMain::sigUpdateData; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *ViewerAppMain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ViewerAppMain::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ViewerAppMain.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ViewerAppMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ViewerAppMain::sigUpdateData(QString _t1, int _t2, int _t3, int _t4, int _t5, int _t6, int _t7)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
