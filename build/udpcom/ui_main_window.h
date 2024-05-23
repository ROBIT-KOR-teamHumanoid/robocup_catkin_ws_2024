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
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
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
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *title;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QFormLayout *formLayout;
    QLabel *PORT_Lable_5;
    QLineEdit *NUM_Line;
    QLabel *IP_Label;
    QLineEdit *IP_Line;
    QLabel *PORT_Lable_2;
    QLineEdit *PORT_Line;
    QLineEdit *PORT_Line_2;
    QLineEdit *PORT_Line_3;
    QLineEdit *PORT_Line_4;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButton_read1;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *radioButton_read2;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *radioButton_read3;
    QPushButton *pushButton;

    void setupUi(QMainWindow *MainWindowDesign)
    {
        if (MainWindowDesign->objectName().isEmpty())
            MainWindowDesign->setObjectName(QString::fromUtf8("MainWindowDesign"));
        MainWindowDesign->resize(425, 303);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/udp.png"), QSize(), QIcon::Normal, QIcon::Off);
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
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        title = new QLabel(centralwidget);
        title->setObjectName(QString::fromUtf8("title"));

        verticalLayout_2->addWidget(title);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        PORT_Lable_5 = new QLabel(centralwidget);
        PORT_Lable_5->setObjectName(QString::fromUtf8("PORT_Lable_5"));

        formLayout->setWidget(0, QFormLayout::LabelRole, PORT_Lable_5);

        NUM_Line = new QLineEdit(centralwidget);
        NUM_Line->setObjectName(QString::fromUtf8("NUM_Line"));

        formLayout->setWidget(0, QFormLayout::FieldRole, NUM_Line);

        IP_Label = new QLabel(centralwidget);
        IP_Label->setObjectName(QString::fromUtf8("IP_Label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, IP_Label);

        IP_Line = new QLineEdit(centralwidget);
        IP_Line->setObjectName(QString::fromUtf8("IP_Line"));

        formLayout->setWidget(1, QFormLayout::FieldRole, IP_Line);

        PORT_Lable_2 = new QLabel(centralwidget);
        PORT_Lable_2->setObjectName(QString::fromUtf8("PORT_Lable_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, PORT_Lable_2);

        PORT_Line = new QLineEdit(centralwidget);
        PORT_Line->setObjectName(QString::fromUtf8("PORT_Line"));

        formLayout->setWidget(2, QFormLayout::FieldRole, PORT_Line);

        PORT_Line_2 = new QLineEdit(centralwidget);
        PORT_Line_2->setObjectName(QString::fromUtf8("PORT_Line_2"));

        formLayout->setWidget(3, QFormLayout::FieldRole, PORT_Line_2);

        PORT_Line_3 = new QLineEdit(centralwidget);
        PORT_Line_3->setObjectName(QString::fromUtf8("PORT_Line_3"));

        formLayout->setWidget(4, QFormLayout::FieldRole, PORT_Line_3);

        PORT_Line_4 = new QLineEdit(centralwidget);
        PORT_Line_4->setObjectName(QString::fromUtf8("PORT_Line_4"));

        formLayout->setWidget(5, QFormLayout::FieldRole, PORT_Line_4);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        radioButton_read1 = new QRadioButton(centralwidget);
        radioButton_read1->setObjectName(QString::fromUtf8("radioButton_read1"));
        radioButton_read1->setEnabled(true);
        radioButton_read1->setIconSize(QSize(16, 16));
        radioButton_read1->setChecked(false);
        radioButton_read1->setAutoRepeat(false);
        radioButton_read1->setAutoExclusive(false);

        verticalLayout_3->addWidget(radioButton_read1);


        formLayout->setLayout(3, QFormLayout::LabelRole, verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        radioButton_read2 = new QRadioButton(centralwidget);
        radioButton_read2->setObjectName(QString::fromUtf8("radioButton_read2"));
        radioButton_read2->setChecked(false);
        radioButton_read2->setAutoRepeat(false);
        radioButton_read2->setAutoExclusive(false);

        verticalLayout_4->addWidget(radioButton_read2);


        formLayout->setLayout(4, QFormLayout::LabelRole, verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        radioButton_read3 = new QRadioButton(centralwidget);
        radioButton_read3->setObjectName(QString::fromUtf8("radioButton_read3"));
        radioButton_read3->setAutoRepeat(false);
        radioButton_read3->setAutoExclusive(false);

        verticalLayout_5->addWidget(radioButton_read3);


        formLayout->setLayout(5, QFormLayout::LabelRole, verticalLayout_5);


        verticalLayout->addLayout(formLayout);


        verticalLayout_2->addLayout(verticalLayout);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_2->addWidget(pushButton);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        MainWindowDesign->setCentralWidget(centralwidget);

        retranslateUi(MainWindowDesign);
        QObject::connect(action_Quit, SIGNAL(triggered()), MainWindowDesign, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindowDesign);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowDesign)
    {
        MainWindowDesign->setWindowTitle(QApplication::translate("MainWindowDesign", "ROBOCUP COMMUICATOR23 ver2.11.2", 0, QApplication::UnicodeUTF8));
        action_Quit->setText(QApplication::translate("MainWindowDesign", "&Quit", 0, QApplication::UnicodeUTF8));
        action_Quit->setShortcut(QApplication::translate("MainWindowDesign", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        action_Preferences->setText(QApplication::translate("MainWindowDesign", "&Preferences", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindowDesign", "&About", 0, QApplication::UnicodeUTF8));
        actionAbout_Qt->setText(QApplication::translate("MainWindowDesign", "About &Qt", 0, QApplication::UnicodeUTF8));
        title->setText(QApplication::translate("MainWindowDesign", "<html><head/><body><p><span style=\" font-size:22pt;\">UDP Commuicator</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindowDesign", "UDP STATE", 0, QApplication::UnicodeUTF8));
        PORT_Lable_5->setText(QApplication::translate("MainWindowDesign", "ROBOT NUM", 0, QApplication::UnicodeUTF8));
        IP_Label->setText(QApplication::translate("MainWindowDesign", "IP ADDR", 0, QApplication::UnicodeUTF8));
        PORT_Lable_2->setText(QApplication::translate("MainWindowDesign", "WRITE", 0, QApplication::UnicodeUTF8));
        PORT_Line_3->setText(QString());
        PORT_Line_4->setText(QString());
        radioButton_read1->setText(QApplication::translate("MainWindowDesign", "READ1", 0, QApplication::UnicodeUTF8));
        radioButton_read2->setText(QApplication::translate("MainWindowDesign", "READ2", 0, QApplication::UnicodeUTF8));
        radioButton_read3->setText(QApplication::translate("MainWindowDesign", "READ3", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindowDesign", "init", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindowDesign: public Ui_MainWindowDesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
