/****************************************************************************
** Meta object code from reading C++ file 'main_window.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/robocup_localization24/include/robocup_localization24/main_window.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_robocup_localization24__MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      36,   35,   35,   35, 0x0a,
      45,   43,   35,   35, 0x0a,
      77,   43,   35,   35, 0x0a,
     106,   35,   35,   35, 0x0a,
     132,   35,   35,   35, 0x0a,
     162,   35,   35,   35, 0x0a,
     184,   35,   35,   35, 0x0a,
     207,   35,   35,   35, 0x0a,
     230,   35,   35,   35, 0x0a,
     253,   35,   35,   35, 0x0a,
     276,   35,   35,   35, 0x0a,
     299,   35,   35,   35, 0x0a,
     322,   35,   35,   35, 0x0a,
     348,   35,   35,   35, 0x0a,
     374,   35,   35,   35, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_robocup_localization24__MainWindow[] = {
    "robocup_localization24::MainWindow\0\0"
    "main()\0e\0mouseReleaseEvent(QMouseEvent*)\0"
    "mouseMoveEvent(QMouseEvent*)\0"
    "on_btn_free_set_clicked()\0"
    "on_btn_objects_save_clicked()\0"
    "on_btn_test_clicked()\0on_btn_set_1_clicked()\0"
    "on_btn_set_2_clicked()\0on_btn_set_3_clicked()\0"
    "on_btn_set_4_clicked()\0on_btn_set_5_clicked()\0"
    "on_btn_set_6_clicked()\0on_btn_set_auto_clicked()\0"
    "on_btn_ball_set_clicked()\0"
    "on_btn_ball_del_clicked()\0"
};

void robocup_localization24::MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->main(); break;
        case 1: _t->mouseReleaseEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 2: _t->mouseMoveEvent((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 3: _t->on_btn_free_set_clicked(); break;
        case 4: _t->on_btn_objects_save_clicked(); break;
        case 5: _t->on_btn_test_clicked(); break;
        case 6: _t->on_btn_set_1_clicked(); break;
        case 7: _t->on_btn_set_2_clicked(); break;
        case 8: _t->on_btn_set_3_clicked(); break;
        case 9: _t->on_btn_set_4_clicked(); break;
        case 10: _t->on_btn_set_5_clicked(); break;
        case 11: _t->on_btn_set_6_clicked(); break;
        case 12: _t->on_btn_set_auto_clicked(); break;
        case 13: _t->on_btn_ball_set_clicked(); break;
        case 14: _t->on_btn_ball_del_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData robocup_localization24::MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject robocup_localization24::MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_robocup_localization24__MainWindow,
      qt_meta_data_robocup_localization24__MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &robocup_localization24::MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *robocup_localization24::MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *robocup_localization24::MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_robocup_localization24__MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int robocup_localization24::MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
