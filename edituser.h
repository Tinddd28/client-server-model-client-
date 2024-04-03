#ifndef EDITUSER_H
#define EDITUSER_H

#include <QWidget>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QDebug>
#include <QCryptographicHash>
#include <QMessageBox>


namespace Ui {
class edituser;
}

class edituser : public QWidget
{
    Q_OBJECT

public:
    explicit edituser(QWidget *parent = nullptr);
    ~edituser();
    void setUser(QString);
    void setCombo();
private slots:
    void on_back_clicked();

    void on_edit_clicked();

private:
    QString user;

signals:
    void back();
    void send(QJsonDocument);
private:
    Ui::edituser *ui;
};

#endif // EDITUSER_H
