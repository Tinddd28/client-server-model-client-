#include "order.h"
#include "ui_order.h"

order::order(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::order)
{
    ui->setupUi(this);
}

order::~order()
{
    delete ui;
}

void order::on_order_2_clicked()
{

}


void order::on_back_clicked()
{
    emit backToSm();
    this->close();
}

void order::addInComboBox(QString jsonString)
{
    QJsonParseError error;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonString.toUtf8(), &error);

    QJsonArray jsonArray = jsonDoc.array();

    for (const auto& jsonValue : jsonArray)
    {
        QJsonObject jsonObj = jsonValue.toObject();

        if (jsonObj.value("amount").toInt() > 0)
            ui->comboBox->addItem(jsonObj.value("item_name").toString());
    }
}
