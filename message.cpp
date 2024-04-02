#include "message.h"
#include "ui_message.h"

message::message(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::message)
{
    ui->setupUi(this);
    ui->combo->hide();
    ui->user->hide();
    ui->type->addItem("Выберите кому сообщение");
    ui->type->addItem("Всем пользователям");
    ui->type->addItem("Конкретному пользователю");
    connect(ui->type, SIGNAL(currentTextChanged(QString)), this, SLOT(ShowComboBox()));
    //connect(ui->type, SIGNAL(currentTextChanged(QString)), this, SLOT(setCombo()));
}

message::~message()
{
    delete ui;
}

void message::ShowComboBox()
{
    if (ui->type->currentText() == "Конкретному пользователю")
    {
        ui->combo->show();
        ui->user->show();
        QJsonArray jsonArray = jsonDoc.array();
        for (int i = 0; i < jsonArray.size(); i++)
        {
            QJsonObject jsonObj = jsonArray[i].toObject();
            ui->combo->addItem(jsonObj.value("mail").toString());
        }
    }
    else if (ui->type->currentText() == "Выберите кому сообщение")
    {
        ui->combo->hide();
        ui->user->hide();
    }
    else if (ui->type->currentText() == "Всем пользователям")
    {
        ui->combo->hide();
        ui->user->hide();
    }
}

void message::setClients(const QString & jsonString)
{
    QJsonParseError error;
    QJsonDocument jsonD = QJsonDocument::fromJson(jsonString.toUtf8(), &error);
    if (error.error != QJsonParseError::NoError)
    {
        qDebug() << "Ошибка при парсинге JSON:" << error.errorString();
        return;
    }
    if (jsonD.array().isEmpty() || jsonD.isEmpty())
    {
        return;
    }
    else
        jsonDoc = jsonD;
}

void message::on_send_clicked()
{
    ForMes mes;
    QVector<ForMes> vector;
    if (ui->lineEdit->text() == "")
    {
        QMessageBox::warning(this, "Ошибка!\t", "Заполните текст сообещния!");
        return;
    }
    if (ui->type->currentText() == "Всем пользователям")
    {
        QJsonArray jsonArray = jsonDoc.array();
        for (const auto& jsonValue : jsonArray)
        {
            QJsonObject jsonObj = jsonValue.toObject();
            mes.mail = jsonObj["mail"].toString();
            mes.name = jsonObj["name"].toString();
            mes.surname = jsonObj["surname"].toString();
            mes.message = ui->lineEdit->text();
            vector.append(mes);
        }
    }
    else if (ui->type->currentText() == "Конкретному пользователю")
    {
        QJsonArray jsonArray = jsonDoc.array();
        for (const auto& jsonValue : jsonArray)
        {
            QJsonObject jsonObj = jsonValue.toObject();
            if (ui->combo->currentText() == jsonObj["mail"].toString())
            {
                mes.mail = jsonObj["mail"].toString();
                mes.name = jsonObj["name"].toString();
                mes.surname = jsonObj["surname"].toString();
                mes.message = ui->lineEdit->text();
                vector.append(mes);
                break;
            }
        }
    }
    else if (ui->type->currentText() == "Выберите кому сообщение")
    {
        QMessageBox::warning(this, "Ошибка!\t", "Выберите кому сообщение!");
        return;
    }
    QByteArray data = serializeVector(vector);
    emit SendMes(data);
    QMessageBox::information(this, "Успешно!\t", "Сообщение отправлено!");
    this->close();
    ui->combo->clear();
    ui->type->clear();
    ui->type->addItem("Выберите кому сообщение");
    ui->type->addItem("Всем пользователям");
    ui->type->addItem("Конкретному пользователю");
    ui->lineEdit->clear();
}

void message::on_back_clicked()
{
    emit backToMm();
    this->close();
    ui->combo->clear();
    ui->type->clear();
    ui->type->addItem("Выберите кому сообщение");
    ui->type->addItem("Всем пользователям");
    ui->type->addItem("Конкретному пользователю");
}
