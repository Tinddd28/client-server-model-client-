/********************************************************************************
** Form generated from reading UI file 'edituser.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITUSER_H
#define UI_EDITUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_edituser
{
public:
    QComboBox *comboBox;
    QLabel *label;
    QPushButton *back;
    QPushButton *edit;
    QLabel *label_2;
    QLineEdit *mail;
    QLabel *label_3;
    QLineEdit *pass;

    void setupUi(QWidget *edituser)
    {
        if (edituser->objectName().isEmpty())
            edituser->setObjectName(QString::fromUtf8("edituser"));
        edituser->resize(557, 412);
        comboBox = new QComboBox(edituser);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(269, 51, 261, 30));
        QFont font;
        font.setPointSize(12);
        comboBox->setFont(font);
        label = new QLabel(edituser);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 50, 222, 24));
        label->setFont(font);
        back = new QPushButton(edituser);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(160, 350, 93, 28));
        back->setFont(font);
        edit = new QPushButton(edituser);
        edit->setObjectName(QString::fromUtf8("edit"));
        edit->setGeometry(QRect(280, 350, 93, 28));
        edit->setFont(font);
        label_2 = new QLabel(edituser);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(41, 131, 196, 24));
        label_2->setFont(font);
        mail = new QLineEdit(edituser);
        mail->setObjectName(QString::fromUtf8("mail"));
        mail->setGeometry(QRect(243, 131, 281, 30));
        mail->setFont(font);
        label_3 = new QLabel(edituser);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 220, 209, 24));
        label_3->setFont(font);
        pass = new QLineEdit(edituser);
        pass->setObjectName(QString::fromUtf8("pass"));
        pass->setGeometry(QRect(266, 221, 251, 30));
        pass->setFont(font);

        retranslateUi(edituser);

        QMetaObject::connectSlotsByName(edituser);
    } // setupUi

    void retranslateUi(QWidget *edituser)
    {
        edituser->setWindowTitle(QCoreApplication::translate("edituser", "Form", nullptr));
        label->setText(QCoreApplication::translate("edituser", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        back->setText(QCoreApplication::translate("edituser", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        edit->setText(QCoreApplication::translate("edituser", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("edituser", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\276\320\262\321\203\321\216 \320\277\320\276\321\207\321\202\321\203", nullptr));
        label_3->setText(QCoreApplication::translate("edituser", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\275\320\276\320\262\321\213\320\271 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class edituser: public Ui_edituser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITUSER_H
