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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_director
{
public:

    void setupUi(QWidget *director)
    {
        if (director->objectName().isEmpty())
            director->setObjectName(QString::fromUtf8("director"));
        director->resize(628, 445);

        retranslateUi(director);

        QMetaObject::connectSlotsByName(director);
    } // setupUi

    void retranslateUi(QWidget *director)
    {
        director->setWindowTitle(QCoreApplication::translate("director", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class director: public Ui_director {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIRECTOR_H
