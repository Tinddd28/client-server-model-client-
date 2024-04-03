#include "adduser.h"
#include "ui_adduser.h"

adduser::adduser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adduser)
{
    ui->setupUi(this);
    ui->comboBox->addItem("Менеджер по продажам");
    ui->comboBox->addItem("Менеджер по маркетингу");
}

adduser::~adduser()
{
    delete ui;
}

void adduser::on_back_clicked()
{
    ui->mail->clear();
    ui->pass->clear();
    emit back();
    this->close();
}

void adduser::setUser(QString user)
{
    this->user = user;
}

void adduser::on_add_clicked()
{
    if (ui->mail->text() == "" || ui->name->text() == "" || ui->surname->text() == "" || ui->login->text() == "" || ui->pass->text() == "")
    {
        QMessageBox::warning(this, "Ошибка!\t", "Заполните все поля!");
        return;
    }
    QJsonDocument jsonDoc = QJsonDocument::fromJson(user.toUtf8());

    QJsonArray jsonArray = jsonDoc.array();
    for (const auto jsonValue : jsonArray)
    {
        QJsonObject jsonObj = jsonValue.toObject();
        if (jsonObj.value("login").toString() == ui->login->text())
        {
            QMessageBox::warning(this, "Ошибка!\t", "Пользователь с таким логином уже существует!");
            return;
        }
    }

    QString mail = ui->mail->text();
    QString name = ui->name->text();
    QString sname = ui->surname->text();
    QString dolzh = ui->comboBox->currentText();
    QString login = ui->login->text();
    QString pass = ui->pass->text();

    emit add(mail, name, sname, dolzh, login, pass);
    ui->name->clear();
    ui->surname->clear();
    ui->mail->clear();
    ui->login->clear();
    ui->pass->clear();
    QMessageBox::information(this, "Успешно!\t", "Данные изменены!");
    this->close();

}
