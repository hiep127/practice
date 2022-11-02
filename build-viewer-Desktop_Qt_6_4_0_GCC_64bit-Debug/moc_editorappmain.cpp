/****************************************************************************
** Meta object code from reading C++ file 'editorappmain.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../editor/editorappmain.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editorappmain.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_EditorAppMain_t {
    uint offsetsAndSizes[42];
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
    char stringdata10[15];
    char stringdata11[17];
    char stringdata12[4];
    char stringdata13[18];
    char stringdata14[14];
    char stringdata15[6];
    char stringdata16[11];
    char stringdata17[4];
    char stringdata18[10];
    char stringdata19[16];
    char stringdata20[9];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_EditorAppMain_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_EditorAppMain_t qt_meta_stringdata_EditorAppMain = {
    {
        QT_MOC_LITERAL(0, 13),  // "EditorAppMain"
        QT_MOC_LITERAL(14, 13),  // "sigUpdateData"
        QT_MOC_LITERAL(28, 0),  // ""
        QT_MOC_LITERAL(29, 4),  // "name"
        QT_MOC_LITERAL(34, 10),  // "assemScore"
        QT_MOC_LITERAL(45, 6),  // "cScore"
        QT_MOC_LITERAL(52, 7),  // "jsScore"
        QT_MOC_LITERAL(60, 8),  // "qmlScore"
        QT_MOC_LITERAL(69, 11),  // "openGlScore"
        QT_MOC_LITERAL(81, 2),  // "id"
        QT_MOC_LITERAL(84, 14),  // "sigListChanged"
        QT_MOC_LITERAL(99, 16),  // "onSigDataChanged"
        QT_MOC_LITERAL(116, 3),  // "num"
        QT_MOC_LITERAL(120, 17),  // "onSigEmployeeData"
        QT_MOC_LITERAL(138, 13),  // "EmployeeGrade"
        QT_MOC_LITERAL(152, 5),  // "grade"
        QT_MOC_LITERAL(158, 10),  // "listSearch"
        QT_MOC_LITERAL(169, 3),  // "inp"
        QT_MOC_LITERAL(173, 9),  // "queryData"
        QT_MOC_LITERAL(183, 15),  // "requestFullList"
        QT_MOC_LITERAL(199, 8)   // "editData"
    },
    "EditorAppMain",
    "sigUpdateData",
    "",
    "name",
    "assemScore",
    "cScore",
    "jsScore",
    "qmlScore",
    "openGlScore",
    "id",
    "sigListChanged",
    "onSigDataChanged",
    "num",
    "onSigEmployeeData",
    "EmployeeGrade",
    "grade",
    "listSearch",
    "inp",
    "queryData",
    "requestFullList",
    "editData"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_EditorAppMain[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    7,   62,    2, 0x06,    1 /* Public */,
      10,    0,   77,    2, 0x06,    9 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    1,   78,    2, 0x08,   10 /* Private */,
      13,    1,   81,    2, 0x08,   12 /* Private */,

 // methods: name, argc, parameters, tag, flags, initial metatype offsets
      16,    1,   84,    2, 0x02,   14 /* Public */,
      18,    1,   87,    2, 0x02,   16 /* Public */,
      19,    0,   90,    2, 0x02,   18 /* Public */,
      20,    6,   91,    2, 0x02,   19 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,    6,    7,    8,    9,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, 0x80000000 | 14,   15,

 // methods: parameters
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    9,    4,    5,    6,    7,    8,

       0        // eod
};

Q_CONSTINIT const QMetaObject EditorAppMain::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_EditorAppMain.offsetsAndSizes,
    qt_meta_data_EditorAppMain,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_EditorAppMain_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<EditorAppMain, std::true_type>,
        // method 'sigUpdateData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'sigListChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSigDataChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'onSigEmployeeData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<EmployeeGrade, std::false_type>,
        // method 'listSearch'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'queryData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'requestFullList'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'editData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void EditorAppMain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EditorAppMain *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sigUpdateData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[7]))); break;
        case 1: _t->sigListChanged(); break;
        case 2: _t->onSigDataChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->onSigEmployeeData((*reinterpret_cast< std::add_pointer_t<EmployeeGrade>>(_a[1]))); break;
        case 4: _t->listSearch((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->queryData((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->requestFullList(); break;
        case 7: _t->editData((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[3])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[4])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[5])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[6]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (EditorAppMain::*)(QString , int , int , int , int , int , int );
            if (_t _q_method = &EditorAppMain::sigUpdateData; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (EditorAppMain::*)();
            if (_t _q_method = &EditorAppMain::sigListChanged; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *EditorAppMain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EditorAppMain::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EditorAppMain.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int EditorAppMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void EditorAppMain::sigUpdateData(QString _t1, int _t2, int _t3, int _t4, int _t5, int _t6, int _t7)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t5))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t6))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t7))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void EditorAppMain::sigListChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
