#ifndef ADDUSER_H
#define ADDUSER_H

#include <QWidget>
#include <QMessageBox>
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QMessageBox>

namespace Ui {
class adduser;
}

class adduser : public QWidget
{
    Q_OBJECT

public:
    explicit adduser(QWidget *parent = nullptr);
    ~adduser();
    void setUser(QString);

private:
    QString user;
private slots:
    void on_back_clicked();

    void on_add_clicked();
signals:
    void back();
    void add(QString, QString, QString, QString, QString, QString);

private:
    Ui::adduser *ui;
};

#endif // ADDUSER_H
