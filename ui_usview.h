/********************************************************************************
** Form generated from reading UI file 'usview.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USVIEW_H
#define UI_USVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_usview
{
public:
    QTableWidget *tableWidget;
    QPushButton *back;

    void setupUi(QWidget *usview)
    {
        if (usview->objectName().isEmpty())
            usview->setObjectName(QString::fromUtf8("usview"));
        usview->resize(674, 519);
        tableWidget = new QTableWidget(usview);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(40, 30, 591, 361));
        back = new QPushButton(usview);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(520, 460, 93, 28));
        QFont font;
        font.setPointSize(12);
        back->setFont(font);

        retranslateUi(usview);

        QMetaObject::connectSlotsByName(usview);
    } // setupUi

    void retranslateUi(QWidget *usview)
    {
        usview->setWindowTitle(QCoreApplication::translate("usview", "Form", nullptr));
        back->setText(QCoreApplication::translate("usview", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class usview: public Ui_usview {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USVIEW_H
