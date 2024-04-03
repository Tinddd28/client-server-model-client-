#include "setsale.h"
#include "ui_setsale.h"

setSale::setSale(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::setSale)
{
    ui->setupUi(this);
    connect(ui->combo, SIGNAL(currentTextChanged(QString)), this, SLOT(setCurPrice()));
}

setSale::~setSale()
{
    delete ui;
}

void setSale::setCurPrice()
{
    QJsonArray jsonArray = items.array();
    for (int i = 0; i < jsonArray.size(); i++)
    {
        QJsonObject jsonObj = jsonArray[i].toObject();
        if (jsonObj["item_name"].toString() == ui->combo->currentText())
            ui->lineEdit->setText(QString::number(jsonObj["price"].toDouble()));
    }
}

void setSale::setComboBox(const QString &jsonString)
{
    QJsonParseError error;
    items = QJsonDocument::fromJson(jsonString.toUtf8(), &error);
    if (error.error != QJsonParseError::NoError)
    {
        qDebug() << "Ошибка при парсинге JSON:" << error.errorString();
        return;
    }
    if (items.array().isEmpty() || items.isEmpty())
    {
        return;
    }
    else
    {
        QJsonArray jsonArray = items.array();

        for (const auto& jsonValue : jsonArray)
        {
            QJsonObject jsonObj = jsonValue.toObject();

            if (jsonObj.value("amount").toInt() > 0)
            {
                ui->combo->addItem(jsonObj.value("item_name").toString());
            }
        }
    }
}

void setSale::on_accept_clicked()
{
    QJsonArray jsonArray = items.array();
    for (int i = 0; i < jsonArray.size(); i++)
    {
        QJsonObject jsonObj = jsonArray[i].toObject();
        if (jsonObj["item_name"].toString() == ui->combo->currentText())
        {
            jsonObj["price"] = jsonObj["price"].toDouble() - jsonObj["price"].toDouble() * ui->lineEdit_2->text().toInt() / 100.0;
            jsonArray[i] = jsonObj;
            break;
        }
    }
    items.setArray(jsonArray);
    emit SendNewPrice(items);
    this->close();
    QMessageBox::information(this, "Успешно!\t", "Скидка применена!");
}

void setSale::on_back_clicked()
{
    emit backTomm();
    this->close();
}
