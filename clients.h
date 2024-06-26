#ifndef CLIENTS_H
#define CLIENTS_H

#include <QWidget>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QDebug>

namespace Ui {
class clients;
}

class clients : public QWidget
{
    Q_OBJECT

public:
    explicit clients(QWidget *parent = nullptr);
    ~clients();
    void OutTable(QString jsonString);

private slots:
    void on_back_clicked();

signals:
    void backToSm();
private:
    Ui::clients *ui;
};

#endif // CLIENTS_H
