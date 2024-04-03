#include "dataout.h"
#include "ui_dataout.h"

dataout::dataout(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dataout)
{
    ui->setupUi(this);
    id = new itemsd;
    cd = new clientsd;
    od = new orders;
    mes = new mess;
    connect(id, &itemsd::backb, this, &dataout::show);
    connect(cd, &clientsd::back, this, &dataout::show);
    connect(mes, &mess::back, this, &dataout::show);
    connect(od, &orders::back, this, &dataout::show);
}

dataout::~dataout()
{
    delete ui;
}

void dataout::on_items_clicked()
{
    id->setWindowTitle("Просмотр товаров");
    QJsonObject jsonObj;
    jsonObj.insert("window", "dataout");
    jsonObj.insert("action", "data");
    jsonObj.insert("data", "items");

    QJsonDocument jsonDoc(jsonObj);
    emit GetItems(jsonDoc);

    id->show();
    this->hide();

}

void dataout::on_clients_clicked()
{
    cd->setWindowTitle("Просмотр клиентов");
    QJsonObject jsonObj;
    jsonObj.insert("window", "dataout");
    jsonObj.insert("action", "data");
    jsonObj.insert("data", "clients");

    QJsonDocument jsonDoc(jsonObj);
    emit GetClients(jsonDoc);

    cd->show();
    this->hide();
}

void dataout::on_orders_clicked()
{
    od->setWindowTitle("Просмотр заказов");
    QJsonObject jsonObj;
    jsonObj.insert("window", "dataout");
    jsonObj.insert("action", "data");
    jsonObj.insert("data", "orders");

    QJsonDocument jsonDoc(jsonObj);
    emit GetOrders(jsonDoc);
    od->show();
    this->hide();
}

void dataout::on_messages_clicked()
{
    mes->setWindowTitle("Просмотр сообщений");
    QJsonObject jsonObj;
    jsonObj.insert("window", "dataout");
    jsonObj.insert("action", "data");
    jsonObj.insert("data", "messages");

    QJsonDocument jsonDoc(jsonObj);
    emit GetMessages(jsonDoc);

    mes->show();
    this->hide();
}

void dataout::on_sales_clicked()
{

}

void dataout::SetItems(QString items)
{
    Items = items;
}

void dataout::SetCLients(QString clients)
{
    Clients = clients;
}

void dataout::SetOrders(QString orders)
{
    Orders = orders;
}

void dataout::SetMessages(QString messages)
{
    Messages = messages;
}

bool dataout::checked_json(QString json)
{
    QJsonParseError error;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(json.toUtf8(), &error);
    if (error.error != QJsonParseError::NoError) {
            qDebug() << "Ошибка при парсинге JSON:" << error.errorString();
            return false;
        }
    if (jsonDoc.array().isEmpty() || jsonDoc.isEmpty()) {
        return 0;
    } else {
        return 1;
    }
}

void dataout::on_backb_clicked()
{
    emit backb();
    this->close();
}
