/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QWidget *headerWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *logoLabel;
    QLineEdit *searchEdit;
    QSpacerItem *horizontalSpacer;
    QPushButton *addButton;
    QPushButton *notificationButton;
    QPushButton *profileButton;
    QWidget *contentWidget;
    QHBoxLayout *horizontalLayout_3;
    QWidget *sidebarWidget;
    QVBoxLayout *verticalLayout;
    QFrame *sidebarFrame;
    QVBoxLayout *verticalLayout_21;
    QWidget *myDayWidget;
    QHBoxLayout *horizontalLayout1;
    QPushButton *myDayButton;
    QWidget *importantWidget;
    QHBoxLayout *horizontalLayout_21;
    QPushButton *importantButton;
    QWidget *plannedWidget;
    QHBoxLayout *horizontalLayout_31;
    QPushButton *plannedButton;
    QWidget *assignedWidget;
    QHBoxLayout *horizontalLayout_4;
    QWidget *flaggedWidget;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *flaggedButton;
    QWidget *tasksWidget;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_6;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QWidget *tasksWidget1;
    QVBoxLayout *verticalLayout_3;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_5;
    QPushButton *changeButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1000, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: rgb(12, 22, 24);"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        headerWidget = new QWidget(widget);
        headerWidget->setObjectName("headerWidget");
        headerWidget->setMinimumSize(QSize(0, 50));
        headerWidget->setAutoFillBackground(false);
        headerWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(38, 34, 47)"));
        horizontalLayout_2 = new QHBoxLayout(headerWidget);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        logoLabel = new QLabel(headerWidget);
        logoLabel->setObjectName("logoLabel");
        logoLabel->setMinimumSize(QSize(30, 30));
        logoLabel->setMaximumSize(QSize(30, 30));

        horizontalLayout_2->addWidget(logoLabel);

        searchEdit = new QLineEdit(headerWidget);
        searchEdit->setObjectName("searchEdit");
        searchEdit->setMinimumSize(QSize(200, 30));
        searchEdit->setMaximumSize(QSize(300, 30));
        searchEdit->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 255, 255, 50);\n"
"border-radius: 15px;\n"
"padding-left: 10px;\n"
"color: white;\n"
""));

        horizontalLayout_2->addWidget(searchEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        addButton = new QPushButton(headerWidget);
        addButton->setObjectName("addButton");
        addButton->setMinimumSize(QSize(30, 30));
        addButton->setMaximumSize(QSize(30, 30));
        addButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    font-size: 20px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 50);\n"
"    border-radius: 15px;\n"
"}"));

        horizontalLayout_2->addWidget(addButton);

        notificationButton = new QPushButton(headerWidget);
        notificationButton->setObjectName("notificationButton");
        notificationButton->setMinimumSize(QSize(30, 30));
        notificationButton->setMaximumSize(QSize(30, 30));
        notificationButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    font-size: 16px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 50);\n"
"    border-radius: 15px;\n"
"}"));

        horizontalLayout_2->addWidget(notificationButton);

        profileButton = new QPushButton(headerWidget);
        profileButton->setObjectName("profileButton");
        profileButton->setMinimumSize(QSize(30, 30));
        profileButton->setMaximumSize(QSize(30, 30));
        profileButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: white;\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    font-size: 16px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 50);\n"
