/********************************************************************************
** Form generated from reading UI file 'itemsd.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ITEMSD_H
#define UI_ITEMSD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_itemsd
{
public:
    QPushButton *back;
    QTableWidget *tableWidget;

    void setupUi(QWidget *itemsd)
    {
        if (itemsd->objectName().isEmpty())
            itemsd->setObjectName(QString::fromUtf8("itemsd"));
        itemsd->resize(611, 434);
        back = new QPushButton(itemsd);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(460, 380, 93, 28));
        QFont font;
        font.setPointSize(12);
        back->setFont(font);
        tableWidget = new QTableWidget(itemsd);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(30, 20, 541, 341));

        retranslateUi(itemsd);

        QMetaObject::connectSlotsByName(itemsd);
    } // setupUi

    void retranslateUi(QWidget *itemsd)
    {
        itemsd->setWindowTitle(QCoreApplication::translate("itemsd", "Form", nullptr));
        back->setText(QCoreApplication::translate("itemsd", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class itemsd: public Ui_itemsd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ITEMSD_H
