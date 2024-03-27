/********************************************************************************
** Form generated from reading UI file 'markmanager.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MARKMANAGER_H
#define UI_MARKMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_markmanager
{
public:

    void setupUi(QWidget *markmanager)
    {
        if (markmanager->objectName().isEmpty())
            markmanager->setObjectName(QString::fromUtf8("markmanager"));
        markmanager->resize(572, 483);

        retranslateUi(markmanager);

        QMetaObject::connectSlotsByName(markmanager);
    } // setupUi

    void retranslateUi(QWidget *markmanager)
    {
        markmanager->setWindowTitle(QCoreApplication::translate("markmanager", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class markmanager: public Ui_markmanager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MARKMANAGER_H
