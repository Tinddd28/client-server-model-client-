#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <QWidget>
#include <QObject>
#include <QDebug>
#include <QTcpSocket>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <dataout.h>
#include <QMessageBox>
#include <users.h>
#include <QCryptographicHash>
#include <QVariantList>
#include <usview.h>

namespace Ui {
class director;
}

class director : public QWidget
{
    Q_OBJECT

public:
    explicit director(QString server_ip, int server_port, QWidget *parent = nullptr);
    ~director();
   void resetSocket();

private:
    QTcpSocket* socket;
    QString server_ip;
    int server_port;
    void readinfo();
    dataout *dataO;
    users *us;
    usview *uview;
    bool checked_json(QString);

    QByteArray serialize(QVector<QString>);

    void SendRequestOfItems(QJsonDocument);
    void SendRequestOfClients(QJsonDocument);
    void SendRequestOfOrders(QJsonDocument);
    void SendRequestOfMessages(QJsonDocument);
    void SendReqForCl(QString action);
    void SendChangeInClients(QJsonDocument);
    void SendDelUser(QString);

    void SendNewUser(QString, QString, QString, QString, QString, QString);

private slots:

    void on_data_clicked();

    void on_report_clicked();

    void on_archive_clicked();

    void on_users_clicked();

    void on_back_clicked();

    void on_us_clicked();

signals:
    void backToMain();

private:
    Ui::director *ui;
};

#endif // DIRECTOR_H
