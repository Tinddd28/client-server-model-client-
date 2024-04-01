#include "markmanager.h"
#include "ui_markmanager.h"

markmanager::markmanager(QString server_ip, int server_port, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::markmanager)
{
    ui->setupUi(this);
    this->server_ip = server_ip;
    this->server_port = server_port;
    mes = new message();
    sale = new setSale();
}

markmanager::~markmanager()
{
    delete mes;
    delete sale;
    delete ui;
}

void markmanager::resetSocket()
{
    delete socket;
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &markmanager::readinfo);
    socket->connectToHost(server_ip, server_port);
}

void markmanager::readinfo()
{
    QByteArray responseData = socket->readAll();
    QList<QByteArray> responses = responseData.split('#');

    for (const QByteArray& response : responses)
    {
        if (response.isEmpty()) continue;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(response);
        QJsonObject jsonObj = jsonDoc.object();
        QString window = jsonObj.value("window").toString();
        if (window == "markmanager")
        {
            QString action = jsonObj.value("action").toString();
            if (action == "message")
            {
                QJsonObject data = jsonObj.value("data").toObject();
                QString clients = data.value("clients").toString();
                QString items = data.value("items").toString();
            }
            else if (action == "set_sale")
            {
                QString items = jsonObj.value("items").toString();
                sale->setComboBox(items);
            }
        }

    }
}

void markmanager::on_back_clicked()
{
    emit backToMain();
    this->hide();
}



void markmanager::on_setsale_clicked()
{
    QJsonObject jsonObj;
    jsonObj.insert("window", "markmanager");
    jsonObj.insert("action", "set_sale");

    QJsonDocument jsonDoc(jsonObj);
    socket->write(jsonDoc.toJson());
    sale->show();
    this->hide();
}

void markmanager::on_notif_clicked()
{
    QJsonObject jsonObj;
    jsonObj.insert("window", "markmanager");
    jsonObj.insert("action", "message");

    QJsonDocument jsonDoc(jsonObj);
    socket->write(jsonDoc.toJson());
    mes->show();
    this->hide();
}
