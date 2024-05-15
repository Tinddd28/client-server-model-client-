#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    socket->disconnectFromHost();
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotReadyRead);
    sm = new sales_manager(server_ip, server_port);
    dir = new director(server_ip, server_port);
    mm = new markmanager(server_ip, server_port);
    r_p = new reset_pass();
    i_p = new input_pass();
    //connect(sm, &sales_manager::backToMain, this, &MainWindow::show);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
    connect(socket, &QTcpSocket::disconnected, sm, &sales_manager::resetSocket);
    connect(socket, &QTcpSocket::disconnected, mm, &markmanager::resetSocket);
    //connect(mm, &markmanager::backToMain, this, &MainWindow::show);
    //connect(dir, &director::backToMain, this, &MainWindow::show);
    connect(socket, &QTcpSocket::disconnected, dir, &director::resetSocket);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::checkConnection);
    timer->start(5000);
    connectToServer();
    connect(r_p, &reset_pass::back, this, &MainWindow::show);
    connect(r_p, &reset_pass::send_data_for_reset, this, &MainWindow::send_data_for_reset);
    connect(r_p, &reset_pass::send_request_for_open, this, &MainWindow::open_window_for_change_pass);
    connect(i_p, &input_pass::change_pass, this, &MainWindow::show);
    connect(i_p, &input_pass::change_pass, this, &MainWindow::change_pass);

}

MainWindow::~MainWindow()
{
    delete sm;
    delete dir;
    delete ui;
}

void MainWindow::change_pass(QString pass)
{
    QJsonObject jsonObj;
    jsonObj.insert("window", "mainwindow");
    jsonObj.insert("action", "change");
    QJsonObject jsData;
    jsData.insert("pass", pass);
    jsData.insert("name", name);
    jsData.insert("sname", sname);
    jsData.insert("login", login);
    jsData.insert("mail", mail);
    jsonObj.insert("data", jsData);
    qDebug() << login;
    QJsonDocument jsonDoc(jsonObj);
    socket->write(jsonDoc.toJson());
}

void MainWindow::open_window_for_change_pass(QString name, QString sname, QString login, QString mail)
{
    this->login = login;
    this->name = name;
    this->sname = sname;
    this->mail = mail;
    i_p->setWindowTitle("Восстановаление пароля для " + login);
    i_p->show();
}

void MainWindow::send_data_for_reset(QString name, QString sname, QString login, QString mail)
{
    QJsonObject jsonObj;
    jsonObj.insert("window", "mainwindow");
    jsonObj.insert("action", "reset");
    QJsonObject jsonData;
    jsonData.insert("name", name);
    jsonData.insert("sname", sname);
    jsonData.insert("login", login);
    jsonData.insert("mail", mail);
    jsonObj.insert("data", jsonData);

    QJsonDocument jsonDoc(jsonObj);
    socket->write(jsonDoc.toJson());
}

void MainWindow::connectToServer()
{
    socket->connectToHost(server_ip, server_port);
}

void MainWindow::checkConnection()
{
    if (socket->state() == QAbstractSocket::UnconnectedState)
    {
        qDebug() << "Attempting to reconnect...";
        connectToServer();
    }
    else qDebug() << "Connection is active!";
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
            else if (action == "reset")
            {
                int flag = jsonObj.value("flag").toInt();
                qDebug() << flag;
                r_p->handle_flag(flag);
            }
            else if (action == "result")
            {
                int flag = jsonObj.value("result").toInt();
                if (flag)
                {
                    QMessageBox::information(this, "Успешно\t", "Пароль был изменен!");
                }
                else
                {
                    QMessageBox::warning(this, "Ошибка", "Что-то пошло не так...");
                }
                i_p->close();
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
        dir->setWindowTitle("Директор");
        dir->show();
    }
    else if (id == 2)
    {
        sm->setWindowTitle("Менеджер по продажам");
        sm->show();
    }
    else if (id == 3)
    {
        mm->setWindowTitle("Менеджер по маркетингу");
        mm->show();
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



void MainWindow::on_pushButton_2_clicked()
{
    r_p->setWindowTitle("Восстановление пароля");
    r_p->show();
}

