/********************************************************************************
** Form generated from reading UI file 'sales_manager.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SALES_MANAGER_H
#define UI_SALES_MANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sales_manager
{
public:
    QLabel *label_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *see_items;
    QPushButton *order;
    QPushButton *see_clients;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *help;
    QLabel *label_2;
    QLabel *label;
    QPushButton *back;

    void setupUi(QWidget *sales_manager)
    {
        if (sales_manager->objectName().isEmpty())
            sales_manager->setObjectName(QString::fromUtf8("sales_manager"));
        sales_manager->resize(660, 357);
        label_3 = new QLabel(sales_manager);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(470, 210, 151, 111));
        QFont font;
        font.setPointSize(14);
        label_3->setFont(font);
        layoutWidget = new QWidget(sales_manager);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 80, 574, 35));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        see_items = new QPushButton(layoutWidget);
        see_items->setObjectName(QString::fromUtf8("see_items"));
        QFont font1;
        font1.setPointSize(12);
        see_items->setFont(font1);

        horizontalLayout->addWidget(see_items);

        order = new QPushButton(layoutWidget);
        order->setObjectName(QString::fromUtf8("order"));
        order->setFont(font1);

        horizontalLayout->addWidget(order);

        see_clients = new QPushButton(layoutWidget);
        see_clients->setObjectName(QString::fromUtf8("see_clients"));
        see_clients->setFont(font1);

        horizontalLayout->addWidget(see_clients);

        layoutWidget1 = new QWidget(sales_manager);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(160, 250, 273, 35));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        help = new QPushButton(layoutWidget1);
        help->setObjectName(QString::fromUtf8("help"));
        help->setFont(font1);

        horizontalLayout_2->addWidget(help);

        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        back = new QPushButton(layoutWidget1);
        back->setObjectName(QString::fromUtf8("back"));
        back->setFont(font1);

        horizontalLayout_2->addWidget(back);


        retranslateUi(sales_manager);

        QMetaObject::connectSlotsByName(sales_manager);
    } // setupUi

    void retranslateUi(QWidget *sales_manager)
    {
        sales_manager->setWindowTitle(QCoreApplication::translate("sales_manager", "Form", nullptr));
        label_3->setText(QCoreApplication::translate("sales_manager", "USER ID: 1", nullptr));
        see_items->setText(QCoreApplication::translate("sales_manager", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \321\202\320\276\320\262\320\260\321\200\320\276\320\262", nullptr));
        order->setText(QCoreApplication::translate("sales_manager", "\320\236\321\204\320\276\321\200\320\274\320\273\320\265\320\275\320\270\320\265 \320\267\320\260\320\272\320\260\320\267\320\260", nullptr));
        see_clients->setText(QCoreApplication::translate("sales_manager", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \320\272\320\273\320\270\320\265\320\275\321\202\320\276\320\262", nullptr));
        help->setText(QCoreApplication::translate("sales_manager", "\320\237\320\276\320\274\320\276\321\211\321\214", nullptr));
        label_2->setText(QString());
        label->setText(QString());
        back->setText(QCoreApplication::translate("sales_manager", "\320\222\321\213\320\271\321\202\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sales_manager: public Ui_sales_manager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SALES_MANAGER_H
