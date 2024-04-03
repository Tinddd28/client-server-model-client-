/********************************************************************************
** Form generated from reading UI file 'orders.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERS_H
#define UI_ORDERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_orders
{
public:
    QTableWidget *tableWidget;
    QPushButton *back;

    void setupUi(QWidget *orders)
    {
        if (orders->objectName().isEmpty())
            orders->setObjectName(QString::fromUtf8("orders"));
        orders->resize(596, 433);
        tableWidget = new QTableWidget(orders);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(40, 30, 511, 311));
        QFont font;
        font.setPointSize(12);
        tableWidget->setFont(font);
        back = new QPushButton(orders);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(450, 380, 93, 28));
        back->setFont(font);

        retranslateUi(orders);

        QMetaObject::connectSlotsByName(orders);
    } // setupUi

    void retranslateUi(QWidget *orders)
    {
        orders->setWindowTitle(QCoreApplication::translate("orders", "Form", nullptr));
        back->setText(QCoreApplication::translate("orders", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class orders: public Ui_orders {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERS_H
