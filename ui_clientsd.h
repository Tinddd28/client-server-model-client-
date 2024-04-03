/********************************************************************************
** Form generated from reading UI file 'clientsd.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTSD_H
#define UI_CLIENTSD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_clientsd
{
public:
    QPushButton *back;
    QTableWidget *tableWidget;

    void setupUi(QWidget *clientsd)
    {
        if (clientsd->objectName().isEmpty())
            clientsd->setObjectName(QString::fromUtf8("clientsd"));
        clientsd->resize(620, 468);
        back = new QPushButton(clientsd);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(500, 420, 93, 28));
        QFont font;
        font.setPointSize(12);
        back->setFont(font);
        tableWidget = new QTableWidget(clientsd);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(30, 20, 551, 361));

        retranslateUi(clientsd);

        QMetaObject::connectSlotsByName(clientsd);
    } // setupUi

    void retranslateUi(QWidget *clientsd)
    {
        clientsd->setWindowTitle(QCoreApplication::translate("clientsd", "Form", nullptr));
        back->setText(QCoreApplication::translate("clientsd", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class clientsd: public Ui_clientsd {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTSD_H
