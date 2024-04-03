#ifndef DATAOUT_H
#define DATAOUT_H

#include <QWidget>
#include <QObject>
#include <QDebug>
#include <QTcpSocket>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QMessageBox>
#include <itemsd.h>
#include <clientsd.h>
#include <orders.h>
#include <mess.h>


namespace Ui {
class dataout;
}

class dataout : public QWidget
{
    Q_OBJECT

public:
    explicit dataout(QWidget *parent = nullptr);
    ~dataout();
    void SetItems(QString);
    void SetCLients(QString);
    void SetOrders(QString);
    void SetMessages(QString);

    itemsd *id;
    clientsd *cd;
    orders *od;
    mess *mes;
private:

    QString Items;
    QString Clients;
    QString Orders;
    QString Messages;

    bool checked_json(QString json);

signals:
    void backb();
    void GetItems(QJsonDocument);
    void GetClients(QJsonDocument);
    void GetOrders(QJsonDocument);
    void GetMessages(QJsonDocument);


private slots:
    void on_items_clicked();

    void on_clients_clicked();

    void on_orders_clicked();

    void on_messages_clicked();

    void on_sales_clicked();

    void on_backb_clicked();

private:
    Ui::dataout *ui;
};

#endif // DATAOUT_H
