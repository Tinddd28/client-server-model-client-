#include "director.h"
#include "ui_director.h"

director::director(QString server_ip, int server_port, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::director)
{
    this->server_ip = server_ip;
    this->server_port = server_port;
    ui->setupUi(this);
    dataO = new dataout();
    us = new users();
    uview = new usview();
    connect(dataO, &dataout::backb, this, &director::show);
    connect(dataO, &dataout::GetItems, this, &director::SendRequestOfItems);
    connect(dataO, &dataout::GetClients, this, &director::SendRequestOfClients);
    connect(dataO, &dataout::GetOrders, this, &director::SendRequestOfOrders);
    connect(dataO, &dataout::GetMessages, this, &director::SendRequestOfMessages);
    connect(us, &users::back, this, &director::show);
    connect(us, &users::send_data, this, &director::SendNewUser);
    connect(us, &users::sendReqForEdit, this, &director::SendReqForCl);
    connect (us, &users::edit, this, &director::SendChangeInClients);
    connect (us, &users::back, this, &director::show);
    connect(us, &users::senddel, this, &director::SendDelUser);
    connect(uview, &usview::back, this, &director::show);
}

director::~director()
{
    delete ui;
}

void director::SendChangeInClients(QJsonDocument jsonDocument)
{
    QJsonObject jsonObj;
    jsonObj.insert("window", "director");
    jsonObj.insert("action", "edit");
    QString usString = jsonDocument.toJson(QJsonDocument::Compact);
    jsonObj.insert("users", usString);

    QJsonDocument jsonDoc(jsonObj);
    socket->write(jsonDoc.toJson());
}

void director::SendNewUser(QString mail, QString name, QString sname, QString dolzh, QString login, QString pass)
{
    QJsonObject jsonObj;
    jsonObj.insert("window", "director");
    jsonObj.insert("action", "add");
    QByteArray passwordData = pass.toUtf8();
    QByteArray passwordHash = QCryptographicHash::hash(passwordData, QCryptographicHash::Sha256).toHex();
    pass = passwordHash;
    QVector<QString> vector;
    vector.append(mail);
    vector.append(name);
    vector.append(sname);
    vector.append(dolzh);
    vector.append(login);
    vector.append(pass);
    QByteArray byteArray = serialize(vector);
    QString dataString = QString::fromLatin1(byteArray.toBase64());
    jsonObj.insert("add", dataString);

    QJsonDocument jsonDoc(jsonObj);
    socket->write(jsonDoc.toJson());
}

void director::SendReqForCl(QString action)
{
    QJsonObject jsonObj;
    jsonObj.insert("window", "director");
    jsonObj.insert("action", action);

    QJsonDocument jsonDoc(jsonObj);
    socket->write(jsonDoc.toJson());
}

QByteArray director::serialize(QVector<QString> vector)
{
    QVariantList list;
    for (const QString& str : vector) {
        list.append(str);
    }

    // Сериализация QVariantList с помощью QDataStream
    QByteArray byteArray;
    QDataStream stream(&byteArray, QIODevice::WriteOnly);
    stream << list;
    return byteArray;
}

void director::resetSocket()
{
    delete socket;
    socket = new QTcpSocket(this);
    socket->connectToHost(server_ip, server_port);
    connect(socket, &QTcpSocket::readyRead, this, &director::readinfo);
}

void director::SendRequestOfItems(QJsonDocument items)
{
    socket->write(items.toJson());
}

void director::SendRequestOfClients(QJsonDocument clients)
{
    socket->write(clients.toJson());
}

void director::SendRequestOfOrders(QJsonDocument orders)
{
    socket->write(orders.toJson());
}

void director::SendRequestOfMessages(QJsonDocument messages)
{
    socket->write(messages.toJson());
}
void director::readinfo()
{
    QByteArray responseData = socket->readAll();
    QList<QByteArray> responses = responseData.split('#');

    for (const QByteArray& response : responses)
    {
        if (response.isEmpty()) continue;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(response);
        QJsonObject jsonObj = jsonDoc.object();
        QString window = jsonObj.value("window").toString();
        if (window == "dataout")
        {
            QString action = jsonObj.value("action").toString();
            if (action == "data")
            {
                QString data = jsonObj.value("data").toString();
                if (data == "items")
                {
                    QString items = jsonObj.value("items").toString();
                    dataO->id->outTable(items);
                }
                else if (data == "clients")
                {
                    QString clients = jsonObj.value("clients").toString();
                    dataO->cd->OutTable(clients);

                }
                else if (data == "orders")
                {
                    QString orders = jsonObj.value("orders").toString();
                    dataO->od->setOrders(orders);
                    dataO->od->outTable();
                }
                else if (data == "messages")
                {
                    QString messages = jsonObj.value("messages").toString();
                    dataO->mes->SetMessages(messages);
                    dataO->mes->OutTable();
                }
            }
        }
        else if (window == "director")
        {
            QString action = jsonObj.value("action").toString();
            if (action == "edituser")
            {
                QString users = jsonObj.value("users").toString();
                us->SetUser(users);
                us->eu->setUser(users);
                us->eu->setCombo();
            }
            else if (action == "adduser")
            {
                QString users = jsonObj.value("users").toString();
                us->au->setUser(users);
                us->SetUser(users);
            }
            else if (action == "deluser")
            {
                QString users = jsonObj.value("users").toString();
                us->SetUser(users);
                us->du->SetUser(users);
                us->du->SetCombo();
            }
            else if (action == "view")
            {
                QString users = jsonObj.value("users").toString();
                uview->OutTable(users);
                uview->show();
                this->hide();
            }
        }
    }
}

void director::SendDelUser(QString login)
{
    QJsonObject jsonObj;
    jsonObj.insert("window", "director");
    jsonObj.insert("action", "del");
    jsonObj.insert("user", login);

    QJsonDocument jsonDoc(jsonObj);
    socket->write(jsonDoc.toJson());
}

bool director::checked_json(QString json)
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

void director::on_data_clicked()
{
    dataO->setWindowTitle("Просмотр");
    dataO->show();
    this->close();
}

void director::on_report_clicked()
{

}

void director::on_archive_clicked()
{

}

void director::on_users_clicked()
{
    us->setWindowTitle("Работа с пользователями");
    us->show();
    this->hide();
}

void director::on_back_clicked()
{
    emit backToMain();
    this->close();
}

void director::on_us_clicked()
{
    uview->setWindowTitle("Просмотр пользователей");
    QJsonObject jsonObj;
    jsonObj.insert("window", "director");
    jsonObj.insert("action", "view");

    QJsonDocument jsonDoc(jsonObj);
    socket->write(jsonDoc.toJson());
}
