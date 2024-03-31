#include "clients.h"
#include "ui_clients.h"

clients::clients(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::clients)
{
    ui->setupUi(this);
}

clients::~clients()
{
    delete ui;
}

void clients::on_back_clicked()
{
    emit backToSm();
    this->close();
    ui->tableWidget->clear();
}

 void clients::OutTable(QString jsonString)
 {
     QJsonParseError error;
     QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonString.toUtf8(), &error);

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
             ui->tableWidget->setColumnCount(4); // Фиксированное количество столбцов
             QStringList headers = { "Имя", "Фамилия", "Почта", "Телефон" };
             ui->tableWidget->setHorizontalHeaderLabels(headers);
         }

         ui->tableWidget->insertRow(row);
         QTableWidgetItem* itemName = new QTableWidgetItem(jsonObject.value("name").toString());
         QTableWidgetItem* surnameItem = new QTableWidgetItem(jsonObject.value("surname").toString());
         QTableWidgetItem* mailItem = new QTableWidgetItem(jsonObject.value("mail").toString());
         QTableWidgetItem* phoneItem = new QTableWidgetItem(jsonObject.value("phone").toString());

         ui->tableWidget->setItem(row, 0, itemName);
         ui->tableWidget->setItem(row, 1, surnameItem);
         ui->tableWidget->setItem(row, 2, mailItem);
         ui->tableWidget->setItem(row, 3, phoneItem);
         row++;
     }
 }
