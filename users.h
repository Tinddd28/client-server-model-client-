#ifndef USERS_H
#define USERS_H

#include <QWidget>
#include <adduser.h>
#include <edituser.h>
#include <deluser.h>

namespace Ui {
class users;
}

class users : public QWidget
{
    Q_OBJECT

public:
    explicit users(QWidget *parent = nullptr);
    ~users();
    void SetUser(QString user);
    deluser *du;
    adduser *au;
    edituser *eu;

private:
    void add(QString, QString, QString, QString, QString, QString);

    QString user;
    void send(QJsonDocument);
    void senddelus(QString);

private slots:
    void on_create_clicked();

    void on_edit_clicked();

    void on_delete_2_clicked();

    void on_back_clicked();

signals:
    void back();
    void edit(QJsonDocument);
    void senddel(QString);
    void sendReqForEdit(QString action);
    void send_data(QString, QString, QString, QString, QString, QString);

private:
    Ui::users *ui;
};

#endif // USERS_H
