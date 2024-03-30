/********************************************************************************
** Form generated from reading UI file 'order.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDER_H
#define UI_ORDER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_order
{
public:
    QLabel *label_9;
    QLabel *label;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_5;
    QLineEdit *name;
    QLabel *label_6;
    QLineEdit *surname;
    QLabel *label_7;
    QLineEdit *mail;
    QLabel *label_8;
    QLineEdit *phone;
    QWidget *layoutWidget1;
    QFormLayout *formLayout;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *amount;
    QLineEdit *price;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QPushButton *back;
    QPushButton *order_2;
    QComboBox *comboBox;
    QLabel *havee;

    void setupUi(QWidget *order)
    {
        if (order->objectName().isEmpty())
            order->setObjectName(QString::fromUtf8("order"));
        order->resize(587, 460);
        label_9 = new QLabel(order);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(120, 220, 148, 24));
        QFont font;
        font.setPointSize(12);
        label_9->setFont(font);
        label = new QLabel(order);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 20, 271, 24));
        label->setFont(font);
        layoutWidget = new QWidget(order);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(170, 70, 266, 140));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 0, 0, 1, 1);

        name = new QLineEdit(layoutWidget);
        name->setObjectName(QString::fromUtf8("name"));
        name->setFont(font);

        gridLayout->addWidget(name, 0, 1, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        surname = new QLineEdit(layoutWidget);
        surname->setObjectName(QString::fromUtf8("surname"));
        surname->setFont(font);

        gridLayout->addWidget(surname, 1, 1, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 2, 0, 1, 1);

        mail = new QLineEdit(layoutWidget);
        mail->setObjectName(QString::fromUtf8("mail"));
        mail->setFont(font);

        gridLayout->addWidget(mail, 2, 1, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        gridLayout->addWidget(label_8, 3, 0, 1, 1);

        phone = new QLineEdit(layoutWidget);
        phone->setObjectName(QString::fromUtf8("phone"));
        phone->setFont(font);

        gridLayout->addWidget(phone, 3, 1, 1, 1);

        layoutWidget1 = new QWidget(order);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(140, 300, 319, 98));
        layoutWidget1->setFont(font);
        formLayout = new QFormLayout(layoutWidget1);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        amount = new QLineEdit(layoutWidget1);
        amount->setObjectName(QString::fromUtf8("amount"));
        amount->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, amount);

        price = new QLineEdit(layoutWidget1);
        price->setObjectName(QString::fromUtf8("price"));
        price->setFont(font);

        formLayout->setWidget(1, QFormLayout::FieldRole, price);

        layoutWidget2 = new QWidget(order);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(200, 400, 204, 35));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        back = new QPushButton(layoutWidget2);
        back->setObjectName(QString::fromUtf8("back"));
        back->setFont(font);

        horizontalLayout->addWidget(back);

        order_2 = new QPushButton(layoutWidget2);
        order_2->setObjectName(QString::fromUtf8("order_2"));
        order_2->setFont(font);

        horizontalLayout->addWidget(order_2);

        comboBox = new QComboBox(order);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(274, 220, 201, 30));
        comboBox->setFont(font);
        havee = new QLabel(order);
        havee->setObjectName(QString::fromUtf8("havee"));
        havee->setGeometry(QRect(140, 260, 321, 31));
        havee->setFont(font);

        retranslateUi(order);

        QMetaObject::connectSlotsByName(order);
    } // setupUi

    void retranslateUi(QWidget *order)
    {
        order->setWindowTitle(QCoreApplication::translate("order", "Form", nullptr));
        label_9->setText(QCoreApplication::translate("order", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\202\320\276\320\262\320\260\321\200", nullptr));
        label->setText(QCoreApplication::translate("order", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276 \320\272\320\273\320\270\320\265\320\275\321\202\320\265", nullptr));
        label_5->setText(QCoreApplication::translate("order", "\320\230\320\274\321\217", nullptr));
        name->setText(QString());
        label_6->setText(QCoreApplication::translate("order", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        label_7->setText(QCoreApplication::translate("order", "\320\237\320\276\321\207\321\202\320\260", nullptr));
        label_8->setText(QCoreApplication::translate("order", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        label_2->setText(QCoreApplication::translate("order", "\320\241\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214", nullptr));
        label_4->setText(QCoreApplication::translate("order", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        back->setText(QCoreApplication::translate("order", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        order_2->setText(QCoreApplication::translate("order", "\320\236\321\204\320\276\321\200\320\274\320\270\321\202\321\214", nullptr));
        havee->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class order: public Ui_order {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDER_H
