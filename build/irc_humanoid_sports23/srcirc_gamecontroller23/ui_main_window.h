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
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RobocupController
{
public:
    QAction *action_Quit;
    QAction *action_Preferences;
    QAction *actionAbout;
    QAction *actionAbout_Qt;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_title;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *textEdit;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLabel *label_Position;
    QComboBox *comboBox_position;
    QLabel *label_State;
    QComboBox *comboBox_State;
    QPushButton *Server_Open;

    void setupUi(QMainWindow *RobocupController)
    {
        if (RobocupController->objectName().isEmpty())
            RobocupController->setObjectName(QString::fromUtf8("RobocupController"));
        RobocupController->resize(465, 216);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/images/robit.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/Icons/images/robit.png"), QSize(), QIcon::Disabled, QIcon::Off);
        RobocupController->setWindowIcon(icon);
        RobocupController->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        RobocupController->setLocale(QLocale(QLocale::English, QLocale::Australia));
        action_Quit = new QAction(RobocupController);
        action_Quit->setObjectName(QString::fromUtf8("action_Quit"));
        action_Quit->setShortcutContext(Qt::ApplicationShortcut);
        action_Preferences = new QAction(RobocupController);
        action_Preferences->setObjectName(QString::fromUtf8("action_Preferences"));
        actionAbout = new QAction(RobocupController);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAbout_Qt = new QAction(RobocupController);
        actionAbout_Qt->setObjectName(QString::fromUtf8("actionAbout_Qt"));
        centralwidget = new QWidget(RobocupController);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setEnabled(true);
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_title = new QLabel(centralwidget);
        label_title->setObjectName(QString::fromUtf8("label_title"));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu"));
        font.setBold(false);
        font.setWeight(50);
        label_title->setFont(font);
        label_title->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        horizontalLayout_3->addWidget(label_title);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(238, 238, 236);"));

        horizontalLayout_2->addWidget(textEdit);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(5, 0, -1, -1);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMaximumSize(QSize(16777215, 20));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        label_Position = new QLabel(centralwidget);
        label_Position->setObjectName(QString::fromUtf8("label_Position"));
        label_Position->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_Position);

        comboBox_position = new QComboBox(centralwidget);
        comboBox_position->setObjectName(QString::fromUtf8("comboBox_position"));
        comboBox_position->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        formLayout->setWidget(1, QFormLayout::FieldRole, comboBox_position);

        label_State = new QLabel(centralwidget);
        label_State->setObjectName(QString::fromUtf8("label_State"));
        label_State->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_State);

        comboBox_State = new QComboBox(centralwidget);
        comboBox_State->setObjectName(QString::fromUtf8("comboBox_State"));
        comboBox_State->setStyleSheet(QString::fromUtf8("color: rgb(238, 238, 236);"));

        formLayout->setWidget(2, QFormLayout::FieldRole, comboBox_State);


        verticalLayout->addLayout(formLayout);

        Server_Open = new QPushButton(centralwidget);
        Server_Open->setObjectName(QString::fromUtf8("Server_Open"));
        Server_Open->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Server_Open->sizePolicy().hasHeightForWidth());
        Server_Open->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(17);
        Server_Open->setFont(font1);
        Server_Open->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 121, 0);"));

        verticalLayout->addWidget(Server_Open);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout_2->addLayout(verticalLayout_2);


        verticalLayout_4->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);

        RobocupController->setCentralWidget(centralwidget);

        retranslateUi(RobocupController);
        QObject::connect(action_Quit, SIGNAL(triggered()), RobocupController, SLOT(close()));

        comboBox_position->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RobocupController);
    } // setupUi

    void retranslateUi(QMainWindow *RobocupController)
    {
        RobocupController->setWindowTitle(QApplication::translate("RobocupController", "SRCIRC 2023 GAMECONTROLLER ver 1.0", 0, QApplication::UnicodeUTF8));
        action_Quit->setText(QApplication::translate("RobocupController", "&Quit", 0, QApplication::UnicodeUTF8));
        action_Quit->setShortcut(QApplication::translate("RobocupController", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        action_Preferences->setText(QApplication::translate("RobocupController", "&Preferences", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("RobocupController", "&About", 0, QApplication::UnicodeUTF8));
        actionAbout_Qt->setText(QApplication::translate("RobocupController", "About &Qt", 0, QApplication::UnicodeUTF8));
        label_title->setText(QApplication::translate("RobocupController", "<html><head/><body><p align=\"center\"><span style=\" font-size:20pt;\">SRCIRC GAMECONTROLLER23</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("RobocupController", "SETTING", 0, QApplication::UnicodeUTF8));
        label_Position->setText(QApplication::translate("RobocupController", "Position : ", 0, QApplication::UnicodeUTF8));
        comboBox_position->clear();
        comboBox_position->insertItems(0, QStringList()
         << QApplication::translate("RobocupController", "SET POSITION", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RobocupController", "BASKETBALL", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RobocupController", "RUNNING", 0, QApplication::UnicodeUTF8)
        );
        label_State->setText(QApplication::translate("RobocupController", "State       :", 0, QApplication::UnicodeUTF8));
        comboBox_State->clear();
        comboBox_State->insertItems(0, QStringList()
         << QApplication::translate("RobocupController", "State_Playing", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("RobocupController", "State_Finish", 0, QApplication::UnicodeUTF8)
        );
        Server_Open->setText(QApplication::translate("RobocupController", "APLLY", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RobocupController: public Ui_RobocupController {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
