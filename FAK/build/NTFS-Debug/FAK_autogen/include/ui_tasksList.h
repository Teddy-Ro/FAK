/********************************************************************************
** Form generated from reading UI file 'tasksList.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TASKSLIST_H
#define UI_TASKSLIST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "tasksList.h"

QT_BEGIN_NAMESPACE

class Ui_tasksList
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLineEdit *textInput;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *buttonsLayout;

    void setupUi(tasksList *tasksList)
    {
        if (tasksList->objectName().isEmpty())
            tasksList->setObjectName("tasksList");
        tasksList->resize(800, 600);
        tasksList->setStyleSheet(QString::fromUtf8("tasksList {\n"
"    background-color: #310E10; /* Black bean */\n"
"    color: #F4E3B2; /* Vanilla */\n"
"}\n"
"\n"
"QLineEdit {\n"
"    background-color: #947268; /* Cinerious */\n"
"    color: #74070E; /* Blood red */\n"
"    border: 1px solid #74070E;\n"
"    border-radius: 4px;\n"
"    padding: 5px 10px;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #74070E;\n"
"}\n"
"\n"
"QScrollArea {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"    background: #947268; /* Cinerious */\n"
"    width: 10px;\n"
"    margin: 0px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: #74070E; /* Blood red */\n"
"    min-height: 20px;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical,\n"
"QScrollBar::sub-line:vertical {\n"
"    background: none;\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: #F4E3B2; /* Vanilla */\n"
"    color: #74070E; /* Blood red */\n"
"    border: none;\n"
"    border-r"
                        "adius: 4px;\n"
"    padding: 8px 15px;\n"
"    font-size: 14px;\n"
"    text-align: left;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(244, 227, 178, 0.8); /* Vanilla 80% */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: rgba(244, 227, 178, 0.6); /* Vanilla 60% */\n"
"}\n"
"\n"
"QCheckBox {\n"
"    color: #F4E3B2; /* Vanilla */\n"
"    spacing: 5px;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"    width: 16px;\n"
"    height: 16px;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked {\n"
"    background-color: #74070E; /* Blood red */\n"
"    border: 1px solid #74070E;\n"
"}\n"
"\n"
"QCheckBox::indicator:unchecked {\n"
"    background-color: #947268; /* Cinerious */\n"
"    border: 1px solid #74070E;\n"
"}"));
        horizontalLayout = new QHBoxLayout(tasksList);
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        textInput = new QLineEdit(tasksList);
        textInput->setObjectName("textInput");
        textInput->setStyleSheet(QString::fromUtf8("background-color: #947268;\n"
"color: #74070E;\n"
"border: 1px solid #74070E;\n"
"border-radius: 4px;\n"
"padding: 8px 12px;\n"
"font-size: 14px;"));

        verticalLayout->addWidget(textInput);

        scrollArea = new QScrollArea(tasksList);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollArea->setStyleSheet(QString::fromUtf8("background-color: transparent;\n"
"border: none;"));
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 776, 546));
        scrollAreaWidgetContents->setStyleSheet(QString::fromUtf8("background-color: #310E10;"));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setObjectName("verticalLayout_3");
        buttonsLayout = new QVBoxLayout();
        buttonsLayout->setObjectName("buttonsLayout");

        verticalLayout_3->addLayout(buttonsLayout);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        verticalLayout_2->addLayout(verticalLayout);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(tasksList);

        QMetaObject::connectSlotsByName(tasksList);
    } // setupUi

    void retranslateUi(tasksList *tasksList)
    {
        tasksList->setWindowTitle(QCoreApplication::translate("tasksList", "\320\234\320\276\320\271 \320\264\320\265\320\275\321\214", nullptr));
        textInput->setPlaceholderText(QCoreApplication::translate("tasksList", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\202\320\265\320\272\321\201\321\202 \320\270 \320\275\320\260\320\266\320\274\320\270\321\202\320\265 Enter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tasksList: public Ui_tasksList {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TASKSLIST_H
