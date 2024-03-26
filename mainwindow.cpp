#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    sm = new sales_manager(socket);
    socket->disconnectFromHost();
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, socket, &MainWindow::deleteLater);
    connect(sm, &sales_manager::backToMain, this, &MainWindow::show);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    socket->connectToHost("192.168.6.133", 2323);
    nextBlockSize = 0;

}

MainWindow::~MainWindow()
{
    delete socket;
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    SendLogin(ui->lineEdit->text(), ui->lineEdit_2->text());
}

void MainWindow::slotReadyRead()
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
            if (flagOfData == 1) //login
            {
                QString status;
                in >> status;
                qDebug() << status;
                if (status == "director")
                {

                }
                else if (status == "salesmanager")
                {
                    sm->show();
                    this->hide();

                }


            }
            else if (flagOfData == 2) //data
            {
                QString jsonString;
                in >> jsonString;
                qDebug() << jsonString;
                sm->it->outTable(jsonString);
            }
            nextBlockSize = 0;
            break;
        }
    }
    else
    {
        qDebug() << "error";
    }
}

void MainWindow::SendLogin(QString user, QString password)
{
    QByteArray passwordData = password.toUtf8();
    QByteArray passwordHash = QCryptographicHash::hash(passwordData, QCryptographicHash::Sha256).toHex();
    qDebug() << passwordHash;
    Data.clear();
    QDataStream out(&Data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_5_14);
    out << quint16(0) << 1 << user << passwordHash;
    out.device()->seek(0);
    out << quint16(Data.size() - sizeof(quint16));
    socket->write(Data);
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}


void MainWindow::on_lineEdit_2_returnPressed()
{
    SendLogin(ui->lineEdit->text(), ui->lineEdit_2->text());
}

void MainWindow::on_checkBox_stateChanged()
{
    if (ui->checkBox->isChecked())
        ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
    else
        ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}
