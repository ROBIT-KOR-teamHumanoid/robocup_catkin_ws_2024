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
#include <QtGui/QCheckBox>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QScrollBar>
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
    QLabel *layout0;
    QGraphicsView *screen;
    QScrollBar *PAN_Scroll;
    QLabel *label;
    QLabel *subtitle0;
    QLabel *label_3;
    QLabel *PAN_Value;
    QCheckBox *btn_oper_pan_tilt;
    QLabel *SCANMODE_value;
    QLabel *title_2;
    QLabel *FPS_value;
    QLabel *label_4;
    QLabel *subtitle0_3;
    QPushButton *btn_mode_0;
    QPushButton *btn_mode_1;
    QPushButton *btn_mode_2;
    QLabel *TARGET_DIS_value;
    QLabel *TARGET_Y_value;
    QLabel *TARGET_X_value;
    QLabel *TARGET_CY_value;
    QLabel *TARGET_CX_value;
    QPushButton *btn_mode_3;
    QLabel *ROBOT_DIS_value;
    QLabel *ROBOT_X_value;
    QLabel *ROBOT_X_value_2;

    void setupUi(QMainWindow *MainWindowDesign)
    {
        if (MainWindowDesign->objectName().isEmpty())
            MainWindowDesign->setObjectName(QString::fromUtf8("MainWindowDesign"));
        MainWindowDesign->resize(700, 671);
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
        title->setGeometry(QRect(10, 0, 251, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font.setPointSize(25);
        font.setBold(true);
        font.setWeight(75);
        title->setFont(font);
        layout0 = new QLabel(centralwidget);
        layout0->setObjectName(QString::fromUtf8("layout0"));
        layout0->setGeometry(QRect(10, 50, 681, 521));
        layout0->setFrameShape(QFrame::Box);
        screen = new QGraphicsView(centralwidget);
        screen->setObjectName(QString::fromUtf8("screen"));
        screen->setGeometry(QRect(20, 60, 661, 501));
        screen->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        PAN_Scroll = new QScrollBar(centralwidget);
        PAN_Scroll->setObjectName(QString::fromUtf8("PAN_Scroll"));
        PAN_Scroll->setGeometry(QRect(60, 620, 160, 16));
        PAN_Scroll->setMinimum(-150);
        PAN_Scroll->setMaximum(150);
        PAN_Scroll->setOrientation(Qt::Horizontal);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(580, 0, 111, 17));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Ubuntu Mono"));
        font1.setBold(true);
        font1.setItalic(false);
        font1.setWeight(75);
        label->setFont(font1);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        subtitle0 = new QLabel(centralwidget);
        subtitle0->setObjectName(QString::fromUtf8("subtitle0"));
        subtitle0->setGeometry(QRect(20, 580, 201, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        subtitle0->setFont(font2);
        subtitle0->setFrameShape(QFrame::Box);
        subtitle0->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 570, 221, 91));
        label_3->setFrameShape(QFrame::Box);
        PAN_Value = new QLabel(centralwidget);
        PAN_Value->setObjectName(QString::fromUtf8("PAN_Value"));
        PAN_Value->setGeometry(QRect(20, 620, 31, 16));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font3.setPointSize(9);
        font3.setBold(true);
        font3.setWeight(75);
        PAN_Value->setFont(font3);
        PAN_Value->setFrameShape(QFrame::Box);
        PAN_Value->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        btn_oper_pan_tilt = new QCheckBox(centralwidget);
        btn_oper_pan_tilt->setObjectName(QString::fromUtf8("btn_oper_pan_tilt"));
        btn_oper_pan_tilt->setGeometry(QRect(90, 580, 131, 20));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Ubuntu Mono"));
        font4.setBold(true);
        font4.setWeight(75);
        btn_oper_pan_tilt->setFont(font4);
        btn_oper_pan_tilt->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);"));
        SCANMODE_value = new QLabel(centralwidget);
        SCANMODE_value->setObjectName(QString::fromUtf8("SCANMODE_value"));
        SCANMODE_value->setGeometry(QRect(40, 70, 171, 21));
        SCANMODE_value->setFont(font4);
        SCANMODE_value->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"color: rgb(238, 238, 236);"));
        title_2 = new QLabel(centralwidget);
        title_2->setObjectName(QString::fromUtf8("title_2"));
        title_2->setGeometry(QRect(240, 0, 121, 41));
        title_2->setFont(font);
        title_2->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"color: rgb(225, 134, 0);"));
        FPS_value = new QLabel(centralwidget);
        FPS_value->setObjectName(QString::fromUtf8("FPS_value"));
        FPS_value->setGeometry(QRect(490, 70, 171, 21));
        FPS_value->setFont(font4);
        FPS_value->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"color: rgb(238, 238, 236);"));
        FPS_value->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(230, 570, 461, 91));
        label_4->setFrameShape(QFrame::Box);
        subtitle0_3 = new QLabel(centralwidget);
        subtitle0_3->setObjectName(QString::fromUtf8("subtitle0_3"));
        subtitle0_3->setGeometry(QRect(240, 580, 441, 21));
        subtitle0_3->setFont(font2);
        subtitle0_3->setFrameShape(QFrame::Box);
        subtitle0_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        btn_mode_0 = new QPushButton(centralwidget);
        btn_mode_0->setObjectName(QString::fromUtf8("btn_mode_0"));
        btn_mode_0->setGeometry(QRect(240, 610, 41, 41));
        btn_mode_0->setFont(font4);
        btn_mode_0->setStyleSheet(QString::fromUtf8("border-image:url(\"/home/robit/catkin_ws/src/robocup_vision23_yolov4/resources/UI/btn_empty.png\");"));
        btn_mode_1 = new QPushButton(centralwidget);
        btn_mode_1->setObjectName(QString::fromUtf8("btn_mode_1"));
        btn_mode_1->setGeometry(QRect(290, 610, 41, 41));
        btn_mode_1->setFont(font4);
        btn_mode_1->setStyleSheet(QString::fromUtf8("border-image:url(\"/home/robit/catkin_ws/src/robocup_vision23_yolov4/resources/UI/btn_empty.png\");"));
        btn_mode_2 = new QPushButton(centralwidget);
        btn_mode_2->setObjectName(QString::fromUtf8("btn_mode_2"));
        btn_mode_2->setGeometry(QRect(340, 610, 41, 41));
        btn_mode_2->setFont(font4);
        btn_mode_2->setStyleSheet(QString::fromUtf8("border-image:url(\"/home/robit/catkin_ws/src/robocup_vision23_yolov4/resources/UI/btn_empty.png\");"));
        TARGET_DIS_value = new QLabel(centralwidget);
        TARGET_DIS_value->setObjectName(QString::fromUtf8("TARGET_DIS_value"));
        TARGET_DIS_value->setGeometry(QRect(40, 530, 261, 21));
        TARGET_DIS_value->setFont(font4);
        TARGET_DIS_value->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"color: rgb(238, 238, 236);"));
        TARGET_Y_value = new QLabel(centralwidget);
        TARGET_Y_value->setObjectName(QString::fromUtf8("TARGET_Y_value"));
        TARGET_Y_value->setGeometry(QRect(40, 470, 261, 21));
        TARGET_Y_value->setFont(font4);
        TARGET_Y_value->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"color: rgb(238, 238, 236);"));
        TARGET_X_value = new QLabel(centralwidget);
        TARGET_X_value->setObjectName(QString::fromUtf8("TARGET_X_value"));
        TARGET_X_value->setGeometry(QRect(40, 450, 261, 21));
        TARGET_X_value->setFont(font4);
        TARGET_X_value->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"color: rgb(238, 238, 236);"));
        TARGET_CY_value = new QLabel(centralwidget);
        TARGET_CY_value->setObjectName(QString::fromUtf8("TARGET_CY_value"));
        TARGET_CY_value->setGeometry(QRect(40, 510, 261, 21));
        TARGET_CY_value->setFont(font4);
        TARGET_CY_value->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"color: rgb(238, 238, 236);"));
        TARGET_CX_value = new QLabel(centralwidget);
        TARGET_CX_value->setObjectName(QString::fromUtf8("TARGET_CX_value"));
        TARGET_CX_value->setGeometry(QRect(40, 490, 261, 21));
        TARGET_CX_value->setFont(font4);
        TARGET_CX_value->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"color: rgb(238, 238, 236);"));
        btn_mode_3 = new QPushButton(centralwidget);
        btn_mode_3->setObjectName(QString::fromUtf8("btn_mode_3"));
        btn_mode_3->setGeometry(QRect(390, 610, 41, 41));
        btn_mode_3->setFont(font4);
        btn_mode_3->setStyleSheet(QString::fromUtf8("border-image:url(\"/home/robit/catkin_ws/src/robocup_vision23_yolov4/resources/UI/btn_empty.png\");"));
        ROBOT_DIS_value = new QLabel(centralwidget);
        ROBOT_DIS_value->setObjectName(QString::fromUtf8("ROBOT_DIS_value"));
        ROBOT_DIS_value->setGeometry(QRect(40, 380, 261, 21));
        ROBOT_DIS_value->setFont(font4);
        ROBOT_DIS_value->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"color: rgb(238, 238, 236);"));
        ROBOT_X_value = new QLabel(centralwidget);
        ROBOT_X_value->setObjectName(QString::fromUtf8("ROBOT_X_value"));
        ROBOT_X_value->setGeometry(QRect(40, 400, 261, 21));
        ROBOT_X_value->setFont(font4);
        ROBOT_X_value->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"color: rgb(238, 238, 236);"));
        ROBOT_X_value_2 = new QLabel(centralwidget);
        ROBOT_X_value_2->setObjectName(QString::fromUtf8("ROBOT_X_value_2"));
        ROBOT_X_value_2->setGeometry(QRect(40, 420, 261, 21));
        ROBOT_X_value_2->setFont(font4);
        ROBOT_X_value_2->setStyleSheet(QString::fromUtf8("background-color: rgba(191, 64, 64, 0);\n"
"color: rgb(238, 238, 236);"));
        MainWindowDesign->setCentralWidget(centralwidget);
        label_3->raise();
        title->raise();
        layout0->raise();
        screen->raise();
        PAN_Scroll->raise();
        label->raise();
        subtitle0->raise();
        PAN_Value->raise();
        btn_oper_pan_tilt->raise();
        SCANMODE_value->raise();
        title_2->raise();
        FPS_value->raise();
        label_4->raise();
        subtitle0_3->raise();
        btn_mode_0->raise();
        btn_mode_1->raise();
        btn_mode_2->raise();
        TARGET_DIS_value->raise();
        TARGET_Y_value->raise();
        TARGET_X_value->raise();
        TARGET_CY_value->raise();
        TARGET_CX_value->raise();
        btn_mode_3->raise();
        ROBOT_DIS_value->raise();
        ROBOT_X_value->raise();
        ROBOT_X_value_2->raise();

        retranslateUi(MainWindowDesign);
        QObject::connect(action_Quit, SIGNAL(triggered()), MainWindowDesign, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindowDesign);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowDesign)
    {
        MainWindowDesign->setWindowTitle(QApplication::translate("MainWindowDesign", "Robocup_Vision23_YoloV4", 0, QApplication::UnicodeUTF8));
        action_Quit->setText(QApplication::translate("MainWindowDesign", "&Quit", 0, QApplication::UnicodeUTF8));
        action_Quit->setShortcut(QApplication::translate("MainWindowDesign", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        action_Preferences->setText(QApplication::translate("MainWindowDesign", "&Preferences", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindowDesign", "&About", 0, QApplication::UnicodeUTF8));
        actionAbout_Qt->setText(QApplication::translate("MainWindowDesign", "About &Qt", 0, QApplication::UnicodeUTF8));
        title->setText(QApplication::translate("MainWindowDesign", "Robocup_Vision23_", 0, QApplication::UnicodeUTF8));
        layout0->setText(QString());
        label->setText(QApplication::translate("MainWindowDesign", "VERSION 5.7", 0, QApplication::UnicodeUTF8));
        subtitle0->setText(QApplication::translate("MainWindowDesign", " PAN_TILT", 0, QApplication::UnicodeUTF8));
        label_3->setText(QString());
        PAN_Value->setText(QApplication::translate("MainWindowDesign", " 0", 0, QApplication::UnicodeUTF8));
        btn_oper_pan_tilt->setText(QApplication::translate("MainWindowDesign", "OPER_PAN_TILT", 0, QApplication::UnicodeUTF8));
        SCANMODE_value->setText(QApplication::translate("MainWindowDesign", "SCANMODE : NONE", 0, QApplication::UnicodeUTF8));
        title_2->setText(QApplication::translate("MainWindowDesign", "OCAM", 0, QApplication::UnicodeUTF8));
        FPS_value->setText(QApplication::translate("MainWindowDesign", "FPS : 00", 0, QApplication::UnicodeUTF8));
        label_4->setText(QString());
        subtitle0_3->setText(QApplication::translate("MainWindowDesign", " MODE", 0, QApplication::UnicodeUTF8));
        btn_mode_0->setText(QApplication::translate("MainWindowDesign", "INIT", 0, QApplication::UnicodeUTF8));
        btn_mode_1->setText(QApplication::translate("MainWindowDesign", "BALL", 0, QApplication::UnicodeUTF8));
        btn_mode_2->setText(QApplication::translate("MainWindowDesign", "LC", 0, QApplication::UnicodeUTF8));
        TARGET_DIS_value->setText(QApplication::translate("MainWindowDesign", "TARGET_DIS : 00", 0, QApplication::UnicodeUTF8));
        TARGET_Y_value->setText(QApplication::translate("MainWindowDesign", "TARGET_Y : 00", 0, QApplication::UnicodeUTF8));
        TARGET_X_value->setText(QApplication::translate("MainWindowDesign", "TARGET_X : 00", 0, QApplication::UnicodeUTF8));
        TARGET_CY_value->setText(QApplication::translate("MainWindowDesign", "TARGET_CY : 00", 0, QApplication::UnicodeUTF8));
        TARGET_CX_value->setText(QApplication::translate("MainWindowDesign", "TARGET_CX : 00", 0, QApplication::UnicodeUTF8));
        btn_mode_3->setText(QApplication::translate("MainWindowDesign", "SAVE", 0, QApplication::UnicodeUTF8));
        ROBOT_DIS_value->setText(QApplication::translate("MainWindowDesign", "ROBOT_DIS : 00", 0, QApplication::UnicodeUTF8));
        ROBOT_X_value->setText(QApplication::translate("MainWindowDesign", "ROBOT_X : 00", 0, QApplication::UnicodeUTF8));
        ROBOT_X_value_2->setText(QApplication::translate("MainWindowDesign", "ROBOT_Y : 00", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindowDesign: public Ui_MainWindowDesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
