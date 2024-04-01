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

    void setupUi(QWidget *message)
    {
        if (message->objectName().isEmpty())
            message->setObjectName(QString::fromUtf8("message"));
        message->resize(517, 364);
        lineEdit = new QLineEdit(message);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(30, 70, 461, 221));
        QFont font;
        font.setPointSize(12);
        lineEdit->setFont(font);
        label = new QLabel(message);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, -40, 331, 161));
        label->setFont(font);
        send = new QPushButton(message);
        send->setObjectName(QString::fromUtf8("send"));
        send->setGeometry(QRect(250, 300, 121, 41));
        send->setFont(font);
        back = new QPushButton(message);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(130, 300, 121, 41));
        back->setFont(font);

        retranslateUi(message);

        QMetaObject::connectSlotsByName(message);
    } // setupUi

    void retranslateUi(QWidget *message)
    {
        message->setWindowTitle(QCoreApplication::translate("message", "Form", nullptr));
        label->setText(QCoreApplication::translate("message", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\201\320\276\320\276\320\261\321\211\320\265\320\275\320\270\320\265 \320\264\320\273\321\217 \321\200\320\260\321\201\321\201\321\213\320\273\320\272\320\270!", nullptr));
        send->setText(QCoreApplication::translate("message", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
        back->setText(QCoreApplication::translate("message", "\320\235\320\260\320\267\320\260\320\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class message: public Ui_message {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGE_H
