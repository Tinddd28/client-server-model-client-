/********************************************************************************
** Form generated from reading UI file 'adduser.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDUSER_H
#define UI_ADDUSER_H

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

class Ui_adduser
{
public:
    QPushButton *add;
    QPushButton *back;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *name;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *surname;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout;
    QLabel *label_11;
    QLineEdit *mail;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QComboBox *comboBox;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QLineEdit *login;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLineEdit *pass;

    void setupUi(QWidget *adduser)
    {
        if (adduser->objectName().isEmpty())
            adduser->setObjectName(QString::fromUtf8("adduser"));
        adduser->resize(480, 456);
        add = new QPushButton(adduser);
        add->setObjectName(QString::fromUtf8("add"));
        add->setGeometry(QRect(240, 400, 101, 28));
        QFont font;
        font.setPointSize(12);
        add->setFont(font);
        back = new QPushButton(adduser);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(130, 400, 93, 28));
        back->setFont(font);
        widget = new QWidget(adduser);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(90, 20, 298, 334));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        name = new QLineEdit(widget);
        name->setObjectName(QString::fromUtf8("name"));
        name->setFont(font);

        horizontalLayout_2->addWidget(name);


        verticalLayout->addLayout(horizontalLayout_2);

        label_10 = new QLabel(widget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout->addWidget(label_10);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_3->addWidget(label_2);

        surname = new QLineEdit(widget);
        surname->setObjectName(QString::fromUtf8("surname"));
        surname->setFont(font);

        horizontalLayout_3->addWidget(surname);


        verticalLayout->addLayout(horizontalLayout_3);

        label_9 = new QLabel(widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout->addWidget(label_9);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_11 = new QLabel(widget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);

        horizontalLayout->addWidget(label_11);

        mail = new QLineEdit(widget);
        mail->setObjectName(QString::fromUtf8("mail"));
        mail->setFont(font);

        horizontalLayout->addWidget(mail);


        verticalLayout->addLayout(horizontalLayout);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout->addWidget(label_7);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        horizontalLayout_4->addWidget(label_5);

        comboBox = new QComboBox(widget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setFont(font);

        horizontalLayout_4->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout_4);

        label_8 = new QLabel(widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout->addWidget(label_8);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout_5->addWidget(label_3);

        login = new QLineEdit(widget);
        login->setObjectName(QString::fromUtf8("login"));
        login->setFont(font);

        horizontalLayout_5->addWidget(login);


        verticalLayout->addLayout(horizontalLayout_5);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        horizontalLayout_6->addWidget(label_4);

        pass = new QLineEdit(widget);
        pass->setObjectName(QString::fromUtf8("pass"));
        pass->setFont(font);

        horizontalLayout_6->addWidget(pass);


        verticalLayout->addLayout(horizontalLayout_6);


        retranslateUi(adduser);

        QMetaObject::connectSlotsByName(adduser);
    } // setupUi

    void retranslateUi(QWidget *adduser)
    {
        adduser->setWindowTitle(QCoreApplication::translate("adduser", "Form", nullptr));
        add->setText(QCoreApplication::translate("adduser", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        back->setText(QCoreApplication::translate("adduser", "\320\235\320\260\320\267\320\260\320\264", nullptr));
        label->setText(QCoreApplication::translate("adduser", "\320\230\320\274\321\217", nullptr));
        label_10->setText(QString());
        label_2->setText(QCoreApplication::translate("adduser", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        label_9->setText(QString());
        label_11->setText(QCoreApplication::translate("adduser", "\320\237\320\276\321\207\321\202\320\260", nullptr));
        label_7->setText(QString());
        label_5->setText(QCoreApplication::translate("adduser", "\320\224\320\276\320\273\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        label_8->setText(QString());
        label_3->setText(QCoreApplication::translate("adduser", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        label_6->setText(QString());
        label_4->setText(QCoreApplication::translate("adduser", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adduser: public Ui_adduser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDUSER_H
