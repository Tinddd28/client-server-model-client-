#include "sales_manager.h"
#include "ui_sales_manager.h"

sales_manager::sales_manager(QTcpSocket* socket, QWidget *parent) :
    QWidget(parent), socket(socket),
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


void sales_manager::on_back_clicked()
{
    emit backToMain();
    this->hide();
}

void sales_manager::on_see_items_clicked()
{
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_14);
    out << quint16(0) << 2;
    out.device()->seek(0);
    out << quint16(Data.size() - sizeof(quint16));
    socket->write(Data);
    it->show();
    this->hide();
}





