#ifndef ORDER_H
#define ORDER_H

#include <QWidget>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QDebug>
#include <QMessageBox>
#include <QIntValidator>
#include <QDoubleValidator>

namespace Ui {
class order;
}

class order : public QWidget
{
    Q_OBJECT

public:
    explicit order(QWidget *parent = nullptr);
    ~order();

    void addInComboBox(QString json);
    void setClients(QString json);
    void setItems(QString json);

private:
    QJsonDocument clients;
    QJsonDocument items;
    void changeContactInfo(QString mail, QString phone);


private slots:
    void on_order_2_clicked();
    void on_back_clicked();
    void SeeAmount();
    void setPrice();


signals:
    void backToSm();
    void broadcastdata(QJsonDocument, QJsonDocument, double, QString, QString, QString);

private:
    Ui::order *ui;
};

#endif // ORDER_H
