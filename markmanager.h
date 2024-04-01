#ifndef MARKMANAGER_H
#define MARKMANAGER_H

#include <QWidget>
#include <QTcpSocket>
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QMessageBox>

#include <setsale.h>
#include <message.h>


namespace Ui {
class markmanager;
}

class markmanager : public QWidget
{
    Q_OBJECT

public:
    explicit markmanager(QString server_ip, int server_port, QWidget *parent = nullptr);
    ~markmanager();

    void resetSocket();

private slots:
    void on_back_clicked();


    void on_setsale_clicked();

    void on_notif_clicked();

private:
    QTcpSocket* socket;
    QString server_ip;
    int server_port;
    setSale* sale;
    message* mes;
    void readinfo();

signals:
    void backToMain();

private:
    Ui::markmanager *ui;
};

#endif // MARKMANAGER_H
