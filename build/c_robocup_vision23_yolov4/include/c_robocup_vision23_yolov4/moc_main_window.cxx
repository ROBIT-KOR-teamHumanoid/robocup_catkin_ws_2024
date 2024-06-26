/****************************************************************************
** Meta object code from reading C++ file 'main_window.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/c_robocup_vision23_yolov4/include/c_robocup_vision23_yolov4/main_window.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_c_robocup_vision23_yolov4__MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      39,   38,   38,   38, 0x0a,
      63,   54,   38,   38, 0x0a,
      95,   87,   38,   38, 0x0a,
     121,   87,   38,   38, 0x0a,
     149,   87,   38,   38, 0x0a,
     176,   87,   38,   38, 0x0a,
     211,   38,   38,   38, 0x0a,
     235,   38,   38,   38, 0x0a,
     259,   38,   38,   38, 0x0a,
     283,   38,   38,   38, 0x0a,
     307,   38,   38,   38, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_c_robocup_vision23_yolov4__MainWindow[] = {
    "c_robocup_vision23_yolov4::MainWindow\0"
    "\0filter_100ms()\0img,info\0"
    "update(cv::Mat,cv::Mat)\0checked\0"
    "on_radioori_clicked(bool)\0"
    "on_radiofield_clicked(bool)\0"
    "on_radioline_clicked(bool)\0"
    "on_btn_oper_pan_tilt_clicked(bool)\0"
    "on_btn_mode_0_clicked()\0on_btn_mode_1_clicked()\0"
    "on_btn_mode_2_clicked()\0on_btn_mode_3_clicked()\0"
    "auto_save()\0"
};

void c_robocup_vision23_yolov4::MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->filter_100ms(); break;
        case 1: _t->update((*reinterpret_cast< const cv::Mat(*)>(_a[1])),(*reinterpret_cast< const cv::Mat(*)>(_a[2]))); break;
        case 2: _t->on_radioori_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_radiofield_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_radioline_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_btn_oper_pan_tilt_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_btn_mode_0_clicked(); break;
        case 7: _t->on_btn_mode_1_clicked(); break;
        case 8: _t->on_btn_mode_2_clicked(); break;
        case 9: _t->on_btn_mode_3_clicked(); break;
        case 10: _t->auto_save(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData c_robocup_vision23_yolov4::MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject c_robocup_vision23_yolov4::MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_c_robocup_vision23_yolov4__MainWindow,
      qt_meta_data_c_robocup_vision23_yolov4__MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &c_robocup_vision23_yolov4::MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *c_robocup_vision23_yolov4::MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *c_robocup_vision23_yolov4::MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_c_robocup_vision23_yolov4__MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int c_robocup_vision23_yolov4::MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
