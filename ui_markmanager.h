/********************************************************************************
** Form generated from reading UI file 'markmanager.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MARKMANAGER_H
#define UI_MARKMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_markmanager
{
public:
    QPushButton *back;
    QPushButton *setsale;
    QPushButton *notif;
    QLabel *userId;

    void setupUi(QWidget *markmanager)
    {
        if (markmanager->objectName().isEmpty())
            markmanager->setObjectName(QString::fromUtf8("markmanager"));
        markmanager->resize(576, 312);
        back = new QPushButton(markmanager);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(430, 260, 101, 31));
        QFont font;
        font.setPointSize(12);
        back->setFont(font);
        setsale = new QPushButton(markmanager);
        setsale->setObjectName(QString::fromUtf8("setsale"));
        setsale->setGeometry(QRect(50, 50, 231, 41));
        setsale->setFont(font);
        notif = new QPushButton(markmanager);
        notif->setObjectName(QString::fromUtf8("notif"));
        notif->setGeometry(QRect(280, 50, 231, 41));
        notif->setFont(font);
        userId = new QLabel(markmanager);
        userId->setObjectName(QString::fromUtf8("userId"));
        userId->setGeometry(QRect(260, 180, 151, 111));
        QFont font1;
        font1.setPointSize(14);
        userId->setFont(font1);

        retranslateUi(markmanager);

        QMetaObject::connectSlotsByName(markmanager);
    } // setupUi

    void retranslateUi(QWidget *markmanager)
    {
        markmanager->setWindowTitle(QCoreApplication::translate("markmanager", "Form", nullptr));
        back->setText(QCoreApplication::translate("markmanager", "\320\222\321\213\320\271\321\202\320\270", nullptr));
        setsale->setText(QCoreApplication::translate("markmanager", "\320\240\320\265\320\263\321\203\320\273\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \321\206\320\265\320\275", nullptr));
        notif->setText(QCoreApplication::translate("markmanager", "\320\240\320\260\321\201\321\201\321\213\320\273\320\272\320\260 \321\203\320\262\320\265\320\264\320\276\320\274\320\273\320\265\320\275\320\270\320\271", nullptr));
        userId->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class markmanager: public Ui_markmanager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MARKMANAGER_H
