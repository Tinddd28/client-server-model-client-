#ifndef SALES_MANAGER_H
#define SALES_MANAGER_H

#include <QWidget>
#include <QTcpSocket>
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>

#include <items.h>

namespace Ui {
class sales_manager;
}

class sales_manager : public QWidget
{
    Q_OBJECT

public:
    explicit sales_manager(QWidget *parent = nullptr);
    ~sales_manager();
    void setSocket(QTcpSocket* socket);
    items *it;
private:
    QTcpSocket *socket;
    QByteArray Data;
    quint16 nextBlockSize;
    //void see_table(const QString &jsonString);



public slots:
    void slotReadyRead();

private slots:
    void on_back_clicked();

    void on_see_items_clicked();


signals:
    void backToMain();

private:
    Ui::sales_manager *ui;
};

#endif // SALES_MANAGER_H
