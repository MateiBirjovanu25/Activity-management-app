/********************************************************************************
** Form generated from reading UI file 'v2.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_V2_H
#define UI_V2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_v2Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *v2Class)
    {
        if (v2Class->objectName().isEmpty())
            v2Class->setObjectName(QString::fromUtf8("v2Class"));
        v2Class->resize(600, 400);
        menuBar = new QMenuBar(v2Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        v2Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(v2Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        v2Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(v2Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        v2Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(v2Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        v2Class->setStatusBar(statusBar);

        retranslateUi(v2Class);

        QMetaObject::connectSlotsByName(v2Class);
    } // setupUi

    void retranslateUi(QMainWindow *v2Class)
    {
        v2Class->setWindowTitle(QCoreApplication::translate("v2Class", "v2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class v2Class: public Ui_v2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_V2_H
