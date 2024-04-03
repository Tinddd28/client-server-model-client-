#include "deluser.h"
#include "ui_deluser.h"

deluser::deluser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::deluser)
{
    ui->setupUi(this);

}

deluser::~deluser()
{
    delete ui;
}

void deluser::SetUser(QString user)
{
    this->user = user;
}

void deluser::SetCombo()
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(user.toUtf8());
    QJsonArray jsonArray = jsonDoc.array();

    for (const auto& jsonValue : jsonArray)
    {
        QJsonObject jsonObj = jsonValue.toObject();
        ui->comboBox->addItem(jsonObj.value("login").toString());
    }
}

void deluser::on_back_clicked()
{
    ui->comboBox->clear();
    emit back();
    this->close();
}

void deluser::on_del_clicked()
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(user.toUtf8());
    QJsonArray jsonArray = jsonDoc.array();
    QString login;

    for (int i = 0; i < jsonArray.size(); i++)
    {
        QJsonObject jsonObj = jsonArray[i].toObject();
        login = ui->comboBox->currentText();
        if (login == jsonObj.value("login").toString())
        {
            jsonArray.removeAt(i);
            break;
        }
    }
    emit change(login);
    QMessageBox::information(this, "Успешно!\t", "Пользователь удален!");
    this->close();
    ui->comboBox->clear();
}
