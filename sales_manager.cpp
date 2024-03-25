#include "sales_manager.h"
#include "ui_sales_manager.h"

sales_manager::sales_manager(QWidget *parent) :
    QWidget(parent), socket(nullptr),
    ui(new Ui::sales_manager)
{
    ui->setupUi(this);
    //connect(socket, &QTcpSocket::readyRead, this, &sales_manager::slotReadyRead);
    //socket = new QTcpSocket;
    it = new items();
    //socket->connectToHost("192.168.6.133", 2323);
    connect(it, &items::backtosm, this, &sales_manager::show);
}

sales_manager::~sales_manager()
{
    //disconnect(socket, &QTcpSocket::readyRead, this, &sales_manager::slotReadyRead);
    //socket->disconnectFromHost();
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

void sales_manager::slotReadyRead()
{
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_5_14);
    if (in.status() == QDataStream::Ok)
    {
        for (;;)
        {
            if (nextBlockSize == 0)
            {
                if (socket->bytesAvailable() < 2) break;
                in >> nextBlockSize;
            }
            if (socket->bytesAvailable() < nextBlockSize) break;
            int flagOfData;
            in >> flagOfData;
            qDebug() << flagOfData;
            if (flagOfData == 2) // items data
            {
                QString jsonString;
                in >> jsonString;
                it->outTable(jsonString);
                this->hide();
                qDebug() << jsonString;
            }
        }
    }
}




