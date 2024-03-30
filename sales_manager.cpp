#include "sales_manager.h"
#include "ui_sales_manager.h"

sales_manager::sales_manager(QString server_ip, int server_port, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sales_manager)
{
    ui->setupUi(this);
    this->server_ip = server_ip;
    this->server_port = server_port;
    it = new items();
    connect(it, &items::backtosm, this, &sales_manager::show);
}

sales_manager::~sales_manager()
{
    delete socket;
    delete ui;
}

void sales_manager::resetSocket()
{
    delete socket;
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &sales_manager::readinfo);
    socket->connectToHost(server_ip, server_port);
}

void sales_manager::readinfo()
{
    QByteArray responseData = socket->readAll();
    QList<QByteArray> responses = responseData.split('#');

    for (const QByteArray& response : responses)
    {
        if (response.isEmpty()) continue;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(response);
        QJsonObject jsonObj = jsonDoc.object();
        QString window = jsonObj.value("window").toString();
        if (window == "salesmanager")
        {
            QString action = jsonObj.value("action").toString();
            if (action == "data")
            {
                QString data = jsonObj.value("data").toString();
                if (data == "items")
                {
                    QString data_items = jsonObj.value("items").toString();
                    if (checkedjson(data_items))
                        qDebug() << "AGDDGAGADAG";
                    else
                        qDebug() << data_items;
                    it->outTable(data_items);
                    qDebug() << data_items;
                }
                else if (data == "clients")
                {
                    QString data_clients = jsonObj.value("clients").toString();
                    if (checkedjson(data_clients))
                        QMessageBox::warning(this, "Ошибка!\t", "База с клиентами пуста!");
                    else
                        qDebug() << data_clients;
                }
            }
        }
    }
}

bool sales_manager::checkedjson(QString json)
{
    QJsonParseError error;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(json.toUtf8(), &error);
    if (error.error != QJsonParseError::NoError) {
            qDebug() << "Ошибка при парсинге JSON:" << error.errorString();
            return false;
        }
    if (!(jsonDoc.isArray()) || jsonDoc.isEmpty()) {
        return 0;
    } else {
        return 1;
    }
}

void sales_manager::on_back_clicked()
{
    emit backToMain();
    this->close();
}

void sales_manager::on_see_items_clicked()
{
    QJsonObject jsonObj;
    jsonObj.insert("window", "salesmanager");
    jsonObj.insert("action", "data");
    jsonObj.insert("data", "items");

    QJsonDocument jsonDoc(jsonObj);
    socket->write(jsonDoc.toJson());

    it->show();
    this->hide();
}


void sales_manager::on_see_clients_clicked()
{
    QJsonObject jsonObj;
    jsonObj.insert("window", "salesmanager");
    jsonObj.insert("action", "data");
    jsonObj.insert("data", "clients");

    QJsonDocument jsonDoc(jsonObj);
    socket->write(jsonDoc.toJson());
}

void sales_manager::on_order_clicked()
{
    QJsonObject jsonObj;
    jsonObj.insert("window", "salesmanager");
    jsonObj.insert("action", "data");
    jsonObj.insert("data", "order");

    QJsonDocument jsonDoc(jsonObj);
    socket->write(jsonDoc.toJson());
}
