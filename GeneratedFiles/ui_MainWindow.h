/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QWidget *centralWidget;
    QRadioButton *box;
    QRadioButton *line;
    QRadioButton *circle;
    QPushButton *draw;
    QPushButton *move;
    QRadioButton *gon;
    QTextEdit *text;
    QPushButton *read;
    QPushButton *save;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QStringLiteral("MainWindowClass"));
        MainWindowClass->resize(814, 564);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        box = new QRadioButton(centralWidget);
        box->setObjectName(QStringLiteral("box"));
        box->setGeometry(QRect(20, 20, 93, 28));
        line = new QRadioButton(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(100, 20, 115, 19));
        circle = new QRadioButton(centralWidget);
        circle->setObjectName(QStringLiteral("circle"));
        circle->setGeometry(QRect(190, 20, 93, 28));
        draw = new QPushButton(centralWidget);
        draw->setObjectName(QStringLiteral("draw"));
        draw->setGeometry(QRect(40, 80, 93, 28));
        move = new QPushButton(centralWidget);
        move->setObjectName(QStringLiteral("move"));
        move->setGeometry(QRect(160, 80, 93, 28));
        gon = new QRadioButton(centralWidget);
        gon->setObjectName(QStringLiteral("gon"));
        gon->setGeometry(QRect(270, 30, 115, 19));
        text = new QTextEdit(centralWidget);
        text->setObjectName(QStringLiteral("text"));
        text->setGeometry(QRect(500, 40, 101, 31));
        read = new QPushButton(centralWidget);
        read->setObjectName(QStringLiteral("read"));
        read->setGeometry(QRect(390, 60, 93, 28));
        save = new QPushButton(centralWidget);
        save->setObjectName(QStringLiteral("save"));
        save->setGeometry(QRect(390, 20, 93, 28));
        MainWindowClass->setCentralWidget(centralWidget);

        retranslateUi(MainWindowClass);
        QObject::connect(box, SIGNAL(clicked()), MainWindowClass, SLOT(on_box_clicked()));
        QObject::connect(line, SIGNAL(clicked()), MainWindowClass, SLOT(on_line_clicked()));
        QObject::connect(circle, SIGNAL(clicked()), MainWindowClass, SLOT(on_circle_clicked()));
        QObject::connect(move, SIGNAL(clicked()), MainWindowClass, SLOT(on_move_clicked()));
        QObject::connect(draw, SIGNAL(clicked()), MainWindowClass, SLOT(on_draw_clicked()));
        QObject::connect(gon, SIGNAL(clicked()), MainWindowClass, SLOT(on_gon_clicked()));

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "MainWindow", Q_NULLPTR));
        box->setText(QApplication::translate("MainWindowClass", "box", Q_NULLPTR));
        line->setText(QApplication::translate("MainWindowClass", "line", Q_NULLPTR));
        circle->setText(QApplication::translate("MainWindowClass", "circle", Q_NULLPTR));
        draw->setText(QApplication::translate("MainWindowClass", "draw", Q_NULLPTR));
        move->setText(QApplication::translate("MainWindowClass", "move", Q_NULLPTR));
        gon->setText(QApplication::translate("MainWindowClass", "gon", Q_NULLPTR));
        read->setText(QApplication::translate("MainWindowClass", "read", Q_NULLPTR));
        save->setText(QApplication::translate("MainWindowClass", "save", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
