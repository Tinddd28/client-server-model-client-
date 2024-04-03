#include "orders.h"
#include "ui_orders.h"

orders::orders(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::orders)
{
    ui->setupUi(this);
}

orders::~orders()
{
    delete ui;
}

void orders::on_back_clicked()
{
    emit back();
    this->close();
}

void orders::setOrders(const QString &jsonString)
{
    this->orderss = jsonString;
}

void orders::outTable()
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(orderss.toUtf8());
    QJsonArray jsonArray = jsonDoc.array();

    if (jsonArray.size() == 0)
    {
        QMessageBox::warning(this, "Ошибка!\t", "Список заказов пуст!");
        return;
    }

    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(0);

    int row = 0;
    for (const auto& jsonValue : jsonArray)
    {
        QJsonObject jsonObj = jsonValue.toObject();
        if (row == 0)
        {
            ui->tableWidget->setColumnCount(5);
            QStringList headers = { "Название", "Имя", "Фамилия", "Сумма", "Дата" };
            ui->tableWidget->setHorizontalHeaderLabels(headers);
        }

        ui->tableWidget->insertRow(row);
        QTableWidgetItem* itemName = new QTableWidgetItem(jsonObj.value("item_name").toString());
        QTableWidgetItem* NameTime = new QTableWidgetItem(jsonObj.value("person_name").toString());
        QTableWidgetItem* SurnameItem = new QTableWidgetItem(jsonObj.value("person_surname").toString());
        QTableWidgetItem* priceItem = new QTableWidgetItem(jsonObj.value("price").toDouble());
        QTableWidgetItem* dateItem = new QTableWidgetItem(jsonObj.value("date_order").toString());

        ui->tableWidget->setItem(row, 0, itemName);
        ui->tableWidget->setItem(row, 1, NameTime);
        ui->tableWidget->setItem(row, 2, SurnameItem);
        ui->tableWidget->setItem(row, 3, priceItem);
        ui->tableWidget->setItem(row, 4, dateItem);
        row++;
    }
}
