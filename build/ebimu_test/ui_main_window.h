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
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
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
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *TITLE;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_yawWeight;
    QDoubleSpinBox *doubleSpinBox_yawWeight;
    QGridLayout *gridLayout;
    QLabel *Kp;
    QLabel *Ki;
    QLabel *Kd;
    QDoubleSpinBox *doubleSpinBox_Kp;
    QDoubleSpinBox *doubleSpinBox_Ki;
    QDoubleSpinBox *doubleSpinBox_Kd;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBox_yawEnable;
    QLabel *YAW;
    QFrame *line;
    QLabel *label_YAW;
    QFrame *line_2;
    QSlider *horizontalSlider_YAW;

    void setupUi(QMainWindow *MainWindowDesign)
    {
        if (MainWindowDesign->objectName().isEmpty())
            MainWindowDesign->setObjectName(QString::fromUtf8("MainWindowDesign"));
        MainWindowDesign->resize(394, 290);
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
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 10, -1, 10);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        TITLE = new QLabel(centralwidget);
        TITLE->setObjectName(QString::fromUtf8("TITLE"));

        horizontalLayout_2->addWidget(TITLE);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        verticalLayout_3->addLayout(gridLayout_2);


        gridLayout_3->addLayout(verticalLayout_3, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 6, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_yawWeight = new QLabel(centralwidget);
        label_yawWeight->setObjectName(QString::fromUtf8("label_yawWeight"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_yawWeight->sizePolicy().hasHeightForWidth());
        label_yawWeight->setSizePolicy(sizePolicy1);
        label_yawWeight->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_yawWeight);

        doubleSpinBox_yawWeight = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_yawWeight->setObjectName(QString::fromUtf8("doubleSpinBox_yawWeight"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(doubleSpinBox_yawWeight->sizePolicy().hasHeightForWidth());
        doubleSpinBox_yawWeight->setSizePolicy(sizePolicy2);
        doubleSpinBox_yawWeight->setSingleStep(0.01);
        doubleSpinBox_yawWeight->setValue(0.2);

        horizontalLayout_3->addWidget(doubleSpinBox_yawWeight);


        gridLayout_3->addLayout(horizontalLayout_3, 4, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Kp = new QLabel(centralwidget);
        Kp->setObjectName(QString::fromUtf8("Kp"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(Kp->sizePolicy().hasHeightForWidth());
        Kp->setSizePolicy(sizePolicy3);
        QFont font;
        font.setPointSize(14);
        font.setBold(false);
        font.setWeight(50);
        Kp->setFont(font);
        Kp->setAlignment(Qt::AlignCenter);
        Kp->setMargin(1);

        gridLayout->addWidget(Kp, 1, 0, 1, 1);

        Ki = new QLabel(centralwidget);
        Ki->setObjectName(QString::fromUtf8("Ki"));
        sizePolicy3.setHeightForWidth(Ki->sizePolicy().hasHeightForWidth());
        Ki->setSizePolicy(sizePolicy3);
        Ki->setFont(font);
        Ki->setAlignment(Qt::AlignCenter);
        Ki->setMargin(1);

        gridLayout->addWidget(Ki, 3, 0, 1, 1);

        Kd = new QLabel(centralwidget);
        Kd->setObjectName(QString::fromUtf8("Kd"));
        sizePolicy3.setHeightForWidth(Kd->sizePolicy().hasHeightForWidth());
        Kd->setSizePolicy(sizePolicy3);
        Kd->setFont(font);
        Kd->setAlignment(Qt::AlignCenter);
        Kd->setMargin(1);

        gridLayout->addWidget(Kd, 4, 0, 1, 1);

        doubleSpinBox_Kp = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_Kp->setObjectName(QString::fromUtf8("doubleSpinBox_Kp"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(doubleSpinBox_Kp->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Kp->setSizePolicy(sizePolicy4);
        doubleSpinBox_Kp->setDecimals(6);
        doubleSpinBox_Kp->setSingleStep(0.1);

        gridLayout->addWidget(doubleSpinBox_Kp, 1, 1, 1, 1);

        doubleSpinBox_Ki = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_Ki->setObjectName(QString::fromUtf8("doubleSpinBox_Ki"));
        sizePolicy4.setHeightForWidth(doubleSpinBox_Ki->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Ki->setSizePolicy(sizePolicy4);
        doubleSpinBox_Ki->setDecimals(6);
        doubleSpinBox_Ki->setSingleStep(0.001);

        gridLayout->addWidget(doubleSpinBox_Ki, 3, 1, 1, 1);

        doubleSpinBox_Kd = new QDoubleSpinBox(centralwidget);
        doubleSpinBox_Kd->setObjectName(QString::fromUtf8("doubleSpinBox_Kd"));
        sizePolicy4.setHeightForWidth(doubleSpinBox_Kd->sizePolicy().hasHeightForWidth());
        doubleSpinBox_Kd->setSizePolicy(sizePolicy4);
        doubleSpinBox_Kd->setDecimals(6);
        doubleSpinBox_Kd->setSingleStep(0.001);

        gridLayout->addWidget(doubleSpinBox_Kd, 4, 1, 1, 1);


        gridLayout_3->addLayout(gridLayout, 5, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        checkBox_yawEnable = new QCheckBox(centralwidget);
        checkBox_yawEnable->setObjectName(QString::fromUtf8("checkBox_yawEnable"));

        horizontalLayout->addWidget(checkBox_yawEnable);

        YAW = new QLabel(centralwidget);
        YAW->setObjectName(QString::fromUtf8("YAW"));

        horizontalLayout->addWidget(YAW);

        line = new QFrame(centralwidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line);

        label_YAW = new QLabel(centralwidget);
        label_YAW->setObjectName(QString::fromUtf8("label_YAW"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_YAW->sizePolicy().hasHeightForWidth());
        label_YAW->setSizePolicy(sizePolicy5);
        label_YAW->setMinimumSize(QSize(40, 20));
        label_YAW->setBaseSize(QSize(300, 100));
        label_YAW->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_YAW);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        horizontalLayout->addWidget(line_2);

        horizontalSlider_YAW = new QSlider(centralwidget);
        horizontalSlider_YAW->setObjectName(QString::fromUtf8("horizontalSlider_YAW"));
        horizontalSlider_YAW->setMinimum(-181000);
        horizontalSlider_YAW->setMaximum(181000);
        horizontalSlider_YAW->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider_YAW);


        gridLayout_3->addLayout(horizontalLayout, 2, 0, 1, 1);

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
        TITLE->setText(QApplication::translate("MainWindowDesign", "<html><head/><body><p align=\"center\"><span style=\" font-size:26pt; font-weight:600;\">IMU TESTER</span></p><p align=\"center\"><span style=\" font-size:14pt; font-weight:600;\">make imu value</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_yawWeight->setText(QApplication::translate("MainWindowDesign", "Set yaw weight", 0, QApplication::UnicodeUTF8));
        Kp->setText(QApplication::translate("MainWindowDesign", "Kp", 0, QApplication::UnicodeUTF8));
        Ki->setText(QApplication::translate("MainWindowDesign", "Ki", 0, QApplication::UnicodeUTF8));
        Kd->setText(QApplication::translate("MainWindowDesign", "Kd", 0, QApplication::UnicodeUTF8));
        checkBox_yawEnable->setText(QString());
        YAW->setText(QApplication::translate("MainWindowDesign", "<html><head/><body><p><span style=\" font-size:14pt;\">YAW</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_YAW->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindowDesign: public Ui_MainWindowDesign {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
