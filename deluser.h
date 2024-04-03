#ifndef DELUSER_H
#define DELUSER_H

#include <QWidget>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class deluser;
}

class deluser : public QWidget
{
    Q_OBJECT

public:
    explicit deluser(QWidget *parent = nullptr);
    ~deluser();
    void SetUser(QString user);
    void SetCombo();

private:
    QString user;

signals:
    void back();
    void change(QString);

private slots:
    void on_back_clicked();

    void on_del_clicked();

private:
    Ui::deluser *ui;
};

#endif // DELUSER_H
