/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowDesign
{
public:
    QAction *action_Quit;
    QAction *action_Preferences;
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QWidget *centralwidget;
    QLabel *title;
    QGraphicsView *screen;
    QLabel *layout0;
    QLabel *label;
    QLabel *label_3;
    QLabel *subtitle0;
    QPushButton *btn_free_set;
    QLabel *BALL_X_value;
    QLabel *BALL_Y_value;
    QLabel *ROBOT_X_value;
    QLabel *ROBOT_Y_value;
    QLabel *IK_Y_value;
    QLabel *IK_X_value;
    QPushButton *btn_set_1;
    QPushButton *btn_set_2;
    QPushButton *btn_set_3;
    QLabel *label_4;
    QPushButton *btn_ball_set;
    QLabel *subtitle0_2;
    QLabel *label_5;
    QPushButton *btn_set_6;
    QPushButton *btn_set_4;
    QPushButton *btn_set_5;
    QPushButton *btn_test;
    QLabel *layout0_2;
    QLabel *subtitle0_3;
    QPushButton *btn_ball_del;
    QPushButton *btn_set_auto;
    QDoubleSpinBox *odom_ry_value;
    QLabel *label_13;
    QDoubleSpinBox *odom_fx_value;
    QLabel *label_10;
    QLabel *label_14;
    QLabel *label_9;
    QDoubleSpinBox *odom_bx_value;
    QDoubleSpinBox *odom_ly_value;
    QDoubleSpinBox *particle_range_value;
    QLabel *label_12;
    QPushButton *btn_objects_save;

    void setupUi(QMainWindow *MainWindowDesign)
    {
        if (MainWindowDesign->objectName().isEmpty())
            MainWindowDesign->setObjectName(QString::fromUtf8("MainWindowDesign"));
        MainWindowDesign->resize(871, 822);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindowDesign->setWindowIcon(icon);
        MainWindowDesign->setStyleSheet(QString::fromUtf8("background-color: rgb(30, 30, 30);\n"
"color: rgb(238, 238, 236);"));
        MainWindowDesign->setLocale(QLocale(QLocale::English, QLocale::Australia));
        action_Quit = new QAction(MainWindowDesign);
        action_Quit->setObjectName(QString::fromUtf8("action_Quit"));
        action_Quit->setShortcutContext(Qt::ApplicationShortcut);
        action_Preferences = new QAction(MainWindowDesign);
        action_Preferences->setObjectName(QString::fromUtf8("action_Preferences"));
        actionAbout = new QAction(MainWindowDesign);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAbout_Qt = new QAction(MainWindowDesign);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        centralwidget = new QWidget(MainWindowDesign);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        title = new QLabel(centralwidget);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(10, 0, 321, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font.setPointSize(25);
        font.setBold(true);
        font.setWeight(75);
        title->setFont(font);
        screen = new QGraphicsView(centralwidget);
        screen->setObjectName(QString::fromUtf8("screen"));
        screen->setGeometry(QRect(20, 60, 830, 600));
        screen->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        screen->setStyleSheet(QString::fromUtf8("background-color: rgb(241, 241, 241);"));
        screen->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        screen->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        layout0 = new QLabel(centralwidget);
        layout0->setObjectName(QString::fromUtf8("layout0"));
        layout0->setGeometry(QRect(10, 50, 851, 621));
        layout0->setFrameShape(QFrame::Box);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(750, 0, 111, 17));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu Mono"));
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        label->setFont(font1);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 670, 211, 141));
        label_3->setFrameShape(QFrame::Box);
        subtitle0 = new QLabel(centralwidget);
        subtitle0->setObjectName(QString::fromUtf8("subtitle0"));
        subtitle0->setGeometry(QRect(20, 680, 191, 25));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu Mono"));
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        subtitle0->setFont(font2);
        subtitle0->setFrameShape(QFrame::Box);
        subtitle0->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        btn_free_set = new QPushButton(centralwidget);
        btn_free_set->setObjectName(QString::fromUtf8("btn_free_set"));
        btn_free_set->setGeometry(QRect(20, 715, 41, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Ubuntu Mono"));
        font3.setBold(true);
        font3.setWeight(75);
        btn_free_set->setFont(font3);
        btn_free_set->setStyleSheet(QString::fromUtf8("border-image:url(\"/home/robit/catkin_ws/src/robocup_localization24_obstacle/resources/UI/btn_empty.png\");"));
        BALL_X_value = new QLabel(centralwidget);
        BALL_X_value->setObjectName(QString::fromUtf8("BALL_X_value"));
        BALL_X_value->setGeometry(QRect(30, 570, 171, 21));
        BALL_X_value->setFont(font3);
        BALL_X_value->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"color: rgb(0, 0, 0);"));
        BALL_Y_value = new QLabel(centralwidget);
        BALL_Y_value->setObjectName(QString::fromUtf8("BALL_Y_value"));
        BALL_Y_value->setGeometry(QRect(30, 590, 171, 21));
        BALL_Y_value->setFont(font3);
        BALL_Y_value->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"color: rgb(0, 0, 0);"));
        ROBOT_X_value = new QLabel(centralwidget);
        ROBOT_X_value->setObjectName(QString::fromUtf8("ROBOT_X_value"));
        ROBOT_X_value->setGeometry(QRect(30, 610, 171, 21));
        ROBOT_X_value->setFont(font3);
        ROBOT_X_value->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"color: rgb(0, 0, 0);"));
        ROBOT_Y_value = new QLabel(centralwidget);
        ROBOT_Y_value->setObjectName(QString::fromUtf8("ROBOT_Y_value"));
        ROBOT_Y_value->setGeometry(QRect(30, 630, 171, 21));
        ROBOT_Y_value->setFont(font3);
        ROBOT_Y_value->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"color: rgb(0, 0, 0);"));
        IK_Y_value = new QLabel(centralwidget);
        IK_Y_value->setObjectName(QString::fromUtf8("IK_Y_value"));
        IK_Y_value->setGeometry(QRect(670, 630, 171, 21));
        IK_Y_value->setFont(font3);
        IK_Y_value->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"color: rgb(0, 0, 0);"));
        IK_Y_value->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        IK_X_value = new QLabel(centralwidget);
        IK_X_value->setObjectName(QString::fromUtf8("IK_X_value"));
        IK_X_value->setGeometry(QRect(670, 610, 171, 21));
        IK_X_value->setFont(font3);
        IK_X_value->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"color: rgb(0, 0, 0);"));
        IK_X_value->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        btn_set_1 = new QPushButton(centralwidget);
        btn_set_1->setObjectName(QString::fromUtf8("btn_set_1"));
        btn_set_1->setGeometry(QRect(70, 715, 41, 41));
        btn_set_1->setFont(font3);
        btn_set_1->setStyleSheet(QString::fromUtf8("border-image:url(\"/home/robit/catkin_ws/src/robocup_localization24_obstacle/resources/UI/btn_empty.png\");"));
        btn_set_2 = new QPushButton(centralwidget);
        btn_set_2->setObjectName(QString::fromUtf8("btn_set_2"));
        btn_set_2->setGeometry(QRect(120, 715, 41, 41));
        btn_set_2->setFont(font3);
        btn_set_2->setStyleSheet(QString::fromUtf8("border-image:url(\"/home/robit/catkin_ws/src/robocup_localization24_obstacle/resources/UI/btn_empty.png\");"));
        btn_set_3 = new QPushButton(centralwidget);
        btn_set_3->setObjectName(QString::fromUtf8("btn_set_3"));
        btn_set_3->setGeometry(QRect(170, 715, 41, 41));
        btn_set_3->setFont(font3);
        btn_set_3->setStyleSheet(QString::fromUtf8("border-image:url(\"/home/robit/catkin_ws/src/robocup_localization24_obstacle/resources/UI/btn_empty.png\");"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(220, 670, 641, 141));
        label_4->setFrameShape(QFrame::Box);
        btn_ball_set = new QPushButton(centralwidget);
        btn_ball_set->setObjectName(QString::fromUtf8("btn_ball_set"));
        btn_ball_set->setGeometry(QRect(230, 715, 41, 41));
        btn_ball_set->setFont(font3);
        btn_ball_set->setStyleSheet(QString::fromUtf8("border-image:url(\"/home/robit/catkin_ws/src/robocup_localization24_obstacle/resources/UI/btn_empty.png\");"));
        subtitle0_2 = new QLabel(centralwidget);
        subtitle0_2->setObjectName(QString::fromUtf8("subtitle0_2"));
        subtitle0_2->setGeometry(QRect(230, 680, 191, 25));
        subtitle0_2->setFont(font2);
        subtitle0_2->setFrameShape(QFrame::Box);
        subtitle0_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(220, 670, 211, 141));
        label_5->setFrameShape(QFrame::Box);
        btn_set_6 = new QPushButton(centralwidget);
        btn_set_6->setObjectName(QString::fromUtf8("btn_set_6"));
        btn_set_6->setGeometry(QRect(170, 760, 41, 41));
        btn_set_6->setFont(font3);
        btn_set_6->setStyleSheet(QString::fromUtf8("border-image:url(\"/home/robit/catkin_ws/src/robocup_localization24_obstacle/resources/UI/btn_empty.png\");"));
        btn_set_4 = new QPushButton(centralwidget);
        btn_set_4->setObjectName(QString::fromUtf8("btn_set_4"));
        btn_set_4->setGeometry(QRect(70, 760, 41, 41));
        btn_set_4->setFont(font3);
        btn_set_4->setStyleSheet(QString::fromUtf8("border-image:url(\"/home/robit/catkin_ws/src/robocup_localization24_obstacle/resources/UI/btn_empty.png\");"));
        btn_set_5 = new QPushButton(centralwidget);
        btn_set_5->setObjectName(QString::fromUtf8("btn_set_5"));
        btn_set_5->setGeometry(QRect(120, 760, 41, 41));
        btn_set_5->setFont(font3);
        btn_set_5->setStyleSheet(QString::fromUtf8("border-image:url(\"/home/robit/catkin_ws/src/robocup_localization24_obstacle/resources/UI/btn_empty.png\");"));
        btn_test = new QPushButton(centralwidget);
        btn_test->setObjectName(QString::fromUtf8("btn_test"));
        btn_test->setGeometry(QRect(330, 715, 41, 41));
        btn_test->setFont(font3);
        btn_test->setStyleSheet(QString::fromUtf8("border-image:url(\"/home/robit/catkin_ws/src/robocup_localization24_obstacle/resources/UI/btn_empty.png\");"));
        layout0_2 = new QLabel(centralwidget);
        layout0_2->setObjectName(QString::fromUtf8("layout0_2"));
        layout0_2->setGeometry(QRect(10, 50, 851, 621));
        layout0_2->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);"));
        layout0_2->setFrameShape(QFrame::Box);
        subtitle0_3 = new QLabel(centralwidget);
        subtitle0_3->setObjectName(QString::fromUtf8("subtitle0_3"));
        subtitle0_3->setGeometry(QRect(440, 680, 411, 25));
        subtitle0_3->setFont(font2);
        subtitle0_3->setFrameShape(QFrame::Box);
        subtitle0_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        btn_ball_del = new QPushButton(centralwidget);
        btn_ball_del->setObjectName(QString::fromUtf8("btn_ball_del"));
        btn_ball_del->setGeometry(QRect(280, 715, 41, 41));
        btn_ball_del->setFont(font3);
        btn_ball_del->setStyleSheet(QString::fromUtf8("border-image:url(\"/home/robit/catkin_ws/src/robocup_localization24_obstacle/resources/UI/btn_empty.png\");"));
        btn_set_auto = new QPushButton(centralwidget);
        btn_set_auto->setObjectName(QString::fromUtf8("btn_set_auto"));
        btn_set_auto->setGeometry(QRect(20, 760, 41, 41));
        btn_set_auto->setFont(font3);
        btn_set_auto->setStyleSheet(QString::fromUtf8("border-image:url(\"/home/robit/catkin_ws/src/robocup_localization24_obstacle/resources/UI/btn_empty.png\");"));
        odom_ry_value = new QDoubleSpinBox(centralwidget);
        odom_ry_value->setObjectName(QString::fromUtf8("odom_ry_value"));
        odom_ry_value->setGeometry(QRect(490, 780, 151, 21));
        odom_ry_value->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(46, 52, 54);"));
        odom_ry_value->setDecimals(2);
        odom_ry_value->setSingleStep(0.01);
        odom_ry_value->setValue(0);
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(440, 735, 31, 20));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Ubuntu Mono"));
        font4.setPointSize(10);
        font4.setBold(true);
        font4.setWeight(75);
        label_13->setFont(font4);
        odom_fx_value = new QDoubleSpinBox(centralwidget);
        odom_fx_value->setObjectName(QString::fromUtf8("odom_fx_value"));
        odom_fx_value->setGeometry(QRect(490, 715, 151, 20));
        odom_fx_value->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(46, 52, 54);"));
        odom_fx_value->setDecimals(2);
        odom_fx_value->setSingleStep(0.01);
        odom_fx_value->setValue(0);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(440, 760, 31, 20));
        label_10->setFont(font4);
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(440, 780, 31, 20));
        label_14->setFont(font4);
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(440, 715, 31, 20));
        label_9->setFont(font4);
        odom_bx_value = new QDoubleSpinBox(centralwidget);
        odom_bx_value->setObjectName(QString::fromUtf8("odom_bx_value"));
        odom_bx_value->setGeometry(QRect(490, 735, 151, 20));
        odom_bx_value->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(46, 52, 54);"));
        odom_bx_value->setDecimals(2);
        odom_bx_value->setSingleStep(0.01);
        odom_bx_value->setValue(0);
        odom_ly_value = new QDoubleSpinBox(centralwidget);
        odom_ly_value->setObjectName(QString::fromUtf8("odom_ly_value"));
        odom_ly_value->setGeometry(QRect(490, 760, 151, 21));
        odom_ly_value->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(46, 52, 54);"));
        odom_ly_value->setDecimals(2);
        odom_ly_value->setSingleStep(0.01);
        odom_ly_value->setValue(0);
        particle_range_value = new QDoubleSpinBox(centralwidget);
        particle_range_value->setObjectName(QString::fromUtf8("particle_range_value"));
        particle_range_value->setGeometry(QRect(700, 715, 151, 20));
        particle_range_value->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(46, 52, 54);"));
        particle_range_value->setDecimals(0);
        particle_range_value->setMaximum(150);
        particle_range_value->setSingleStep(1);
        particle_range_value->setValue(0);
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(650, 715, 41, 20));
        label_12->setFont(font4);
        btn_objects_save = new QPushButton(centralwidget);
        btn_objects_save->setObjectName(QString::fromUtf8("btn_objects_save"));
        btn_objects_save->setGeometry(QRect(810, 760, 41, 41));
        btn_objects_save->setFont(font3);
        btn_objects_save->setStyleSheet(QString::fromUtf8("border-image:url(\"/home/robit/catkin_ws/src/robocup_localization24_obstacle/resources/UI/btn_save_save.png\");"));
        MainWindowDesign->setCentralWidget(centralwidget);
        label_4->raise();
        label_5->raise();
        layout0->raise();
        title->raise();
        screen->raise();
        label->raise();
        label_3->raise();
        subtitle0->raise();
        btn_free_set->raise();
        BALL_X_value->raise();
        BALL_Y_value->raise();
        ROBOT_X_value->raise();
        ROBOT_Y_value->raise();
        IK_Y_value->raise();
        IK_X_value->raise();
        btn_set_1->raise();
        btn_set_2->raise();
        btn_set_3->raise();
        btn_ball_set->raise();
        subtitle0_2->raise();
        btn_set_6->raise();
        btn_set_4->raise();
        btn_set_5->raise();
        btn_test->raise();
        layout0_2->raise();
        subtitle0_3->raise();
        btn_ball_del->raise();
        btn_set_auto->raise();
        odom_ry_value->raise();
        label_13->raise();
        odom_fx_value->raise();
        label_10->raise();
        label_14->raise();
        label_9->raise();
        odom_bx_value->raise();
        odom_ly_value->raise();
        particle_range_value->raise();
        label_12->raise();
        btn_objects_save->raise();

        retranslateUi(MainWindowDesign);
        QObject::connect(action_Quit, SIGNAL(triggered()), MainWindowDesign, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindowDesign);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowDesign)
    {
        MainWindowDesign->setWindowTitle(QApplication::translate("MainWindowDesign", "robocup_localization24_obstacle", 0, QApplication::UnicodeUTF8));
        action_Quit->setText(QApplication::translate("MainWindowDesign", "&Quit", 0, QApplication::UnicodeUTF8));
        action_Quit->setShortcut(QApplication::translate("MainWindowDesign", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        action_Preferences->setText(QApplication::translate("MainWindowDesign", "&Preferences", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindowDesign", "&About", 0, QApplication::UnicodeUTF8));
        actionAbout_Qt->setText(QApplication::translate("MainWindowDesign", "About &Qt", 0, QApplication::UnicodeUTF8));
        title->setText(QApplication::translate("MainWindowDesign", "robocup_localization24_obstacle", 0, QApplication::UnicodeUTF8));
        layout0->setText(QString());
        label->setText(QApplication::translate("MainWindowDesign", "VERSION 8.0", 0, QApplication::UnicodeUTF8));
        label_3->setText(QString());
        subtitle0->setText(QApplication::translate("MainWindowDesign", " SET ROBOT", 0, QApplication::UnicodeUTF8));
        btn_free_set->setText(QApplication::translate("MainWindowDesign", "FREE", 0, QApplication::UnicodeUTF8));
        BALL_X_value->setText(QApplication::translate("MainWindowDesign", "BALL_X : 00", 0, QApplication::UnicodeUTF8));
        BALL_Y_value->setText(QApplication::translate("MainWindowDesign", "BALL_Y : 00", 0, QApplication::UnicodeUTF8));
        ROBOT_X_value->setText(QApplication::translate("MainWindowDesign", "ROBOT_X : 00", 0, QApplication::UnicodeUTF8));
        ROBOT_Y_value->setText(QApplication::translate("MainWindowDesign", "ROBOT_Y : 00", 0, QApplication::UnicodeUTF8));
        IK_Y_value->setText(QApplication::translate("MainWindowDesign", "IK_Y : 00", 0, QApplication::UnicodeUTF8));
        IK_X_value->setText(QApplication::translate("MainWindowDesign", "IK_X : 00", 0, QApplication::UnicodeUTF8));
        btn_set_1->setText(QApplication::translate("MainWindowDesign", "A", 0, QApplication::UnicodeUTF8));
        btn_set_2->setText(QApplication::translate("MainWindowDesign", "B", 0, QApplication::UnicodeUTF8));
        btn_set_3->setText(QApplication::translate("MainWindowDesign", "C", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
        btn_ball_set->setText(QApplication::translate("MainWindowDesign", "SET", 0, QApplication::UnicodeUTF8));
        subtitle0_2->setText(QApplication::translate("MainWindowDesign", " SET BALL", 0, QApplication::UnicodeUTF8));
        label_5->setText(QString());
        btn_set_6->setText(QApplication::translate("MainWindowDesign", "F", 0, QApplication::UnicodeUTF8));
        btn_set_4->setText(QApplication::translate("MainWindowDesign", "D", 0, QApplication::UnicodeUTF8));
        btn_set_5->setText(QApplication::translate("MainWindowDesign", "E", 0, QApplication::UnicodeUTF8));
        btn_test->setText(QApplication::translate("MainWindowDesign", "CLS", 0, QApplication::UnicodeUTF8));
        layout0_2->setText(QString());
        subtitle0_3->setText(QApplication::translate("MainWindowDesign", " OBJECTS", 0, QApplication::UnicodeUTF8));
        btn_ball_del->setText(QApplication::translate("MainWindowDesign", "DEL", 0, QApplication::UnicodeUTF8));
        btn_set_auto->setText(QApplication::translate("MainWindowDesign", "AUTO", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindowDesign", " B_x", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindowDesign", " L_y", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindowDesign", " R_y", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindowDesign", " F_x", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindowDesign", " range", 0, QApplication::UnicodeUTF8));
        btn_objects_save->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindowDesign: public Ui_MainWindowDesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
