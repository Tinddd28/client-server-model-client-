/********************************************************************************
** Form generated from reading UI file 'deluser.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELUSER_H
#define UI_DELUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_deluser
{
public:
    QComboBox *comboBox;
    QLabel *label;
    QPushButton *del;
    QPushButton *back;
    QLabel *label_2;

    void setupUi(QWidget *deluser)
    {
        if (deluser->objectName().isEmpty())
            deluser->setObjectName(QString::fromUtf8("deluser"));
        deluser->resize(501, 221);
        comboBox = new QComboBox(deluser);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(259, 31, 211, 30));
        QFont font;
        font.setPointSize(12);
        comboBox->setFont(font);
        label = new QLabel(deluser);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(31, 31, 222, 24));
        label->setFont(font);
        del = new QPushButton(deluser);
        del->setObjectName(QString::fromUtf8("del"));
        del->setGeometry(QRect(260, 140, 93, 28));
        del->setFont(font);
        back = new QPushButton(deluser);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(140, 140, 93, 28));
        back->setFont(font);
        label_2 = new QLabel(deluser);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 80, 421, 41));
        label_2->setFont(font);

        retranslateUi(deluser);

        QMetaObject::connectSlotsByName(deluser);
    } // setupUi

    void retranslateUi(QWidget *deluser)
    {
        deluser->setWindowTitle(QCoreApplication::translate("deluser", "Form", nullptr));
        label->setText(QCoreApplication::translate("deluser", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        del->setText(QCoreApplication::translate("deluser", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        back->setText(QCoreApplication::translate("deluser", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class deluser: public Ui_deluser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELUSER_H
