/********************************************************************************
** Form generated from reading UI file 'dataout.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAOUT_H
#define UI_DATAOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dataout
{
public:
    QPushButton *items;
    QPushButton *clients;
    QPushButton *orders;
    QPushButton *messages;
    QPushButton *sales;
    QPushButton *backb;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *dataout)
    {
        if (dataout->objectName().isEmpty())
            dataout->setObjectName(QString::fromUtf8("dataout"));
        dataout->resize(708, 329);
        items = new QPushButton(dataout);
        items->setObjectName(QString::fromUtf8("items"));
        items->setGeometry(QRect(41, 31, 177, 41));
        QFont font;
        font.setPointSize(12);
        items->setFont(font);
        clients = new QPushButton(dataout);
        clients->setObjectName(QString::fromUtf8("clients"));
        clients->setGeometry(QRect(258, 31, 188, 41));
        clients->setFont(font);
        orders = new QPushButton(dataout);
        orders->setObjectName(QString::fromUtf8("orders"));
        orders->setGeometry(QRect(485, 31, 175, 41));
        orders->setFont(font);
        messages = new QPushButton(dataout);
        messages->setObjectName(QString::fromUtf8("messages"));
        messages->setGeometry(QRect(100, 110, 221, 41));
        messages->setFont(font);
        sales = new QPushButton(dataout);
        sales->setObjectName(QString::fromUtf8("sales"));
        sales->setGeometry(QRect(390, 110, 191, 41));
        sales->setFont(font);
        backb = new QPushButton(dataout);
        backb->setObjectName(QString::fromUtf8("backb"));
        backb->setGeometry(QRect(500, 250, 121, 41));
        backb->setFont(font);
        label = new QLabel(dataout);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(224, 31, 28, 33));
        label_2 = new QLabel(dataout);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(452, 31, 27, 33));

        retranslateUi(dataout);

        QMetaObject::connectSlotsByName(dataout);
    } // setupUi

    void retranslateUi(QWidget *dataout)
    {
        dataout->setWindowTitle(QCoreApplication::translate("dataout", "Form", nullptr));
        items->setText(QCoreApplication::translate("dataout", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \321\202\320\276\320\262\320\260\321\200\320\276\320\262", nullptr));
        clients->setText(QCoreApplication::translate("dataout", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \320\272\320\273\320\270\320\265\320\275\321\202\320\276\320\262", nullptr));
        orders->setText(QCoreApplication::translate("dataout", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \320\267\320\260\320\272\320\260\320\267\320\276\320\262", nullptr));
        messages->setText(QCoreApplication::translate("dataout", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\271", nullptr));
        sales->setText(QCoreApplication::translate("dataout", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \321\201\320\272\320\270\320\264\320\276\320\272", nullptr));
        backb->setText(QCoreApplication::translate("dataout", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        label->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class dataout: public Ui_dataout {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAOUT_H
