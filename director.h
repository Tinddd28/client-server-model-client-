#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <QWidget>
#include <QDebug>
#include <QTcpSocket>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>

namespace Ui {
class director;
}

class director : public QWidget
{
    Q_OBJECT

public:
    explicit director(QString server_ip, int server_port, QWidget *parent = nullptr);
    ~director();
private:
    QTcpSocket* socket();
    QString server_ip;
    int server_port;

private:
    Ui::director *ui;
};

#endif // DIRECTOR_H
