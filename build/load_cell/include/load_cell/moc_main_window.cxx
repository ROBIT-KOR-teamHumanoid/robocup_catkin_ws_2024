/****************************************************************************
** Meta object code from reading C++ file 'main_window.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/load_cell/include/load_cell/main_window.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_load_cell__MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   22,   22,   22, 0x0a,
      43,   22,   22,   22, 0x0a,
      54,   22,   22,   22, 0x0a,
     122,   66,   22,   22, 0x0a,
     184,  171,  162,   22, 0x0a,
     210,   22,   22,   22, 0x08,
     234,   22,   22,   22, 0x08,
     258,   22,   22,   22, 0x08,
     282,   22,   22,   22, 0x08,
     306,   22,   22,   22, 0x08,
     330,   22,   22,   22, 0x08,
     354,   22,   22,   22, 0x08,
     378,   22,   22,   22, 0x08,
     402,   22,   22,   22, 0x08,
     437,  432,   22,   22, 0x08,
     477,  432,   22,   22, 0x08,
     517,  432,   22,   22, 0x08,
     557,  432,   22,   22, 0x08,
     597,  432,   22,   22, 0x08,
     637,  432,   22,   22, 0x08,
     677,  432,   22,   22, 0x08,
     717,  432,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_load_cell__MainWindow[] = {
    "load_cell::MainWindow\0\0LoadCell_Callback()\0"
    "makePlot()\0Plot_init()\0"
    "data_1,data_2,data_3,data_4,data_5,data_6,data_7,data_8\0"
    "median(int,int,int,int,int,int,int,int)\0"
    "long int\0initial_data\0Low_pass_filter(long int)\0"
    "on_ZG_Push_00_clicked()\0on_ZG_Push_01_clicked()\0"
    "on_ZG_Push_02_clicked()\0on_ZG_Push_03_clicked()\0"
    "on_ZG_Push_04_clicked()\0on_ZG_Push_05_clicked()\0"
    "on_ZG_Push_06_clicked()\0on_ZG_Push_07_clicked()\0"
    "on_ZG_Insert_Button_clicked()\0arg1\0"
    "on_LC_Zero_Gain_00_textChanged(QString)\0"
    "on_LC_Zero_Gain_01_textChanged(QString)\0"
    "on_LC_Zero_Gain_02_textChanged(QString)\0"
    "on_LC_Zero_Gain_03_textChanged(QString)\0"
    "on_LC_Zero_Gain_04_textChanged(QString)\0"
    "on_LC_Zero_Gain_05_textChanged(QString)\0"
    "on_LC_Zero_Gain_06_textChanged(QString)\0"
    "on_LC_Zero_Gain_07_textChanged(QString)\0"
};

void load_cell::MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->LoadCell_Callback(); break;
        case 1: _t->makePlot(); break;
        case 2: _t->Plot_init(); break;
        case 3: _t->median((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< int(*)>(_a[8]))); break;
        case 4: { long int _r = _t->Low_pass_filter((*reinterpret_cast< long int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< long int*>(_a[0]) = _r; }  break;
        case 5: _t->on_ZG_Push_00_clicked(); break;
        case 6: _t->on_ZG_Push_01_clicked(); break;
        case 7: _t->on_ZG_Push_02_clicked(); break;
        case 8: _t->on_ZG_Push_03_clicked(); break;
        case 9: _t->on_ZG_Push_04_clicked(); break;
        case 10: _t->on_ZG_Push_05_clicked(); break;
        case 11: _t->on_ZG_Push_06_clicked(); break;
        case 12: _t->on_ZG_Push_07_clicked(); break;
        case 13: _t->on_ZG_Insert_Button_clicked(); break;
        case 14: _t->on_LC_Zero_Gain_00_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->on_LC_Zero_Gain_01_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->on_LC_Zero_Gain_02_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: _t->on_LC_Zero_Gain_03_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 18: _t->on_LC_Zero_Gain_04_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 19: _t->on_LC_Zero_Gain_05_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 20: _t->on_LC_Zero_Gain_06_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 21: _t->on_LC_Zero_Gain_07_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData load_cell::MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject load_cell::MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_load_cell__MainWindow,
      qt_meta_data_load_cell__MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &load_cell::MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *load_cell::MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *load_cell::MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_load_cell__MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int load_cell::MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
