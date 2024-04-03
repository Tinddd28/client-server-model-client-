/********************************************************************************
** Form generated from reading UI file 'message.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGE_H
#define UI_MESSAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_message
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *send;
    QPushButton *back;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *user;
    QComboBox *combo;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *type;

    void setupUi(QWidget *message)
    {
        if (message->objectName().isEmpty())
            message->setObjectName(QString::fromUtf8("message"));
        message->resize(517, 383);
        lineEdit = new QLineEdit(message);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(20, 220, 461, 61));
        QFont font;
        font.setPointSize(12);
        lineEdit->setFont(font);
        label = new QLabel(message);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 110, 331, 161));
        label->setFont(font);
        send = new QPushButton(message);
        send->setObjectName(QString::fromUtf8("send"));
        send->setGeometry(QRect(240, 310, 121, 41));
        send->setFont(font);
        back = new QPushButton(message);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(120, 310, 121, 41));
        back->setFont(font);
        widget = new QWidget(message);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 90, 411, 51));
        widget->setFont(font);
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        user = new QLabel(widget);
        user->setObjectName(QString::fromUtf8("user"));
        user->setFont(font);

        horizontalLayout->addWidget(user);

        combo = new QComboBox(widget);
        combo->setObjectName(QString::fromUtf8("combo"));
        combo->setFont(font);

        horizontalLayout->addWidget(combo);

        widget1 = new QWidget(message);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(50, 20, 411, 51));
        horizontalLayout_2 = new QHBoxLayout(widget1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(widget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        type = new QComboBox(widget1);
        type->setObjectName(QString::fromUtf8("type"));
        type->setFont(font);

        horizontalLayout_2->addWidget(type);


        retranslateUi(message);

        QMetaObject::connectSlotsByName(message);
    } // setupUi

    void retranslateUi(QWidget *message)
    {
        message->setWindowTitle(QCoreApplication::translate("message", "Form", nullptr));
        label->setText(QCoreApplication::translate("message", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265 \320\264\320\273\321\217 \321\200\320\260\321\201\321\201\321\213\320\273\320\272\320\270!", nullptr));
        send->setText(QCoreApplication::translate("message", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
        back->setText(QCoreApplication::translate("message", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        user->setText(QCoreApplication::translate("message", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        label_2->setText(QCoreApplication::translate("message", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\202\320\270\320\277", nullptr));
    } // retranslateUi

};

namespace Ui {
    class message: public Ui_message {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGE_H
