/********************************************************************************
** Form generated from reading UI file 'setsale.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETSALE_H
#define UI_SETSALE_H

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

class Ui_setSale
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *combo;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *back;
    QPushButton *accept;

    void setupUi(QWidget *setSale)
    {
        if (setSale->objectName().isEmpty())
            setSale->setObjectName(QString::fromUtf8("setSale"));
        setSale->resize(518, 330);
        widget = new QWidget(setSale);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(100, 50, 310, 154));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        combo = new QComboBox(widget);
        combo->setObjectName(QString::fromUtf8("combo"));
        combo->setFont(font);

        horizontalLayout->addWidget(combo);


        verticalLayout->addLayout(horizontalLayout);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setFont(font);

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout->addWidget(label_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setFont(font);

        horizontalLayout_3->addWidget(lineEdit_2);


        verticalLayout->addLayout(horizontalLayout_3);

        widget1 = new QWidget(setSale);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(150, 240, 211, 35));
        horizontalLayout_4 = new QHBoxLayout(widget1);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        back = new QPushButton(widget1);
        back->setObjectName(QString::fromUtf8("back"));
        back->setFont(font);

        horizontalLayout_4->addWidget(back);

        accept = new QPushButton(widget1);
        accept->setObjectName(QString::fromUtf8("accept"));
        accept->setFont(font);

        horizontalLayout_4->addWidget(accept);


        retranslateUi(setSale);

        QMetaObject::connectSlotsByName(setSale);
    } // setupUi

    void retranslateUi(QWidget *setSale)
    {
        setSale->setWindowTitle(QCoreApplication::translate("setSale", "Form", nullptr));
        label->setText(QCoreApplication::translate("setSale", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\202\320\276\320\262\320\260\321\200", nullptr));
        label_4->setText(QString());
        label_2->setText(QCoreApplication::translate("setSale", "\320\241\321\202\320\276\320\270\320\274\320\276\321\201\321\202\321\214", nullptr));
        label_5->setText(QString());
        label_3->setText(QCoreApplication::translate("setSale", "\320\241\320\272\320\270\320\264\320\272\320\260", nullptr));
        back->setText(QCoreApplication::translate("setSale", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        accept->setText(QCoreApplication::translate("setSale", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class setSale: public Ui_setSale {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETSALE_H
