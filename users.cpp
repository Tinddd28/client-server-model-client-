#include "users.h"
#include "ui_users.h"

users::users(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::users)
{
    ui->setupUi(this);
    au = new adduser();
    eu = new edituser();
    du = new deluser();
    connect(au, &adduser::back, this, &users::show);
    connect(au, &adduser::add, this, &users::show);
    connect(au, &adduser::add, this, &users::add);
    connect(eu, &edituser::back, this, &users::show);
    connect(eu, &edituser::send, this, &users::show);
    connect(eu, &edituser::send, this, &users::send);
    connect(du, &deluser::back, this, &users::show);
    connect(du, &deluser::change, this, &users::show);
    connect(du, &deluser::change, this, &users::senddelus);
}

users::~users()
{
    delete ui;
}

void users::senddelus(QString login)
{
    emit senddel(login);
}

void users::send(QJsonDocument jsonDoc)
{
    emit edit(jsonDoc);
}

void users::add(QString mail, QString name, QString sname, QString dolzh, QString login, QString pass)
{
    emit send_data(mail, name, sname, dolzh, login, pass);
}

void users::SetUser(QString user)
{
    this->user = user;
}

void users::on_create_clicked()
{
    QString action = "adduser";
    emit sendReqForEdit(action);
    au->setWindowTitle("Добавление");
    au->show();
    this->close();
}

void users::on_edit_clicked()
{
    QString action = "edituser";
    eu->setWindowTitle("Редактирование");
    emit sendReqForEdit(action);
    eu->show();
    this->close();
}

void users::on_delete_2_clicked()
{
    QString action = "deluser";
    du->setWindowTitle("Удаление");
    emit sendReqForEdit(action);
    du->show();
    this->close();
}

void users::on_back_clicked()
{
    emit back();
    this->close();
}
