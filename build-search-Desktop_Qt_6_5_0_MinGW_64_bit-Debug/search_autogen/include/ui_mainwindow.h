/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *path;
    QLabel *label_2;
    QLineEdit *keyword;
    QPushButton *search;
    QTextEdit *result;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(450, 306);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(80, 20, 91, 21));
        path = new QLineEdit(centralwidget);
        path->setObjectName("path");
        path->setGeometry(QRect(10, 50, 211, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(300, 20, 111, 20));
        keyword = new QLineEdit(centralwidget);
        keyword->setObjectName("keyword");
        keyword->setGeometry(QRect(242, 50, 201, 20));
        search = new QPushButton(centralwidget);
        search->setObjectName("search");
        search->setGeometry(QRect(130, 280, 161, 20));
        result = new QTextEdit(centralwidget);
        result->setObjectName("result");
        result->setGeometry(QRect(33, 93, 391, 171));
        result->setReadOnly(true);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "path to search in", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "keyword or line", nullptr));
        search->setText(QCoreApplication::translate("MainWindow", "search", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
