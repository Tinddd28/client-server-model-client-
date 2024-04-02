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
    QPushButton *pushButton;

    void setupUi(QWidget *director)
    {
        if (director->objectName().isEmpty())
            director->setObjectName(QString::fromUtf8("director"));
        director->resize(628, 445);
        pushButton = new QPushButton(director);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(472, 387, 101, 31));
        QFont font;
        font.setPointSize(12);
        pushButton->setFont(font);

        retranslateUi(director);

        QMetaObject::connectSlotsByName(director);
    } // setupUi

    void retranslateUi(QWidget *director)
    {
        director->setWindowTitle(QCoreApplication::translate("director", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("director", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class director: public Ui_director {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIRECTOR_H
