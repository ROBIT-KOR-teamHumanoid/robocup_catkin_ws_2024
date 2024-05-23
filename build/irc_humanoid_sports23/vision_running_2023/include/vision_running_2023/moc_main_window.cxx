/****************************************************************************
** Meta object code from reading C++ file 'main_window.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../src/irc_humanoid_sports23/vision_running_2023/include/vision_running_2023/main_window.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_vision_running_2023__MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      42,   33,   32,   32, 0x0a,
      66,   32,   32,   32, 0x0a,
      78,   32,   32,   32, 0x0a,
     104,   32,   32,   32, 0x0a,
     130,   32,   32,   32, 0x0a,
     156,   32,   32,   32, 0x0a,
     182,   32,   32,   32, 0x0a,
     216,  208,   32,   32, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_vision_running_2023__MainWindow[] = {
    "vision_running_2023::MainWindow\0\0"
    "img,info\0update(cv::Mat,cv::Mat)\0"
    "Print_Fps()\0on_saveButton_1_clicked()\0"
    "on_saveButton_2_clicked()\0"
    "on_saveButton_3_clicked()\0"
    "on_saveButton_4_clicked()\0"
    "on_saveButton_5_clicked()\0checked\0"
    "on_radioButton_clicked(bool)\0"
};

void vision_running_2023::MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->update((*reinterpret_cast< const cv::Mat(*)>(_a[1])),(*reinterpret_cast< const cv::Mat(*)>(_a[2]))); break;
        case 1: _t->Print_Fps(); break;
        case 2: _t->on_saveButton_1_clicked(); break;
        case 3: _t->on_saveButton_2_clicked(); break;
        case 4: _t->on_saveButton_3_clicked(); break;
        case 5: _t->on_saveButton_4_clicked(); break;
        case 6: _t->on_saveButton_5_clicked(); break;
        case 7: _t->on_radioButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData vision_running_2023::MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject vision_running_2023::MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_vision_running_2023__MainWindow,
      qt_meta_data_vision_running_2023__MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &vision_running_2023::MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *vision_running_2023::MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *vision_running_2023::MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_vision_running_2023__MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int vision_running_2023::MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
