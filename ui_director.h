/********************************************************************************
** Form generated from reading UI file 'director.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIRECTOR_H
#define UI_DIRECTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_director
{
public:
    QPushButton *back;
    QPushButton *data;
    QPushButton *report;
    QPushButton *archive;
    QPushButton *users;
    QPushButton *us;

    void setupUi(QWidget *director)
    {
        if (director->objectName().isEmpty())
            director->setObjectName(QString::fromUtf8("director"));
        director->resize(656, 362);
        back = new QPushButton(director);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(480, 280, 101, 31));
        QFont font;
        font.setPointSize(12);
        back->setFont(font);
        data = new QPushButton(director);
        data->setObjectName(QString::fromUtf8("data"));
        data->setGeometry(QRect(30, 40, 191, 41));
        data->setFont(font);
        report = new QPushButton(director);
        report->setObjectName(QString::fromUtf8("report"));
        report->setGeometry(QRect(230, 40, 191, 41));
        report->setFont(font);
        archive = new QPushButton(director);
        archive->setObjectName(QString::fromUtf8("archive"));
        archive->setGeometry(QRect(430, 40, 191, 41));
        archive->setFont(font);
        users = new QPushButton(director);
        users->setObjectName(QString::fromUtf8("users"));
        users->setGeometry(QRect(60, 150, 291, 41));
        users->setFont(font);
        us = new QPushButton(director);
        us->setObjectName(QString::fromUtf8("us"));
        us->setGeometry(QRect(380, 150, 211, 41));
        us->setFont(font);

        retranslateUi(director);

        QMetaObject::connectSlotsByName(director);
    } // setupUi

    void retranslateUi(QWidget *director)
    {
        director->setWindowTitle(QCoreApplication::translate("director", "Form", nullptr));
        back->setText(QCoreApplication::translate("director", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        data->setText(QCoreApplication::translate("director", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        report->setText(QCoreApplication::translate("director", "\320\241\320\276\320\267\320\264\320\260\320\275\320\270\320\265 \320\276\321\202\321\207\321\221\321\202\320\260", nullptr));
        archive->setText(QCoreApplication::translate("director", "\320\240\320\260\320\261\320\276\321\202\320\260 \321\201 \320\260\321\200\321\205\320\270\320\262\320\276\320\274", nullptr));
        users->setText(QCoreApplication::translate("director", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217\320\274\320\270", nullptr));
        us->setText(QCoreApplication::translate("director", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\320\265\320\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class director: public Ui_director {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIRECTOR_H
