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
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
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
    QPushButton *pushButton_StartMt;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_MtNum;
    QLabel *label_2;
    QPushButton *pushButton_STOP;

    void setupUi(QMainWindow *MainWindowDesign)
    {
        if (MainWindowDesign->objectName().isEmpty())
            MainWindowDesign->setObjectName(QString::fromUtf8("MainWindowDesign"));
        MainWindowDesign->resize(415, 294);
        QFont font;
        font.setPointSize(11);
        MainWindowDesign->setFont(font);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/robot.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindowDesign->setWindowIcon(icon);
        MainWindowDesign->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 52, 52);\n"
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
        pushButton_StartMt = new QPushButton(centralwidget);
        pushButton_StartMt->setObjectName(QString::fromUtf8("pushButton_StartMt"));
        pushButton_StartMt->setGeometry(QRect(40, 140, 160, 60));
        QFont font1;
        font1.setPointSize(14);
        pushButton_StartMt->setFont(font1);
        pushButton_StartMt->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);\n"
"border-radius: 5px;\n"
"border:1px solid white;"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 80, 160, 35));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("border:2px solid white;"));
        label->setFrameShape(QFrame::Box);

        horizontalLayout->addWidget(label);

        lineEdit_MtNum = new QLineEdit(horizontalLayoutWidget);
        lineEdit_MtNum->setObjectName(QString::fromUtf8("lineEdit_MtNum"));
        lineEdit_MtNum->setEnabled(true);

        horizontalLayout->addWidget(lineEdit_MtNum);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 10, 121, 61));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Bitstream Vera Sans"));
        font2.setPointSize(30);
        font2.setBold(true);
        font2.setItalic(true);
        font2.setWeight(75);
        label_2->setFont(font2);
        pushButton_STOP = new QPushButton(centralwidget);
        pushButton_STOP->setObjectName(QString::fromUtf8("pushButton_STOP"));
        pushButton_STOP->setGeometry(QRect(215, 140, 160, 60));
        pushButton_STOP->setFont(font1);
        pushButton_STOP->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 87, 83);\n"
"border-radius: 5px;\n"
"border:1px solid white;"));
        MainWindowDesign->setCentralWidget(centralwidget);

        retranslateUi(MainWindowDesign);
        QObject::connect(action_Quit, SIGNAL(triggered()), MainWindowDesign, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindowDesign);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowDesign)
    {
        MainWindowDesign->setWindowTitle(QApplication::translate("MainWindowDesign", "Robit_Motion_Operator", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_ACCESSIBILITY
        MainWindowDesign->setAccessibleDescription(QString());
#endif // QT_NO_ACCESSIBILITY
        action_Quit->setText(QApplication::translate("MainWindowDesign", "&Quit", 0, QApplication::UnicodeUTF8));
        action_Quit->setShortcut(QApplication::translate("MainWindowDesign", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        action_Preferences->setText(QApplication::translate("MainWindowDesign", "&Preferences", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindowDesign", "&About", 0, QApplication::UnicodeUTF8));
        actionAbout_Qt->setText(QApplication::translate("MainWindowDesign", "About &Qt", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_ACCESSIBILITY
        pushButton_StartMt->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
        pushButton_StartMt->setText(QApplication::translate("MainWindowDesign", "Motion Start!!", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindowDesign", "Num :", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindowDesign", "RoBit", 0, QApplication::UnicodeUTF8));
        pushButton_STOP->setText(QApplication::translate("MainWindowDesign", "STOP(init)", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindowDesign: public Ui_MainWindowDesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
