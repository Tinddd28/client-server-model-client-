/********************************************************************************
** Form generated from reading UI file 'items.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ITEMS_H
#define UI_ITEMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_items
{
public:
    QTableWidget *tableWidget;
    QPushButton *pushButton;

    void setupUi(QWidget *items)
    {
        if (items->objectName().isEmpty())
            items->setObjectName(QString::fromUtf8("items"));
        items->resize(690, 511);
        tableWidget = new QTableWidget(items);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(20, 20, 651, 391));
        pushButton = new QPushButton(items);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(530, 440, 93, 28));
        QFont font;
        font.setPointSize(12);
        pushButton->setFont(font);

        retranslateUi(items);

        QMetaObject::connectSlotsByName(items);
    } // setupUi

    void retranslateUi(QWidget *items)
    {
        items->setWindowTitle(QCoreApplication::translate("items", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("items", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class items: public Ui_items {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ITEMS_H
