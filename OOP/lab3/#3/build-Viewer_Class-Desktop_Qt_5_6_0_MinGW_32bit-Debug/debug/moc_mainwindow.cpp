/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Viewer_Class/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[18];
    char stringdata0[254];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 23), // "on_actionHELP_triggered"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 23), // "on_actionFILE_triggered"
QT_MOC_LITERAL(4, 60, 9), // "readScale"
QT_MOC_LITERAL(5, 70, 9), // "readAngle"
QT_MOC_LITERAL(6, 80, 15), // "readCamDistance"
QT_MOC_LITERAL(7, 96, 12), // "QbuttClicked"
QT_MOC_LITERAL(8, 109, 12), // "EbuttClicked"
QT_MOC_LITERAL(9, 122, 12), // "WbuttClicked"
QT_MOC_LITERAL(10, 135, 12), // "SbuttClicked"
QT_MOC_LITERAL(11, 148, 12), // "AbuttClicked"
QT_MOC_LITERAL(12, 161, 12), // "DbuttClicked"
QT_MOC_LITERAL(13, 174, 15), // "PlusbuttClicked"
QT_MOC_LITERAL(14, 190, 16), // "MinusbuttClicked"
QT_MOC_LITERAL(15, 207, 13), // "keyPressEvent"
QT_MOC_LITERAL(16, 221, 10), // "QKeyEvent*"
QT_MOC_LITERAL(17, 232, 21) // "on_btn_addCam_clicked"

    },
    "MainWindow\0on_actionHELP_triggered\0\0"
    "on_actionFILE_triggered\0readScale\0"
    "readAngle\0readCamDistance\0QbuttClicked\0"
    "EbuttClicked\0WbuttClicked\0SbuttClicked\0"
    "AbuttClicked\0DbuttClicked\0PlusbuttClicked\0"
    "MinusbuttClicked\0keyPressEvent\0"
    "QKeyEvent*\0on_btn_addCam_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    0,   93,    2, 0x08 /* Private */,
       7,    0,   94,    2, 0x08 /* Private */,
       8,    0,   95,    2, 0x08 /* Private */,
       9,    0,   96,    2, 0x08 /* Private */,
      10,    0,   97,    2, 0x08 /* Private */,
      11,    0,   98,    2, 0x08 /* Private */,
      12,    0,   99,    2, 0x08 /* Private */,
      13,    0,  100,    2, 0x08 /* Private */,
      14,    0,  101,    2, 0x08 /* Private */,
      15,    1,  102,    2, 0x08 /* Private */,
      17,    0,  105,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Double,
    QMetaType::Double,
    QMetaType::Double,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,    2,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionHELP_triggered(); break;
        case 1: _t->on_actionFILE_triggered(); break;
        case 2: { double _r = _t->readScale();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 3: { double _r = _t->readAngle();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 4: { double _r = _t->readCamDistance();
            if (_a[0]) *reinterpret_cast< double*>(_a[0]) = _r; }  break;
        case 5: _t->QbuttClicked(); break;
        case 6: _t->EbuttClicked(); break;
        case 7: _t->WbuttClicked(); break;
        case 8: _t->SbuttClicked(); break;
        case 9: _t->AbuttClicked(); break;
        case 10: _t->DbuttClicked(); break;
        case 11: _t->PlusbuttClicked(); break;
        case 12: _t->MinusbuttClicked(); break;
        case 13: _t->keyPressEvent((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 14: _t->on_btn_addCam_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
