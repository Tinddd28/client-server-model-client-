#include "items.h"
#include "ui_items.h"

items::items(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::items)
{
    ui->setupUi(this);
}

items::~items()
{
    delete ui;
}

void items::on_pushButton_clicked()
{
    emit backtosm();
    this->close();
}

void items::outTable(const QString &jsonString)
{
    QJsonParseError error;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonString.toUtf8(), &error);

    if (error.error != QJsonParseError::NoError)
    {
        qDebug() << "Ошибка разбора JSON: " << error.errorString();
        return;
    }

    if (!jsonDoc.isArray())
    {
        qDebug() << "JSON не массив";
        return;
    }

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
