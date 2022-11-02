/****************************************************************************
** Meta object code from reading C++ file 'editorappmain.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../editor/editorappmain.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'editorappmain.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EditorAppMain_t {
    QByteArrayData data[21];
    char stringdata0[208];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EditorAppMain_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EditorAppMain_t qt_meta_stringdata_EditorAppMain = {
    {
QT_MOC_LITERAL(0, 0, 13), // "EditorAppMain"
QT_MOC_LITERAL(1, 14, 13), // "sigUpdateData"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 4), // "name"
QT_MOC_LITERAL(4, 34, 10), // "assemScore"
QT_MOC_LITERAL(5, 45, 6), // "cScore"
QT_MOC_LITERAL(6, 52, 7), // "jsScore"
QT_MOC_LITERAL(7, 60, 8), // "qmlScore"
QT_MOC_LITERAL(8, 69, 11), // "openGlScore"
QT_MOC_LITERAL(9, 81, 2), // "id"
QT_MOC_LITERAL(10, 84, 14), // "sigListChanged"
QT_MOC_LITERAL(11, 99, 16), // "onSigDataChanged"
QT_MOC_LITERAL(12, 116, 3), // "num"
QT_MOC_LITERAL(13, 120, 17), // "onSigEmployeeData"
QT_MOC_LITERAL(14, 138, 13), // "EmployeeGrade"
QT_MOC_LITERAL(15, 152, 5), // "grade"
QT_MOC_LITERAL(16, 158, 10), // "listSearch"
QT_MOC_LITERAL(17, 169, 3), // "inp"
QT_MOC_LITERAL(18, 173, 9), // "queryData"
QT_MOC_LITERAL(19, 183, 15), // "requestFullList"
QT_MOC_LITERAL(20, 199, 8) // "editData"

    },
    "EditorAppMain\0sigUpdateData\0\0name\0"
    "assemScore\0cScore\0jsScore\0qmlScore\0"
    "openGlScore\0id\0sigListChanged\0"
    "onSigDataChanged\0num\0onSigEmployeeData\0"
    "EmployeeGrade\0grade\0listSearch\0inp\0"
    "queryData\0requestFullList\0editData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EditorAppMain[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    7,   54,    2, 0x06 /* Public */,
      10,    0,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,   70,    2, 0x08 /* Private */,
      13,    1,   73,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      16,    1,   76,    2, 0x02 /* Public */,
      18,    1,   79,    2, 0x02 /* Public */,
      19,    0,   82,    2, 0x02 /* Public */,
      20,    6,   83,    2, 0x02 /* Public */,

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

void EditorAppMain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EditorAppMain *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigUpdateData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7]))); break;
        case 1: _t->sigListChanged(); break;
        case 2: _t->onSigDataChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->onSigEmployeeData((*reinterpret_cast< EmployeeGrade(*)>(_a[1]))); break;
        case 4: _t->listSearch((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->queryData((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->requestFullList(); break;
        case 7: _t->editData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (EditorAppMain::*)(QString , int , int , int , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EditorAppMain::sigUpdateData)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (EditorAppMain::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&EditorAppMain::sigListChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject EditorAppMain::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_EditorAppMain.data,
    qt_meta_data_EditorAppMain,
    qt_static_metacall,
    nullptr,
    nullptr
} };


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
            *reinterpret_cast<int*>(_a[0]) = -1;
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
