#include "director.h"
#include "ui_director.h"

director::director(QString server_ip, int server_port, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::director)
{
    this->server_ip = server_ip;
    this->server_port = server_port;
    ui->setupUi(this);
}

director::~director()
{
    delete ui;
}
