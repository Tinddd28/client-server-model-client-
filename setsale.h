#ifndef SETSALE_H
#define SETSALE_H

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
class setSale;
}

class setSale : public QWidget
{
    Q_OBJECT

public:
    explicit setSale(QWidget *parent = nullptr);
    ~setSale();

    void setComboBox(const QString& jsonString);

private slots:

    void on_accept_clicked();

    void on_back_clicked();

private:

    double price;

signals:
    void backTomm();
    void SendNewPrice();

private:
    Ui::setSale *ui;
};

#endif // SETSALE_H