"    border-radius: 15px;\n"
"}"));

        horizontalLayout_2->addWidget(profileButton);


        verticalLayout_2->addWidget(headerWidget);

        contentWidget = new QWidget(widget);
        contentWidget->setObjectName("contentWidget");
        horizontalLayout_3 = new QHBoxLayout(contentWidget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        sidebarWidget = new QWidget(contentWidget);
        sidebarWidget->setObjectName("sidebarWidget");
        sidebarWidget->setMinimumSize(QSize(250, 0));
        sidebarWidget->setMaximumSize(QSize(250, 16777215));
        sidebarWidget->setAutoFillBackground(false);
        sidebarWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(19, 17, 24)\n"
""));
        verticalLayout = new QVBoxLayout(sidebarWidget);
        verticalLayout->setObjectName("verticalLayout");
        sidebarFrame = new QFrame(sidebarWidget);
        sidebarFrame->setObjectName("sidebarFrame");
        sidebarFrame->setMaximumSize(QSize(16777215, 300));
        sidebarFrame->setStyleSheet(QString::fromUtf8("QFrame {\n"
"                background-color: #1e1e1e;\n"
"                color: white;\n"
"				 border-radius: 10px;\n"
"                }\n"
"\n"
"                QLabel {\n"
"                color: #888888;\n"
"                font-size: 14px;\n"
"                border-radius: 5px;\n"
"\n"
"                }\n"
"\n"
"                QPushButton {\n"
"                border: none;\n"
"                text-align: left;\n"
"                padding: 10px;\n"
"                color: white;\n"
"                font-size: 16px;\n"
"                background-color: transparent;\n"
"                }\n"
"\n"
"                QPushButton:hover {\n"
"                background-color: #333333;\n"
"                border-radius: 5px;\n"
"\n"
"                }\n"
"\n"
"                QPushButton#tasksButton {\n"
"                background-color: #333333;\n"
"                border-left: 3px solid #3b7be0;\n"
"                }\n"
""));
        sidebarFrame->setFrameShape(QFrame::NoFrame);
        verticalLayout_21 = new QVBoxLayout(sidebarFrame);
        verticalLayout_21->setSpacing(2);
        verticalLayout_21->setObjectName("verticalLayout_21");
        verticalLayout_21->setContentsMargins(10, 10, 10, 10);
        myDayWidget = new QWidget(sidebarFrame);
        myDayWidget->setObjectName("myDayWidget");
        horizontalLayout1 = new QHBoxLayout(myDayWidget);
        horizontalLayout1->setObjectName("horizontalLayout1");
        horizontalLayout1->setContentsMargins(0, 0, 0, 0);
        myDayButton = new QPushButton(myDayWidget);
        myDayButton->setObjectName("myDayButton");
        QIcon icon;
        icon.addFile(QString::fromUtf8("icons/sun.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        myDayButton->setIcon(icon);

        horizontalLayout1->addWidget(myDayButton);


        verticalLayout_21->addWidget(myDayWidget);

        importantWidget = new QWidget(sidebarFrame);
        importantWidget->setObjectName("importantWidget");
        horizontalLayout_21 = new QHBoxLayout(importantWidget);
        horizontalLayout_21->setObjectName("horizontalLayout_21");
        horizontalLayout_21->setContentsMargins(0, 0, 0, 0);
        importantButton = new QPushButton(importantWidget);
        importantButton->setObjectName("importantButton");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("icons/star.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        importantButton->setIcon(icon1);

        horizontalLayout_21->addWidget(importantButton);


        verticalLayout_21->addWidget(importantWidget);

        plannedWidget = new QWidget(sidebarFrame);
        plannedWidget->setObjectName("plannedWidget");
        horizontalLayout_31 = new QHBoxLayout(plannedWidget);
        horizontalLayout_31->setObjectName("horizontalLayout_31");
        horizontalLayout_31->setContentsMargins(0, 0, 0, 0);
        plannedButton = new QPushButton(plannedWidget);
        plannedButton->setObjectName("plannedButton");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("icons/calendar.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        plannedButton->setIcon(icon2);

        horizontalLayout_31->addWidget(plannedButton);


        verticalLayout_21->addWidget(plannedWidget);

        assignedWidget = new QWidget(sidebarFrame);
        assignedWidget->setObjectName("assignedWidget");
        horizontalLayout_4 = new QHBoxLayout(assignedWidget);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);

        verticalLayout_21->addWidget(assignedWidget);

        flaggedWidget = new QWidget(sidebarFrame);
        flaggedWidget->setObjectName("flaggedWidget");
        horizontalLayout_5 = new QHBoxLayout(flaggedWidget);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        flaggedButton = new QPushButton(flaggedWidget);
        flaggedButton->setObjectName("flaggedButton");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("icons/flag.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        flaggedButton->setIcon(icon3);

        horizontalLayout_5->addWidget(flaggedButton);


        verticalLayout_21->addWidget(flaggedWidget);

        tasksWidget = new QWidget(sidebarFrame);
        tasksWidget->setObjectName("tasksWidget");
        horizontalLayout_6 = new QHBoxLayout(tasksWidget);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);

        verticalLayout_21->addWidget(tasksWidget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_21->addItem(verticalSpacer);


        verticalLayout->addWidget(sidebarFrame);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        widget_2 = new QWidget(sidebarWidget);
        widget_2->setObjectName("widget_2");
        verticalLayout_4 = new QVBoxLayout(widget_2);
        verticalLayout_4->setObjectName("verticalLayout_4");
        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName("pushButton_2");

        verticalLayout_4->addWidget(pushButton_2);

        pushButton = new QPushButton(widget_2);
        pushButton->setObjectName("pushButton");

        verticalLayout_4->addWidget(pushButton);


        verticalLayout_6->addWidget(widget_2);


        verticalLayout->addLayout(verticalLayout_6);

        verticalLayout->setStretch(0, 1);

        horizontalLayout_3->addWidget(sidebarWidget);

        tasksWidget1 = new QWidget(contentWidget);
        tasksWidget1->setObjectName("tasksWidget1");
        tasksWidget1->setStyleSheet(QString::fromUtf8("background-color: rgb(12, 22, 24)"));
        verticalLayout_3 = new QVBoxLayout(tasksWidget1);
        verticalLayout_3->setObjectName("verticalLayout_3");
        widget_3 = new QWidget(tasksWidget1);
        widget_3->setObjectName("widget_3");
        verticalLayout_5 = new QVBoxLayout(widget_3);
        verticalLayout_5->setObjectName("verticalLayout_5");
        changeButton = new QPushButton(widget_3);
        changeButton->setObjectName("changeButton");

        verticalLayout_5->addWidget(changeButton);


        verticalLayout_3->addWidget(widget_3);


        horizontalLayout_3->addWidget(tasksWidget1);


        verticalLayout_2->addWidget(contentWidget);


        horizontalLayout->addWidget(widget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\274\320\265\321\202\320\272\320\270 \320\270 \320\267\320\260\320\264\320\260\321\207\320\270", nullptr));
        logoLabel->setText(QString());
        searchEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "\320\221\321\213\321\201\321\202\321\200\321\213\320\271 \320\277\320\276\320\270\321\201\320\272", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        notificationButton->setText(QCoreApplication::translate("MainWindow", "\360\237\224\224", nullptr));
        profileButton->setText(QCoreApplication::translate("MainWindow", "\360\237\221\244", nullptr));
        myDayButton->setText(QCoreApplication::translate("MainWindow", "  \320\234\320\276\320\271 \320\264\320\265\320\275\321\214", nullptr));
        importantButton->setText(QCoreApplication::translate("MainWindow", "  \320\222\320\260\320\266\320\275\320\276", nullptr));
        plannedButton->setText(QCoreApplication::translate("MainWindow", "  \320\227\320\260\320\277\320\273\320\260\320\275\320\270\321\200\320\276\320\262\320\260\320\275\320\276", nullptr));
        flaggedButton->setText(QCoreApplication::translate("MainWindow", "  \320\237\320\276\320\274\320\265\321\207\320\265\320\275\320\275\321\213\320\265 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\321\217", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        changeButton->setText(QCoreApplication::translate("MainWindow", "changeButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
