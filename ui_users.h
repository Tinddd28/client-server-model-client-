/********************************************************************************
** Form generated from reading UI file 'users.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERS_H
#define UI_USERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_users
{
public:
    QPushButton *create;
    QPushButton *edit;
    QPushButton *delete_2;
    QPushButton *back;

    void setupUi(QWidget *users)
    {
        if (users->objectName().isEmpty())
            users->setObjectName(QString::fromUtf8("users"));
        users->resize(495, 440);
        create = new QPushButton(users);
        create->setObjectName(QString::fromUtf8("create"));
        create->setGeometry(QRect(100, 20, 301, 61));
        QFont font;
        font.setPointSize(12);
        create->setFont(font);
        edit = new QPushButton(users);
        edit->setObjectName(QString::fromUtf8("edit"));
        edit->setGeometry(QRect(100, 110, 301, 61));
        edit->setFont(font);
        delete_2 = new QPushButton(users);
        delete_2->setObjectName(QString::fromUtf8("delete_2"));
        delete_2->setGeometry(QRect(100, 200, 301, 61));
        delete_2->setFont(font);
        back = new QPushButton(users);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(100, 300, 301, 61));
        back->setFont(font);

        retranslateUi(users);

        QMetaObject::connectSlotsByName(users);
    } // setupUi

    void retranslateUi(QWidget *users)
    {
        users->setWindowTitle(QCoreApplication::translate("users", "Form", nullptr));
        create->setText(QCoreApplication::translate("users", "\320\241\320\276\320\267\320\264\320\260\320\275\320\270\320\265 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        edit->setText(QCoreApplication::translate("users", "\320\240\320\265\320\264\320\260\320\272\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        delete_2->setText(QCoreApplication::translate("users", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        back->setText(QCoreApplication::translate("users", "\320\222\320\265\321\200\320\275\321\203\321\202\321\214\321\201\321\217 \320\262 \320\274\320\265\320\275\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class users: public Ui_users {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERS_H
