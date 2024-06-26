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
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
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
    QLabel *Receive_2;
    QLabel *label_RNum;
    QGroupBox *groupBox_2;
    QLabel *label_9;
    QLabel *label_7;
    QLabel *label_6;
    QTextEdit *textEdit_READ_2;
    QTextEdit *textEdit_READ;
    QTextEdit *textEdit_READ_3;
    QGroupBox *groupBox;
    QTextEdit *textEdit_SEND;
    QTextEdit *textEdit_SEND_2;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_20;
    QLabel *label_22;
    QTextEdit *textEdit_SEND_3;
    QLabel *label_23;
    QTextEdit *textEdit_SEND_4;
    QTextEdit *textEdit_SEND_5;
    QGroupBox *UDP_Setting;
    QLabel *IP_Label;
    QLineEdit *IP_Line;
    QLineEdit *PORT_Line_2;
    QLabel *PORT_Lable_2;
    QLabel *PORT_Lable_3;
    QLineEdit *PORT_Line;
    QLabel *Receive;
    QPushButton *pushButton;
    QLabel *Receive_3;
    QLabel *label_CaseNum;

    void setupUi(QMainWindow *MainWindowDesign)
    {
        if (MainWindowDesign->objectName().isEmpty())
            MainWindowDesign->setObjectName(QString::fromUtf8("MainWindowDesign"));
        MainWindowDesign->resize(1090, 341);
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
        Receive_2 = new QLabel(centralwidget);
        Receive_2->setObjectName(QString::fromUtf8("Receive_2"));
        Receive_2->setGeometry(QRect(280, 20, 301, 61));
        QFont font;
        font.setFamily(QString::fromUtf8("Waree"));
        font.setBold(true);
        font.setWeight(75);
        Receive_2->setFont(font);
        label_RNum = new QLabel(centralwidget);
        label_RNum->setObjectName(QString::fromUtf8("label_RNum"));
        label_RNum->setGeometry(QRect(570, 20, 81, 61));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Waree"));
        font1.setPointSize(25);
        font1.setBold(true);
        font1.setWeight(75);
        label_RNum->setFont(font1);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(640, 80, 211, 240));
        QFont font2;
        font2.setPointSize(13);
        groupBox_2->setFont(font2);
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(143, 30, 60, 22));
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setWeight(75);
        label_9->setFont(font3);
        label_9->setFrameShape(QFrame::Box);
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 30, 60, 22));
        label_7->setFont(font3);
        label_7->setFrameShape(QFrame::Box);
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(76, 30, 61, 22));
        label_6->setFont(font3);
        label_6->setFrameShape(QFrame::Box);
        textEdit_READ_2 = new QTextEdit(groupBox_2);
        textEdit_READ_2->setObjectName(QString::fromUtf8("textEdit_READ_2"));
        textEdit_READ_2->setGeometry(QRect(78, 60, 60, 171));
        QFont font4;
        font4.setPointSize(11);
        textEdit_READ_2->setFont(font4);
        textEdit_READ = new QTextEdit(groupBox_2);
        textEdit_READ->setObjectName(QString::fromUtf8("textEdit_READ"));
        textEdit_READ->setGeometry(QRect(10, 60, 60, 171));
        textEdit_READ->setFont(font4);
        textEdit_READ_3 = new QTextEdit(groupBox_2);
        textEdit_READ_3->setObjectName(QString::fromUtf8("textEdit_READ_3"));
        textEdit_READ_3->setGeometry(QRect(144, 60, 60, 171));
        textEdit_READ_3->setFont(font4);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 80, 611, 240));
        QFont font5;
        font5.setPointSize(13);
        font5.setBold(true);
        font5.setWeight(75);
        groupBox->setFont(font5);
        textEdit_SEND = new QTextEdit(groupBox);
        textEdit_SEND->setObjectName(QString::fromUtf8("textEdit_SEND"));
        textEdit_SEND->setGeometry(QRect(10, 60, 121, 171));
        textEdit_SEND->setFont(font4);
        textEdit_SEND_2 = new QTextEdit(groupBox);
        textEdit_SEND_2->setObjectName(QString::fromUtf8("textEdit_SEND_2"));
        textEdit_SEND_2->setGeometry(QRect(140, 60, 121, 171));
        textEdit_SEND_2->setFont(font4);
        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(140, 30, 121, 22));
        label_15->setFont(font3);
        label_15->setFrameShape(QFrame::Box);
        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(11, 30, 121, 22));
        label_16->setFont(font3);
        label_16->setFrameShape(QFrame::Box);
        label_20 = new QLabel(groupBox);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(290, 30, 91, 22));
        label_20->setFont(font3);
        label_20->setFocusPolicy(Qt::NoFocus);
        label_20->setFrameShape(QFrame::Box);
        label_22 = new QLabel(groupBox);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(390, 30, 91, 22));
        label_22->setFont(font3);
        label_22->setFocusPolicy(Qt::NoFocus);
        label_22->setFrameShape(QFrame::Box);
        textEdit_SEND_3 = new QTextEdit(groupBox);
        textEdit_SEND_3->setObjectName(QString::fromUtf8("textEdit_SEND_3"));
        textEdit_SEND_3->setGeometry(QRect(290, 60, 91, 171));
        textEdit_SEND_3->setFont(font4);
        label_23 = new QLabel(groupBox);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(490, 30, 111, 22));
        label_23->setFont(font3);
        label_23->setFocusPolicy(Qt::NoFocus);
        label_23->setFrameShape(QFrame::Box);
        textEdit_SEND_4 = new QTextEdit(groupBox);
        textEdit_SEND_4->setObjectName(QString::fromUtf8("textEdit_SEND_4"));
        textEdit_SEND_4->setGeometry(QRect(390, 60, 91, 171));
        textEdit_SEND_4->setFont(font4);
        textEdit_SEND_5 = new QTextEdit(groupBox);
        textEdit_SEND_5->setObjectName(QString::fromUtf8("textEdit_SEND_5"));
        textEdit_SEND_5->setGeometry(QRect(490, 60, 111, 171));
        textEdit_SEND_5->setFont(font4);
        UDP_Setting = new QGroupBox(centralwidget);
        UDP_Setting->setObjectName(QString::fromUtf8("UDP_Setting"));
        UDP_Setting->setGeometry(QRect(870, 90, 201, 231));
        IP_Label = new QLabel(UDP_Setting);
        IP_Label->setObjectName(QString::fromUtf8("IP_Label"));
        IP_Label->setGeometry(QRect(10, 40, 21, 17));
        IP_Line = new QLineEdit(UDP_Setting);
        IP_Line->setObjectName(QString::fromUtf8("IP_Line"));
        IP_Line->setGeometry(QRect(80, 40, 113, 27));
        PORT_Line_2 = new QLineEdit(UDP_Setting);
        PORT_Line_2->setObjectName(QString::fromUtf8("PORT_Line_2"));
        PORT_Line_2->setGeometry(QRect(120, 190, 71, 27));
        PORT_Lable_2 = new QLabel(UDP_Setting);
        PORT_Lable_2->setObjectName(QString::fromUtf8("PORT_Lable_2"));
        PORT_Lable_2->setGeometry(QRect(10, 110, 91, 17));
        PORT_Lable_3 = new QLabel(UDP_Setting);
        PORT_Lable_3->setObjectName(QString::fromUtf8("PORT_Lable_3"));
        PORT_Lable_3->setGeometry(QRect(10, 190, 91, 17));
        PORT_Line = new QLineEdit(UDP_Setting);
        PORT_Line->setObjectName(QString::fromUtf8("PORT_Line"));
        PORT_Line->setGeometry(QRect(120, 110, 71, 27));
        Receive = new QLabel(centralwidget);
        Receive->setObjectName(QString::fromUtf8("Receive"));
        Receive->setGeometry(QRect(10, 20, 251, 61));
        Receive->setFont(font);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(890, 10, 191, 81));
        Receive_3 = new QLabel(centralwidget);
        Receive_3->setObjectName(QString::fromUtf8("Receive_3"));
        Receive_3->setGeometry(QRect(670, 20, 101, 61));
        Receive_3->setFont(font);
        label_CaseNum = new QLabel(centralwidget);
        label_CaseNum->setObjectName(QString::fromUtf8("label_CaseNum"));
        label_CaseNum->setGeometry(QRect(770, 20, 81, 61));
        label_CaseNum->setFont(font1);
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
        Receive_2->setText(QApplication::translate("MainWindowDesign", "<html><head/><body><p><span style=\" font-size:26pt; font-style:italic;\">ROBOT_Helper</span></p><p><br/></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_RNum->setText(QString());
        groupBox_2->setTitle(QApplication::translate("MainWindowDesign", "READ_Kicker", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindowDesign", "Yaw", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindowDesign", "X", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindowDesign", "Y", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindowDesign", "SEND_Helper", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindowDesign", "Local_Y_order", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindowDesign", "Local_X_order", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindowDesign", "IK_X_order", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("MainWindowDesign", "IK_Y_order", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("MainWindowDesign", "IK_Yaw_order", 0, QApplication::UnicodeUTF8));
        UDP_Setting->setTitle(QApplication::translate("MainWindowDesign", "UDP_Setting", 0, QApplication::UnicodeUTF8));
        IP_Label->setText(QApplication::translate("MainWindowDesign", "IP", 0, QApplication::UnicodeUTF8));
        PORT_Lable_2->setText(QApplication::translate("MainWindowDesign", "WRITE_PORT", 0, QApplication::UnicodeUTF8));
        PORT_Lable_3->setText(QApplication::translate("MainWindowDesign", "READ 1", 0, QApplication::UnicodeUTF8));
        Receive->setText(QApplication::translate("MainWindowDesign", "<html><head/><body><p><span style=\" font-size:26pt; font-weight:600; font-style:italic;\">UDP Receive</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindowDesign", "F5", 0, QApplication::UnicodeUTF8));
        Receive_3->setText(QApplication::translate("MainWindowDesign", "<html><head/><body><p><span style=\" font-size:26pt; font-style:italic;\">Case</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_CaseNum->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindowDesign: public Ui_MainWindowDesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
