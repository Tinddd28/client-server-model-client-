#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    socket->disconnectFromHost();
    //socket->connectToHost(server_ip, server_port);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotReadyRead);
    sm = new sales_manager(server_ip, server_port);
    dir = new director(server_ip, server_port);
    mm = new markmanager(server_ip, server_port);
    connect(sm, &sales_manager::backToMain, this, &MainWindow::show);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    connect(socket, &QTcpSocket::disconnected, sm, &sales_manager::resetSocket);
    connect(socket, &QTcpSocket::disconnected, mm, &markmanager::resetSocket);
    connect(mm, &markmanager::backToMain, this, &MainWindow::show);
}

MainWindow::~MainWindow()
{
    delete socket;
    delete sm;
    delete dir;
    delete ui;
}

void MainWindow::connectToServer()
{
    socket->connectToHost(server_ip, server_port);
}

void MainWindow::on_pushButton_clicked()
{
    if (ui->lineEdit->text() == "" && ui->lineEdit_2->text() == "")
    {
        QMessageBox::warning(this, "Ошибка\t", "Заполните поля логина и пароля!");
        flag_auth = 1;
    }
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
                {
                    if (flag_auth == 0)
                        QMessageBox::warning(this, "Ошибка\t", "Неправильные данные");
                    flag_auth = 0;
                }
            }
        }
    }
}

void MainWindow::selection_role(int id)
{
    socket->disconnected();
    socket->close();
    if (id == 1)
    {
        dir->show();
        this->hide();
    }
    else if (id == 2)
    {
        sm->show();
        this->hide();
    }
    else if (id == 3)
    {
        mm->show();
        this->hide();
    }
}

void MainWindow::SendLogin(QString user, QString password)
{
    if(socket->state() != QAbstractSocket::ConnectedState){
           connectToServer();
           QMessageBox::warning(this, "Ошибка", "Нет соединения с сервером");

           return;
    }

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
