#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    socket->disconnectFromHost();
    sm = new sales_manager();
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotReadyRead);

    connect(sm, &sales_manager::backToMain, this, &MainWindow::show);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    socket->connectToHost("192.168.6.133", 2323);

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
    QByteArray responseData = socket->readAll();
    QList<QByteArray> responses = responseData.split('#');

    for (const QByteArray& response : responses)
    {
        if (response.isEmpty()) continue;

        QJsonDocument jsonDoc = QJsonDocument::fromJson(response);
        QJsonObject jsonObj = jsonDoc.object();

        QString window = jsonObj.value("window").toString();
        if(window == "mainwindow")
        {
            QString action = jsonObj.value("action").toString();
            if (action == "login")
            {
                QString status = jsonObj.value("status").toString();
                if (status == "success")
                {
                    int id = jsonObj.value("id").toInt();
                    selection_role(id);
                }
                else if (status == "fail")
                    qDebug() << "Erorr";
            }
        }
    }
}

void MainWindow::selection_role(int id)
{
    socket->disconnect();
    if (id == 1)
    {

    }
    else if (id == 2)
    {
        sm->setSocket(socket);
        sm->show();
        this->hide();
    }
    else if (id == 3)
    {

    }
}

void MainWindow::SendLogin(QString user, QString password)
{
    QByteArray passwordData = password.toUtf8();
    QByteArray passwordHash = QCryptographicHash::hash(passwordData, QCryptographicHash::Sha256).toHex();
    QString pass = passwordHash;
    QJsonObject jsonObj;
    jsonObj.insert("window", "mainwindow");
    jsonObj.insert("action", "login");
    QJsonObject data;
    data.insert("us_name", user);
    data.insert("us_pass", pass);

    jsonObj.insert("data", data);

    QJsonDocument jsonDoc(jsonObj);
    socket->write(jsonDoc.toJson());

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
