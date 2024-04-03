#include "edituser.h"
#include "ui_edituser.h"

edituser::edituser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::edituser)
{
    ui->setupUi(this);
}

edituser::~edituser()
{
    delete ui;
}

void edituser::setUser(QString user)
{
    this->user = user;
}

void edituser::setCombo()
{
    QJsonDocument jsondoc = QJsonDocument::fromJson(user.toUtf8());

    QJsonArray jsonArray = jsondoc.array();

    for (int i = 0; i < jsonArray.size(); i++)
    {
        QJsonObject jsonObj = jsonArray[i].toObject();
        ui->comboBox->addItem(jsonObj.value("login").toString());
    }
}
void edituser::on_back_clicked()
{
    ui->mail->clear();
    ui->pass->clear();
    ui->comboBox->clear();
    emit back();
    this->close();
}

void edituser::on_edit_clicked()
{
    QJsonDocument jsondoc = QJsonDocument::fromJson(user.toUtf8());

    QJsonArray jsonArray = jsondoc.array();
    if (ui->pass->text() != "" || ui->mail->text() != 0)
    {
        for (int i = 0; i < jsonArray.size(); i++)
        {
            QJsonObject jsonObj = jsonArray[i].toObject();
            if (jsonObj.value("login").toString() == ui->comboBox->currentText())
            {
                if (ui->pass->text() != "")
                {
                    QByteArray passwordData = ui->pass->text().toUtf8();
                    QByteArray passwordHash = QCryptographicHash::hash(passwordData, QCryptographicHash::Sha256).toHex();
                    QString pass = passwordHash;
                    jsonObj["password_hash"] = pass;
                    qDebug() << pass;
                }
                else if (ui->mail->text() != "")
                {
                    jsonObj["mail"] = ui->mail->text();
                }
                jsonArray[i] = jsonObj;
                break;
            }
        }
    }
    else
    {
       QMessageBox::warning(this, "Ошибка", "Нет соединения с сервером");
       return;
    }
    jsondoc.setArray(jsonArray);
    ui->comboBox->clear();
    ui->pass->clear();
    ui->mail->clear();
    emit send(jsondoc);
    this->close();
}
