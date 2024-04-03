#ifndef CLIENTSD_H
#define CLIENTSD_H

#include <QWidget>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class clientsd;
}

class clientsd : public QWidget
{
    Q_OBJECT

public:
    explicit clientsd(QWidget *parent = nullptr);
    ~clientsd();
    void OutTable(QString jsonString);

private slots:
    void on_back_clicked();

signals:
    void back();
private:
    Ui::clientsd *ui;
};

#endif // CLIENTSD_H
