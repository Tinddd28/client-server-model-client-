#include "usview.h"
#include "ui_usview.h"

usview::usview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::usview)
{
    ui->setupUi(this);
}

usview::~usview()
{
    delete ui;
}

void usview::OutTable(QString json)
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(json.toUtf8());

    QJsonArray jsonArray = jsonDoc.array();
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(0);
    int row = 0;
    for (const auto& jsonValue : jsonArray)
    {
        QJsonObject jsonObject = jsonValue.toObject();
        if (row == 0)
        {
            ui->tableWidget->setColumnCount(5); // Фиксированное количество столбцов
            QStringList headers = { "Логин", "Имя", "Фамилия", "Должность", "Почта"};
            ui->tableWidget->setHorizontalHeaderLabels(headers);
        }

        ui->tableWidget->insertRow(row);
        QTableWidgetItem* itemLogin = new QTableWidgetItem(jsonObject.value("login").toString());
        QTableWidgetItem* nameItem = new QTableWidgetItem(jsonObject.value("user_name").toString());
        QTableWidgetItem* surnameItem = new QTableWidgetItem(jsonObject.value("user_surname").toString());
        QTableWidgetItem* dolItem = new QTableWidgetItem(jsonObject.value("dolzh").toString());
        QTableWidgetItem* mailItem = new QTableWidgetItem(jsonObject.value("mail").toString());


        ui->tableWidget->setItem(row, 0, itemLogin);
        ui->tableWidget->setItem(row, 1, nameItem);
        ui->tableWidget->setItem(row, 2, surnameItem);
        ui->tableWidget->setItem(row, 3, dolItem);
        ui->tableWidget->setItem(row, 4, mailItem);
        row++;
    }


}

void usview::on_back_clicked()
{
    ui->tableWidget->clear();
    emit back();
    this->close();
}
