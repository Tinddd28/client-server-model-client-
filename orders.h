#ifndef ORDERS_H
#define ORDERS_H

#include <QWidget>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class orders;
}

class orders : public QWidget
{
    Q_OBJECT

public:
    explicit orders(QWidget *parent = nullptr);
    ~orders();

    void outTable();
    void setOrders(const QString& jsonString);

private:
    QString orderss;


private slots:
    void on_back_clicked();

signals:
    void back();

private:
    Ui::orders *ui;
};

#endif // ORDERS_H
