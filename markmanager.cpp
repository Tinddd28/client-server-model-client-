#include "markmanager.h"
#include "ui_markmanager.h"

markmanager::markmanager(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::markmanager)
{
    ui->setupUi(this);
}

markmanager::~markmanager()
{
    delete ui;
}
