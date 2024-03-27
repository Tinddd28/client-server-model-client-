#include "director.h"
#include "ui_director.h"

director::director(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::director)
{
    ui->setupUi(this);
}

director::~director()
{
    delete ui;
}
