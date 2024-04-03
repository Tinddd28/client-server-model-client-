/********************************************************************************
** Form generated from reading UI file 'clients.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTS_H
#define UI_CLIENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_clients
{
public:
    QPushButton *back;
    QTableWidget *tableWidget;

    void setupUi(QWidget *clients)
    {
        if (clients->objectName().isEmpty())
            clients->setObjectName(QString::fromUtf8("clients"));
        clients->resize(657, 483);
        back = new QPushButton(clients);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(510, 420, 93, 28));
        QFont font;
        font.setPointSize(12);
        back->setFont(font);
        tableWidget = new QTableWidget(clients);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(40, 30, 581, 361));

        retranslateUi(clients);

        QMetaObject::connectSlotsByName(clients);
    } // setupUi

    void retranslateUi(QWidget *clients)
    {
        clients->setWindowTitle(QCoreApplication::translate("clients", "Form", nullptr));
        back->setText(QCoreApplication::translate("clients", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class clients: public Ui_clients {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTS_H
