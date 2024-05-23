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
#include <QtGui/QDial>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
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
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QDial *dial;
    QSlider *verticalSlider;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QSlider *horizontalSlider;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_set;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_set_n90;
    QPushButton *pushButton_set_180;
    QPushButton *pushButton_set_p90;

    void setupUi(QMainWindow *MainWindowDesign)
    {
        if (MainWindowDesign->objectName().isEmpty())
            MainWindowDesign->setObjectName(QString::fromUtf8("MainWindowDesign"));
        MainWindowDesign->resize(409, 474);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/mw_2.png"), QSize(), QIcon::Normal, QIcon::Off);
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
        centralwidget->setAutoFillBackground(false);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        dial = new QDial(centralwidget);
        dial->setObjectName(QString::fromUtf8("dial"));
        dial->setMinimumSize(QSize(300, 300));
        dial->setMaximumSize(QSize(300, 300));
        dial->setMinimum(-180);
        dial->setMaximum(180);
        dial->setNotchTarget(0);

        horizontalLayout->addWidget(dial);

        verticalSlider = new QSlider(centralwidget);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(verticalSlider->sizePolicy().hasHeightForWidth());
        verticalSlider->setSizePolicy(sizePolicy);
        verticalSlider->setMinimumSize(QSize(20, 300));
        verticalSlider->setMaximumSize(QSize(20, 300));
        verticalSlider->setMinimum(-90);
        verticalSlider->setMaximum(90);
        verticalSlider->setOrientation(Qt::Vertical);

        horizontalLayout->addWidget(verticalSlider);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMinimumSize(QSize(300, 20));
        horizontalSlider->setMaximumSize(QSize(300, 20));
        horizontalSlider->setMinimum(-90);
        horizontalSlider->setMaximum(90);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSlider);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        pushButton_set = new QPushButton(centralwidget);
        pushButton_set->setObjectName(QString::fromUtf8("pushButton_set"));
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        font.setWeight(75);
        pushButton_set->setFont(font);

        verticalLayout_2->addWidget(pushButton_set);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton_set_n90 = new QPushButton(centralwidget);
        pushButton_set_n90->setObjectName(QString::fromUtf8("pushButton_set_n90"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_set_n90->sizePolicy().hasHeightForWidth());
        pushButton_set_n90->setSizePolicy(sizePolicy1);
        pushButton_set_n90->setFont(font);

        horizontalLayout_4->addWidget(pushButton_set_n90);

        pushButton_set_180 = new QPushButton(centralwidget);
        pushButton_set_180->setObjectName(QString::fromUtf8("pushButton_set_180"));
        sizePolicy1.setHeightForWidth(pushButton_set_180->sizePolicy().hasHeightForWidth());
        pushButton_set_180->setSizePolicy(sizePolicy1);
        pushButton_set_180->setFont(font);

        horizontalLayout_4->addWidget(pushButton_set_180);

        pushButton_set_p90 = new QPushButton(centralwidget);
        pushButton_set_p90->setObjectName(QString::fromUtf8("pushButton_set_p90"));
        sizePolicy1.setHeightForWidth(pushButton_set_p90->sizePolicy().hasHeightForWidth());
        pushButton_set_p90->setSizePolicy(sizePolicy1);
        pushButton_set_p90->setFont(font);

        horizontalLayout_4->addWidget(pushButton_set_p90);


        verticalLayout_2->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        MainWindowDesign->setCentralWidget(centralwidget);

        retranslateUi(MainWindowDesign);
        QObject::connect(action_Quit, SIGNAL(triggered()), MainWindowDesign, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindowDesign);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowDesign)
    {
        MainWindowDesign->setWindowTitle(QApplication::translate("MainWindowDesign", "2023 ROBIT IMU", 0, QApplication::UnicodeUTF8));
        action_Quit->setText(QApplication::translate("MainWindowDesign", "&Quit", 0, QApplication::UnicodeUTF8));
        action_Quit->setShortcut(QApplication::translate("MainWindowDesign", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        action_Preferences->setText(QApplication::translate("MainWindowDesign", "&Preferences", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindowDesign", "&About", 0, QApplication::UnicodeUTF8));
        actionAbout_Qt->setText(QApplication::translate("MainWindowDesign", "About &Qt", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindowDesign", "<html><head/><body><p><span style=\" font-size:26pt;\">EBIMU v5 </span><span style=\" font-size:16pt;\">for RoboCup 2023</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        pushButton_set->setText(QApplication::translate("MainWindowDesign", "SET YAW", 0, QApplication::UnicodeUTF8));
        pushButton_set_n90->setText(QApplication::translate("MainWindowDesign", "SET -90", 0, QApplication::UnicodeUTF8));
        pushButton_set_180->setText(QApplication::translate("MainWindowDesign", "SET 180", 0, QApplication::UnicodeUTF8));
        pushButton_set_p90->setText(QApplication::translate("MainWindowDesign", "SET +90", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindowDesign: public Ui_MainWindowDesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
