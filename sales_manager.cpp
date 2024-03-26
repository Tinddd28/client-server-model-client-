#include "sales_manager.h"
#include "ui_sales_manager.h"

sales_manager::sales_manager(QWidget *parent) :
    QWidget(parent), socket(nullptr),
    ui(new Ui::sales_manager)
{
    ui->setupUi(this);
    it = new items();
    connect(it, &items::backtosm, this, &sales_manager::show);
}

sales_manager::~sales_manager()
{
    delete ui;
}

void sales_manager::setSocket(QTcpSocket *socket)
{
    this->socket = socket;
}

void sales_manager::on_back_clicked()
{
    emit backToMain();
    this->hide();
}

void sales_manager::on_see_items_clicked()
{

    it->show();
    this->hide();
}





