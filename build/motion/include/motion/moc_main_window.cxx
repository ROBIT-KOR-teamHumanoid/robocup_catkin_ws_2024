/****************************************************************************
** Meta object code from reading C++ file 'main_window.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/motion/include/motion/main_window.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_motion__MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   19,   20,   19, 0x0a,
      31,   19,   19,   19, 0x0a,
      55,   19,   19,   19, 0x0a,
      78,   19,   19,   19, 0x0a,
     101,   19,   19,   19, 0x0a,
     122,   19,   19,   19, 0x0a,
     145,   19,   19,   19, 0x0a,
     173,   19,   19,   19, 0x0a,
     199,   19,   19,   19, 0x0a,
     225,   19,   19,   19, 0x0a,
     250,   19,   19,   19, 0x0a,
     275,   19,   19,   19, 0x0a,
     298,   19,   19,   19, 0x0a,
     323,   19,   19,   19, 0x0a,
     353,   19,   19,   19, 0x0a,
     387,  381,   19,   19, 0x0a,
     418,   19,   19,   19, 0x0a,
     443,   19,   19,   19, 0x0a,
     468,   19,   19,   19, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_motion__MainWindow[] = {
    "motion::MainWindow\0\0int\0main()\0"
    "on_init_reset_clicked()\0on_init_save_clicked()\0"
    "on_init_down_clicked()\0on_init_up_clicked()\0"
    "on_init_read_clicked()\0"
    "on_init_down_side_clicked()\0"
    "on_init_up_side_clicked()\0"
    "on_offset_reset_clicked()\0"
    "on_offset_save_clicked()\0"
    "on_offset_down_clicked()\0"
    "on_offset_up_clicked()\0on_offset_read_clicked()\0"
    "on_offset_down_side_clicked()\0"
    "on_offset_up_side_clicked()\0index\0"
    "on_toolBox_currentChanged(int)\0"
    "on_ready_swing_clicked()\0"
    "on_motion_test_clicked()\0"
    "on_load_cell_clicked()\0"
};

void motion::MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: { int _r = _t->main();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 1: _t->on_init_reset_clicked(); break;
        case 2: _t->on_init_save_clicked(); break;
        case 3: _t->on_init_down_clicked(); break;
        case 4: _t->on_init_up_clicked(); break;
        case 5: _t->on_init_read_clicked(); break;
        case 6: _t->on_init_down_side_clicked(); break;
        case 7: _t->on_init_up_side_clicked(); break;
        case 8: _t->on_offset_reset_clicked(); break;
        case 9: _t->on_offset_save_clicked(); break;
        case 10: _t->on_offset_down_clicked(); break;
        case 11: _t->on_offset_up_clicked(); break;
        case 12: _t->on_offset_read_clicked(); break;
        case 13: _t->on_offset_down_side_clicked(); break;
        case 14: _t->on_offset_up_side_clicked(); break;
        case 15: _t->on_toolBox_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->on_ready_swing_clicked(); break;
        case 17: _t->on_motion_test_clicked(); break;
        case 18: _t->on_load_cell_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData motion::MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject motion::MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_motion__MainWindow,
      qt_meta_data_motion__MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &motion::MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *motion::MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *motion::MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_motion__MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int motion::MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
