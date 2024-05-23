/****************************************************************************
** Meta object code from reading C++ file 'main_window.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/irc_humanoid_sports23/vision_basketball_2023/include/vision_basketball_2023/main_window.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vision_basketball_2023__MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      36,   35,   35,   35, 0x0a,
      57,   48,   35,   35, 0x0a,
      81,   35,   35,   35, 0x0a,
      91,   35,   35,   35, 0x0a,
      99,   35,   35,   35, 0x0a,
     114,  110,  106,   35, 0x0a,
     152,  137,   35,   35, 0x0a,
     182,   35,   35,   35, 0x0a,
     203,   35,   35,   35, 0x0a,
     216,   35,   35,   35, 0x0a,
     240,   35,   35,   35, 0x0a,
     266,   35,   35,   35, 0x0a,
     292,   35,   35,   35, 0x0a,
     318,   35,   35,   35, 0x0a,
     344,   35,   35,   35, 0x0a,
     370,   35,   35,   35, 0x0a,
     396,   35,   35,   35, 0x0a,
     427,  419,   35,   35, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_vision_basketball_2023__MainWindow[] = {
    "vision_basketball_2023::MainWindow\0\0"
    "Print_Fps()\0img,info\0update(cv::Mat,cv::Mat)\0"
    "setting()\0panOp()\0Init()\0Mat\0img\0"
    "imgProcessing(cv::Mat)\0img,result_img\0"
    "Print_Screen(cv::Mat,cv::Mat)\0"
    "Print_local_Screen()\0publishMSG()\0"
    "on_saveButton_clicked()\0"
    "on_saveButton_0_clicked()\0"
    "on_saveButton_1_clicked()\0"
    "on_saveButton_2_clicked()\0"
    "on_saveButton_3_clicked()\0"
    "on_saveButton_4_clicked()\0"
    "on_saveButton_5_clicked()\0"
    "on_setButton_clicked()\0checked\0"
    "on_radioButton_clicked(bool)\0"
};

void vision_basketball_2023::MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->Print_Fps(); break;
        case 1: _t->update((*reinterpret_cast< const cv::Mat(*)>(_a[1])),(*reinterpret_cast< const cv::Mat(*)>(_a[2]))); break;
        case 2: _t->setting(); break;
        case 3: _t->panOp(); break;
        case 4: _t->Init(); break;
        case 5: { Mat _r = _t->imgProcessing((*reinterpret_cast< const cv::Mat(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< Mat*>(_a[0]) = _r; }  break;
        case 6: _t->Print_Screen((*reinterpret_cast< const cv::Mat(*)>(_a[1])),(*reinterpret_cast< const cv::Mat(*)>(_a[2]))); break;
        case 7: _t->Print_local_Screen(); break;
        case 8: _t->publishMSG(); break;
        case 9: _t->on_saveButton_clicked(); break;
        case 10: _t->on_saveButton_0_clicked(); break;
        case 11: _t->on_saveButton_1_clicked(); break;
        case 12: _t->on_saveButton_2_clicked(); break;
        case 13: _t->on_saveButton_3_clicked(); break;
        case 14: _t->on_saveButton_4_clicked(); break;
        case 15: _t->on_saveButton_5_clicked(); break;
        case 16: _t->on_setButton_clicked(); break;
        case 17: _t->on_radioButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData vision_basketball_2023::MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject vision_basketball_2023::MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_vision_basketball_2023__MainWindow,
      qt_meta_data_vision_basketball_2023__MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &vision_basketball_2023::MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *vision_basketball_2023::MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *vision_basketball_2023::MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vision_basketball_2023__MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int vision_basketball_2023::MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
