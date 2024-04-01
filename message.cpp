#include "message.h"
#include "ui_message.h"

message::message(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::message)
{
    ui->setupUi(this);
}

message::~message()
{
    delete ui;
}

void message::on_send_clicked()
{
    emit SendMes();
    this->close();
}

void message::on_back_clicked()
{
    emit backToMm();
    this->close();
}
