#ifndef ORDER_H
#define ORDER_H

#include <QWidget>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QDebug>

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


private slots:
    void on_order_2_clicked();
    void on_back_clicked();


signals:
    void backToSm();

private:
    Ui::order *ui;
};

#endif // ORDER_H
