#include "itemsd.h"
#include "ui_itemsd.h"

itemsd::itemsd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::itemsd)
{
    ui->setupUi(this);
}

itemsd::~itemsd()
{
    delete ui;
}



void itemsd::outTable(const QString &jsonString)
{
    QJsonParseError error;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonString.toUtf8(), &error);

    QJsonArray jsonArray = jsonDoc.array();
    if (jsonArray.size() == 0)
    {
        QMessageBox::warning(this, "Ошибка!\t", "Список товаров пуст!");
        return;
    }
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
            QStringList headers = { "Название", "Цена", "Тип", "Количество" };
            ui->tableWidget->setHorizontalHeaderLabels(headers);
        }

        ui->tableWidget->insertRow(row);
        QTableWidgetItem* itemNameItem = new QTableWidgetItem(jsonObject.value("item_name").toString());
        QTableWidgetItem* priceItem = new QTableWidgetItem(QString::number(jsonObject.value("price").toDouble()));
        QTableWidgetItem* typeItem = new QTableWidgetItem(jsonObject.value("type").toString());
        QTableWidgetItem* amountItem = new QTableWidgetItem(QString::number(jsonObject.value("amount").toInt()));

        ui->tableWidget->setItem(row, 0, itemNameItem);
        ui->tableWidget->setItem(row, 1, priceItem);
        ui->tableWidget->setItem(row, 2, typeItem);
        ui->tableWidget->setItem(row, 3, amountItem);
        row++;
    }
}

void itemsd::on_back_clicked()
{
    emit backb();
    this->close();
    ui->tableWidget->clear();
}
