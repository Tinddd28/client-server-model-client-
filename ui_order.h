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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_order
{
public:
    QPushButton *order_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QComboBox *comboBox;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *price;

    void setupUi(QWidget *order)
    {
        if (order->objectName().isEmpty())
            order->setObjectName(QString::fromUtf8("order"));
        order->resize(437, 334);
        order_2 = new QPushButton(order);
        order_2->setObjectName(QString::fromUtf8("order_2"));
        order_2->setGeometry(QRect(150, 250, 141, 31));
        QFont font;
        font.setPointSize(12);
        order_2->setFont(font);
        widget = new QWidget(order);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(120, 50, 209, 168));
        widget->setFont(font);
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setFont(font);

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        verticalLayout->addWidget(label_3);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setFont(font);

        verticalLayout->addWidget(comboBox);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        verticalLayout->addWidget(label_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        price = new QLineEdit(widget);
        price->setObjectName(QString::fromUtf8("price"));
        price->setFont(font);

        horizontalLayout_2->addWidget(price);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(order);

        QMetaObject::connectSlotsByName(order);
    } // setupUi

    void retranslateUi(QWidget *order)
    {
        order->setWindowTitle(QCoreApplication::translate("order", "Form", nullptr));
        order_2->setText(QCoreApplication::translate("order", "\320\236\321\204\320\276\321\200\320\274\320\270\321\202\321\214", nullptr));
        label->setText(QCoreApplication::translate("order", "\320\232\320\273\320\270\320\265\320\275\321\202", nullptr));
        label_3->setText(QString());
        label_4->setText(QString());
        label_2->setText(QCoreApplication::translate("order", "\320\241\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class order: public Ui_order {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDER_H
