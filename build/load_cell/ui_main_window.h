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
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>
#include <qcustomplot.hpp>

QT_BEGIN_NAMESPACE

class Ui_MainWindowDesign
{
public:
    QAction *action_Quit;
    QAction *action_Preferences;
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QWidget *centralwidget;
    QLabel *label_19;
    QCustomPlot *customPlot_LR;
    QLabel *label_40;
    QFrame *frame_2;
    QGroupBox *groupBox_6;
    QLabel *label_28;
    QLineEdit *LC_Zero_Gain_07;
    QLabel *label_25;
    QLineEdit *LC_Zero_Gain_03;
    QLineEdit *LC_Zero_Gain_06;
    QLabel *label_26;
    QLineEdit *LC_Zero_Gain_05;
    QLabel *label_27;
    QLineEdit *LC_Zero_Gain_00;
    QLineEdit *LC_Zero_Gain_04;
    QLineEdit *LC_Zero_Gain_01;
    QLabel *label_29;
    QLabel *label_30;
    QLineEdit *LC_Zero_Gain_02;
    QPushButton *ZG_Push_02;
    QPushButton *ZG_Push_07;
    QPushButton *ZG_Push_01;
    QPushButton *ZG_Push_06;
    QPushButton *ZG_Push_04;
    QPushButton *ZG_Push_05;
    QPushButton *ZG_Push_03;
    QPushButton *ZG_Push_00;
    QGroupBox *groupBox_4;
    QLineEdit *LC_Unit_Value_07;
    QLabel *label_13;
    QLineEdit *LC_Unit_Value_03;
    QLineEdit *LC_Unit_Value_06;
    QLabel *label_14;
    QLineEdit *LC_Unit_Value_05;
    QLabel *label_15;
    QLineEdit *LC_Unit_Value_00;
    QLineEdit *LC_Unit_Value_04;
    QLineEdit *LC_Unit_Value_01;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLineEdit *LC_Unit_Value_02;
    QPushButton *ZG_Insert_Button;
    QFrame *frame;
    QGroupBox *groupBox;
    QLineEdit *LC_Data_07;
    QLabel *label_3;
    QLineEdit *LC_Data_03;
    QLineEdit *LC_Data_06;
    QLabel *label_5;
    QLineEdit *LC_Data_05;
    QLabel *label_4;
    QLineEdit *LC_Data_00;
    QLineEdit *LC_Data_04;
    QLineEdit *LC_Data_01;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_6;
    QLineEdit *LC_Data_02;
    QGroupBox *groupBox_2;
    QLineEdit *LC_Zero_Value_07;
    QLabel *label_7;
    QLineEdit *LC_Zero_Value_03;
    QLineEdit *LC_Zero_Value_06;
    QLabel *label_8;
    QLineEdit *LC_Zero_Value_05;
    QLabel *label_9;
    QLineEdit *LC_Zero_Value_00;
    QLineEdit *LC_Zero_Value_04;
    QLineEdit *LC_Zero_Value_01;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLineEdit *LC_Zero_Value_02;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;

