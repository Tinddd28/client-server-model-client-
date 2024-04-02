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
    connect(sale, &setSale::backTomm, this, &markmanager::show);
    connect(sale, &setSale::SendNewPrice, this, &markmanager::show);
    connect(sale, &setSale::SendNewPrice, this, &markmanager::SendDataToServer);
    connect(mes, &message::backToMm, this, &markmanager::show);
    connect(mes, &message::SendMes, this, &markmanager::sendMessage);
    connect(mes, &message::SendMes, this, &markmanager::show);
}

markmanager::~markmanager()
{
    delete mes;
    delete sale;
    delete ui;
}

void markmanager::sendMessage(QByteArray data)
{
    QJsonObject jsonObj;
    jsonObj.insert("window", "markmanager");
    jsonObj.insert("action", "send");
    QString dataString = QString::fromLatin1(data.toBase64());
    jsonObj.insert("data", dataString);

    QJsonDocument jsonDoc(jsonObj);
    socket->write(jsonDoc.toJson());
}

void markmanager::SendDataToServer(QJsonDocument jsonDoc)
{
    QJsonObject jsonObj;
    jsonObj.insert("window", "markmanager");
    jsonObj.insert("action", "send_sale");
    QString itemsString = jsonDoc.toJson(QJsonDocument::Compact);
    jsonObj.insert("items", itemsString);

    QJsonDocument jsonD(jsonObj);
    socket->write(jsonD.toJson());

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
                QString clients = jsonObj.value("clients").toString();
                mes->show();
                this->hide();
                mes->setClients(clients);
            }
            else if (action == "set_sale")
            {
                QString items = jsonObj.value("items").toString();
                sale->show();
                this->hide();
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
}

void markmanager::on_notif_clicked()
{
    QJsonObject jsonObj;
    jsonObj.insert("window", "markmanager");
    jsonObj.insert("action", "message");

    QJsonDocument jsonDoc(jsonObj);
    socket->write(jsonDoc.toJson());
}
