#ifndef SALES_MANAGER_H
#define SALES_MANAGER_H

#include <QWidget>
#include <QTcpSocket>
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QMessageBox>

#include <items.h>

namespace Ui {
class sales_manager;
}

class sales_manager : public QWidget
{
    Q_OBJECT

public:
    explicit sales_manager(QString server_ip, int server_port, QWidget *parent = nullptr);
    ~sales_manager();
    items *it;
    void resetSocket();



private:
    QTcpSocket *socket;
    QString server_ip;
    int server_port;
    int user_id;
    bool checkedjson(QString json);


public slots:
    void readinfo();

private slots:
    void on_back_clicked();

    void on_see_items_clicked();


    void on_see_clients_clicked();

    void on_order_clicked();

signals:
    void backToMain();

private:
    Ui::sales_manager *ui;
};

#endif // SALES_MANAGER_H
