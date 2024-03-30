#include "clients.h"
#include "ui_clients.h"

clients::clients(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clients)
{
    ui->setupUi(this);
}

clients::~clients()
{
    delete ui;
}

void clients::on_back_clicked()
{
    emit backToSm();
    this->close();
}