    void setupUi(QMainWindow *MainWindowDesign)
    {
        if (MainWindowDesign->objectName().isEmpty())
            MainWindowDesign->setObjectName(QString::fromUtf8("MainWindowDesign"));
        MainWindowDesign->resize(973, 464);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindowDesign->setWindowIcon(icon);
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
        label_19 = new QLabel(centralwidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(630, 170, 21, 31));
        QFont font;
        font.setPointSize(20);
        label_19->setFont(font);
        label_19->setAlignment(Qt::AlignCenter);
        customPlot_LR = new QCustomPlot(centralwidget);
        customPlot_LR->setObjectName(QString::fromUtf8("customPlot_LR"));
        customPlot_LR->setGeometry(QRect(650, 80, 311, 371));
        label_40 = new QLabel(centralwidget);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setGeometry(QRect(630, 320, 21, 31));
        label_40->setFont(font);
        label_40->setAlignment(Qt::AlignCenter);
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(270, 74, 361, 381));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        groupBox_6 = new QGroupBox(frame_2);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 9, 341, 171));
        QFont font1;
        font1.setPointSize(12);
        groupBox_6->setFont(font1);
        label_28 = new QLabel(groupBox_6);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(8, 52, 49, 17));
        label_28->setAlignment(Qt::AlignCenter);
        LC_Zero_Gain_07 = new QLineEdit(groupBox_6);
        LC_Zero_Gain_07->setObjectName(QString::fromUtf8("LC_Zero_Gain_07"));
        LC_Zero_Gain_07->setGeometry(QRect(147, 142, 78, 25));
        label_25 = new QLabel(groupBox_6);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(8, 114, 49, 17));
        label_25->setAlignment(Qt::AlignCenter);
        LC_Zero_Gain_03 = new QLineEdit(groupBox_6);
        LC_Zero_Gain_03->setObjectName(QString::fromUtf8("LC_Zero_Gain_03"));
        LC_Zero_Gain_03->setGeometry(QRect(63, 142, 78, 25));
        LC_Zero_Gain_06 = new QLineEdit(groupBox_6);
        LC_Zero_Gain_06->setObjectName(QString::fromUtf8("LC_Zero_Gain_06"));
        LC_Zero_Gain_06->setGeometry(QRect(147, 111, 78, 25));
        label_26 = new QLabel(groupBox_6);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(83, 26, 37, 20));
        label_26->setLayoutDirection(Qt::RightToLeft);
        label_26->setAlignment(Qt::AlignCenter);
        LC_Zero_Gain_05 = new QLineEdit(groupBox_6);
        LC_Zero_Gain_05->setObjectName(QString::fromUtf8("LC_Zero_Gain_05"));
        LC_Zero_Gain_05->setGeometry(QRect(147, 80, 78, 25));
        label_27 = new QLabel(groupBox_6);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(8, 145, 49, 17));
        label_27->setAlignment(Qt::AlignCenter);
        LC_Zero_Gain_00 = new QLineEdit(groupBox_6);
        LC_Zero_Gain_00->setObjectName(QString::fromUtf8("LC_Zero_Gain_00"));
        LC_Zero_Gain_00->setGeometry(QRect(63, 49, 78, 25));
        LC_Zero_Gain_04 = new QLineEdit(groupBox_6);
        LC_Zero_Gain_04->setObjectName(QString::fromUtf8("LC_Zero_Gain_04"));
        LC_Zero_Gain_04->setGeometry(QRect(147, 49, 78, 25));
        LC_Zero_Gain_01 = new QLineEdit(groupBox_6);
        LC_Zero_Gain_01->setObjectName(QString::fromUtf8("LC_Zero_Gain_01"));
        LC_Zero_Gain_01->setGeometry(QRect(63, 80, 78, 25));
        label_29 = new QLabel(groupBox_6);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(8, 83, 49, 17));
        label_29->setAlignment(Qt::AlignCenter);
        label_30 = new QLabel(groupBox_6);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(166, 30, 37, 17));
        label_30->setAlignment(Qt::AlignCenter);
        LC_Zero_Gain_02 = new QLineEdit(groupBox_6);
        LC_Zero_Gain_02->setObjectName(QString::fromUtf8("LC_Zero_Gain_02"));
        LC_Zero_Gain_02->setGeometry(QRect(63, 111, 78, 25));
        ZG_Push_02 = new QPushButton(groupBox_6);
        ZG_Push_02->setObjectName(QString::fromUtf8("ZG_Push_02"));
        ZG_Push_02->setGeometry(QRect(235, 113, 48, 25));
        ZG_Push_07 = new QPushButton(groupBox_6);
        ZG_Push_07->setObjectName(QString::fromUtf8("ZG_Push_07"));
        ZG_Push_07->setGeometry(QRect(285, 146, 47, 25));
        ZG_Push_01 = new QPushButton(groupBox_6);
        ZG_Push_01->setObjectName(QString::fromUtf8("ZG_Push_01"));
        ZG_Push_01->setGeometry(QRect(235, 80, 48, 25));
        ZG_Push_06 = new QPushButton(groupBox_6);
        ZG_Push_06->setObjectName(QString::fromUtf8("ZG_Push_06"));
        ZG_Push_06->setGeometry(QRect(285, 113, 47, 25));
        ZG_Push_04 = new QPushButton(groupBox_6);
        ZG_Push_04->setObjectName(QString::fromUtf8("ZG_Push_04"));
        ZG_Push_04->setGeometry(QRect(285, 47, 47, 25));
        ZG_Push_05 = new QPushButton(groupBox_6);
        ZG_Push_05->setObjectName(QString::fromUtf8("ZG_Push_05"));
        ZG_Push_05->setGeometry(QRect(285, 80, 47, 25));
        ZG_Push_03 = new QPushButton(groupBox_6);
        ZG_Push_03->setObjectName(QString::fromUtf8("ZG_Push_03"));
        ZG_Push_03->setGeometry(QRect(235, 146, 48, 25));
        ZG_Push_00 = new QPushButton(groupBox_6);
        ZG_Push_00->setObjectName(QString::fromUtf8("ZG_Push_00"));
        ZG_Push_00->setGeometry(QRect(235, 47, 48, 25));
        groupBox_4 = new QGroupBox(frame_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 200, 241, 171));
        groupBox_4->setFont(font1);
        LC_Unit_Value_07 = new QLineEdit(groupBox_4);
        LC_Unit_Value_07->setObjectName(QString::fromUtf8("LC_Unit_Value_07"));
        LC_Unit_Value_07->setGeometry(QRect(150, 137, 85, 25));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        LC_Unit_Value_07->setFont(font2);
        LC_Unit_Value_07->setAlignment(Qt::AlignCenter);
        label_13 = new QLabel(groupBox_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(5, 109, 49, 17));
        label_13->setAlignment(Qt::AlignCenter);
        LC_Unit_Value_03 = new QLineEdit(groupBox_4);
        LC_Unit_Value_03->setObjectName(QString::fromUtf8("LC_Unit_Value_03"));
        LC_Unit_Value_03->setGeometry(QRect(60, 137, 85, 25));
        LC_Unit_Value_03->setFont(font2);
        LC_Unit_Value_03->setAlignment(Qt::AlignCenter);
        LC_Unit_Value_06 = new QLineEdit(groupBox_4);
        LC_Unit_Value_06->setObjectName(QString::fromUtf8("LC_Unit_Value_06"));
        LC_Unit_Value_06->setGeometry(QRect(150, 106, 85, 25));
        LC_Unit_Value_06->setFont(font2);
        LC_Unit_Value_06->setAlignment(Qt::AlignCenter);
        label_14 = new QLabel(groupBox_4);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(85, 24, 37, 17));
        label_14->setLayoutDirection(Qt::RightToLeft);
        label_14->setAlignment(Qt::AlignCenter);
        LC_Unit_Value_05 = new QLineEdit(groupBox_4);
        LC_Unit_Value_05->setObjectName(QString::fromUtf8("LC_Unit_Value_05"));
        LC_Unit_Value_05->setGeometry(QRect(150, 75, 85, 25));
        LC_Unit_Value_05->setFont(font2);
        LC_Unit_Value_05->setAlignment(Qt::AlignCenter);
        label_15 = new QLabel(groupBox_4);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(5, 140, 49, 17));
        label_15->setAlignment(Qt::AlignCenter);
        LC_Unit_Value_00 = new QLineEdit(groupBox_4);
        LC_Unit_Value_00->setObjectName(QString::fromUtf8("LC_Unit_Value_00"));
        LC_Unit_Value_00->setGeometry(QRect(60, 44, 85, 25));
        LC_Unit_Value_00->setFont(font2);
        LC_Unit_Value_00->setAlignment(Qt::AlignCenter);
        LC_Unit_Value_04 = new QLineEdit(groupBox_4);
        LC_Unit_Value_04->setObjectName(QString::fromUtf8("LC_Unit_Value_04"));
        LC_Unit_Value_04->setGeometry(QRect(150, 44, 85, 25));
        LC_Unit_Value_04->setFont(font2);
        LC_Unit_Value_04->setAlignment(Qt::AlignCenter);
        LC_Unit_Value_01 = new QLineEdit(groupBox_4);
        LC_Unit_Value_01->setObjectName(QString::fromUtf8("LC_Unit_Value_01"));
        LC_Unit_Value_01->setGeometry(QRect(60, 75, 85, 25));
        LC_Unit_Value_01->setFont(font2);
        LC_Unit_Value_01->setAlignment(Qt::AlignCenter);
        label_16 = new QLabel(groupBox_4);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(5, 47, 49, 17));
        label_16->setAlignment(Qt::AlignCenter);
        label_17 = new QLabel(groupBox_4);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(5, 78, 49, 17));
        label_17->setAlignment(Qt::AlignCenter);
        label_18 = new QLabel(groupBox_4);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(174, 24, 37, 17));
        label_18->setAlignment(Qt::AlignCenter);
        LC_Unit_Value_02 = new QLineEdit(groupBox_4);
        LC_Unit_Value_02->setObjectName(QString::fromUtf8("LC_Unit_Value_02"));
        LC_Unit_Value_02->setGeometry(QRect(60, 106, 85, 25));
        LC_Unit_Value_02->setFont(font2);
        LC_Unit_Value_02->setAlignment(Qt::AlignCenter);
        ZG_Insert_Button = new QPushButton(frame_2);
        ZG_Insert_Button->setObjectName(QString::fromUtf8("ZG_Insert_Button"));
        ZG_Insert_Button->setGeometry(QRect(110, 180, 91, 31));
        QFont font3;
        font3.setPointSize(13);
        ZG_Insert_Button->setFont(font3);
        ZG_Insert_Button->setFocusPolicy(Qt::StrongFocus);
        ZG_Insert_Button->setDefault(false);
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 74, 261, 381));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        groupBox = new QGroupBox(frame);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 241, 171));
        groupBox->setFont(font1);
        LC_Data_07 = new QLineEdit(groupBox);
        LC_Data_07->setObjectName(QString::fromUtf8("LC_Data_07"));
        LC_Data_07->setGeometry(QRect(150, 145, 85, 25));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(7, 119, 49, 17));
        label_3->setAlignment(Qt::AlignCenter);
        LC_Data_03 = new QLineEdit(groupBox);
        LC_Data_03->setObjectName(QString::fromUtf8("LC_Data_03"));
        LC_Data_03->setGeometry(QRect(62, 145, 85, 25));
        LC_Data_06 = new QLineEdit(groupBox);
        LC_Data_06->setObjectName(QString::fromUtf8("LC_Data_06"));
        LC_Data_06->setGeometry(QRect(150, 114, 85, 25));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(85, 30, 37, 17));
        label_5->setLayoutDirection(Qt::RightToLeft);
        label_5->setAlignment(Qt::AlignCenter);
        LC_Data_05 = new QLineEdit(groupBox);
        LC_Data_05->setObjectName(QString::fromUtf8("LC_Data_05"));
        LC_Data_05->setGeometry(QRect(150, 83, 85, 25));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(7, 150, 49, 17));
        label_4->setAlignment(Qt::AlignCenter);
        LC_Data_00 = new QLineEdit(groupBox);
        LC_Data_00->setObjectName(QString::fromUtf8("LC_Data_00"));
        LC_Data_00->setGeometry(QRect(62, 52, 85, 25));
        LC_Data_04 = new QLineEdit(groupBox);
        LC_Data_04->setObjectName(QString::fromUtf8("LC_Data_04"));
        LC_Data_04->setGeometry(QRect(150, 52, 85, 25));
        LC_Data_01 = new QLineEdit(groupBox);
        LC_Data_01->setObjectName(QString::fromUtf8("LC_Data_01"));
        LC_Data_01->setGeometry(QRect(62, 83, 85, 25));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(7, 57, 49, 17));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(7, 88, 49, 17));
        label_2->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(174, 30, 37, 17));
        label_6->setAlignment(Qt::AlignCenter);
        LC_Data_02 = new QLineEdit(groupBox);
        LC_Data_02->setObjectName(QString::fromUtf8("LC_Data_02"));
        LC_Data_02->setGeometry(QRect(62, 114, 85, 25));
        groupBox_2 = new QGroupBox(frame);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 200, 241, 171));
        groupBox_2->setFont(font1);
        LC_Zero_Value_07 = new QLineEdit(groupBox_2);
        LC_Zero_Value_07->setObjectName(QString::fromUtf8("LC_Zero_Value_07"));
        LC_Zero_Value_07->setGeometry(QRect(150, 137, 85, 25));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(4, 109, 49, 17));
        label_7->setAlignment(Qt::AlignCenter);
        LC_Zero_Value_03 = new QLineEdit(groupBox_2);
        LC_Zero_Value_03->setObjectName(QString::fromUtf8("LC_Zero_Value_03"));
        LC_Zero_Value_03->setGeometry(QRect(59, 137, 85, 25));
        LC_Zero_Value_06 = new QLineEdit(groupBox_2);
        LC_Zero_Value_06->setObjectName(QString::fromUtf8("LC_Zero_Value_06"));
        LC_Zero_Value_06->setGeometry(QRect(150, 106, 85, 25));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(85, 25, 37, 17));
        label_8->setLayoutDirection(Qt::RightToLeft);
        label_8->setAlignment(Qt::AlignCenter);
        LC_Zero_Value_05 = new QLineEdit(groupBox_2);
        LC_Zero_Value_05->setObjectName(QString::fromUtf8("LC_Zero_Value_05"));
        LC_Zero_Value_05->setGeometry(QRect(150, 75, 85, 25));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(4, 140, 49, 17));
        label_9->setAlignment(Qt::AlignCenter);
        LC_Zero_Value_00 = new QLineEdit(groupBox_2);
        LC_Zero_Value_00->setObjectName(QString::fromUtf8("LC_Zero_Value_00"));
        LC_Zero_Value_00->setGeometry(QRect(59, 44, 85, 25));
        LC_Zero_Value_04 = new QLineEdit(groupBox_2);
        LC_Zero_Value_04->setObjectName(QString::fromUtf8("LC_Zero_Value_04"));
        LC_Zero_Value_04->setGeometry(QRect(150, 44, 85, 25));
        LC_Zero_Value_01 = new QLineEdit(groupBox_2);
        LC_Zero_Value_01->setObjectName(QString::fromUtf8("LC_Zero_Value_01"));
        LC_Zero_Value_01->setGeometry(QRect(59, 75, 85, 25));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(4, 47, 49, 17));
        label_10->setAlignment(Qt::AlignCenter);
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(4, 78, 49, 17));
        label_11->setAlignment(Qt::AlignCenter);
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(174, 25, 37, 17));
        label_12->setAlignment(Qt::AlignCenter);
        LC_Zero_Value_02 = new QLineEdit(groupBox_2);
        LC_Zero_Value_02->setObjectName(QString::fromUtf8("LC_Zero_Value_02"));
        LC_Zero_Value_02->setGeometry(QRect(59, 106, 85, 25));
        label_20 = new QLabel(centralwidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(350, 20, 211, 41));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Tibetan Machine Uni"));
        font4.setPointSize(24);
        label_20->setFont(font4);
        label_20->setAlignment(Qt::AlignCenter);
        label_21 = new QLabel(centralwidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(570, 30, 81, 31));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Tibetan Machine Uni"));
        font5.setPointSize(16);
        label_21->setFont(font5);
        label_21->setAlignment(Qt::AlignCenter);
        label_22 = new QLabel(centralwidget);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(320, 10, 361, 51));
        label_22->setFocusPolicy(Qt::TabFocus);
        label_22->setFrameShape(QFrame::Box);
        label_22->setLineWidth(3);
        MainWindowDesign->setCentralWidget(centralwidget);

        retranslateUi(MainWindowDesign);
        QObject::connect(action_Quit, SIGNAL(triggered()), MainWindowDesign, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindowDesign);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowDesign)
    {
        MainWindowDesign->setWindowTitle(QApplication::translate("MainWindowDesign", "QRosApp", 0, QApplication::UnicodeUTF8));
        action_Quit->setText(QApplication::translate("MainWindowDesign", "&Quit", 0, QApplication::UnicodeUTF8));
        action_Quit->setShortcut(QApplication::translate("MainWindowDesign", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        action_Preferences->setText(QApplication::translate("MainWindowDesign", "&Preferences", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindowDesign", "&About", 0, QApplication::UnicodeUTF8));
        actionAbout_Qt->setText(QApplication::translate("MainWindowDesign", "About &Qt", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindowDesign", "R", 0, QApplication::UnicodeUTF8));
        label_40->setText(QApplication::translate("MainWindowDesign", "L", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("MainWindowDesign", " Zero_Gain", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("MainWindowDesign", "LC_0_4", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("MainWindowDesign", "LC_2_6", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("MainWindowDesign", "Left", 0, QApplication::UnicodeUTF8));
        label_27->setText(QApplication::translate("MainWindowDesign", "LC_3_7", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("MainWindowDesign", "LC_1_5", 0, QApplication::UnicodeUTF8));
        label_30->setText(QApplication::translate("MainWindowDesign", "Right", 0, QApplication::UnicodeUTF8));
        ZG_Push_02->setText(QApplication::translate("MainWindowDesign", "LC_2", 0, QApplication::UnicodeUTF8));
        ZG_Push_07->setText(QApplication::translate("MainWindowDesign", "LC_7", 0, QApplication::UnicodeUTF8));
        ZG_Push_01->setText(QApplication::translate("MainWindowDesign", "LC_1", 0, QApplication::UnicodeUTF8));
        ZG_Push_06->setText(QApplication::translate("MainWindowDesign", "LC_6", 0, QApplication::UnicodeUTF8));
        ZG_Push_04->setText(QApplication::translate("MainWindowDesign", "LC_4", 0, QApplication::UnicodeUTF8));
        ZG_Push_05->setText(QApplication::translate("MainWindowDesign", "LC_5", 0, QApplication::UnicodeUTF8));
        ZG_Push_03->setText(QApplication::translate("MainWindowDesign", "LC_3", 0, QApplication::UnicodeUTF8));
        ZG_Push_00->setText(QApplication::translate("MainWindowDesign", "LC_0", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindowDesign", "Binary", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindowDesign", "LC_2_6", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindowDesign", "Left", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindowDesign", "LC_3_7", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindowDesign", "LC_0_4", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindowDesign", "LC_1_5", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindowDesign", "Right", 0, QApplication::UnicodeUTF8));
        ZG_Insert_Button->setText(QApplication::translate("MainWindowDesign", "Insert", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindowDesign", " Data", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindowDesign", "LC_2_6", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindowDesign", "Left", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindowDesign", "LC_3_7", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindowDesign", "LC_0_4", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindowDesign", "LC_1_5", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindowDesign", "Right", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindowDesign", " Zero_Value", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindowDesign", "LC_2_6", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindowDesign", "Left", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindowDesign", "LC_3_7", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindowDesign", "LC_0_4", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindowDesign", "LC_1_5", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindowDesign", "Right", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindowDesign", "LOAD_CELL", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("MainWindowDesign", "for LTC", 0, QApplication::UnicodeUTF8));
        label_22->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindowDesign: public Ui_MainWindowDesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H