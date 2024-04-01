#include "setsale.h"
#include "ui_setsale.h"

setSale::setSale(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::setSale)
{
    ui->setupUi(this);
}

setSale::~setSale()
{
    delete ui;
}

void setSale::setComboBox(const QString &jsonString)
{
    QJsonParseError error;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonString.toUtf8(), &error);
    if (error.error != QJsonParseError::NoError)
    {
        qDebug() << "Ошибка при парсинге JSON:" << error.errorString();
        return;
    }
    if (jsonDoc.array().isEmpty() || jsonDoc.isEmpty())
    {
        return;
    }
    else
    {
        QJsonArray jsonArray = jsonDoc.array();

        for (const auto& jsonValue : jsonArray)
        {
            QJsonObject jsonObj = jsonValue.toObject();

            if (jsonObj.value("amount").toInt() > 0)
            {
                ui->combo->addItem(jsonObj.value("item_name").toString());
                price = jsonObj.value("price").toDouble();
            }
        }
    }
}

void setSale::on_accept_clicked()
{
    emit SendNewPrice();
    this->close();
}

void setSale::on_back_clicked()
{
    emit backTomm();
    this->close();
}
