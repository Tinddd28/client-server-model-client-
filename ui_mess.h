/********************************************************************************
** Form generated from reading UI file 'mess.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESS_H
#define UI_MESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mess
{
public:
    QTableWidget *tableWidget;
    QPushButton *back;

    void setupUi(QWidget *mess)
    {
        if (mess->objectName().isEmpty())
            mess->setObjectName(QString::fromUtf8("mess"));
        mess->resize(654, 499);
        tableWidget = new QTableWidget(mess);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(40, 20, 571, 361));
        QFont font;
        font.setPointSize(12);
        tableWidget->setFont(font);
        back = new QPushButton(mess);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(510, 440, 93, 28));
        back->setFont(font);

        retranslateUi(mess);

        QMetaObject::connectSlotsByName(mess);
    } // setupUi

    void retranslateUi(QWidget *mess)
    {
        mess->setWindowTitle(QCoreApplication::translate("mess", "Form", nullptr));
        back->setText(QCoreApplication::translate("mess", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mess: public Ui_mess {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESS_H
