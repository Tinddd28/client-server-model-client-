#include "mess.h"
#include "ui_mess.h"

mess::mess(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mess)
{
    ui->setupUi(this);
}

mess::~mess()
{
    delete ui;
}

void mess::on_back_clicked()
{
    emit back();
    this->close();
}

void mess::SetMessages(QString messages)
{
    this->messages = messages;
}

void mess::OutTable()
{
    QJsonDocument jsonDoc = QJsonDocument::fromJson(messages.toUtf8());
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
            QStringList headers = { "Почта", "Имя", "Фамилия", "Дата", "Время" };
            ui->tableWidget->setHorizontalHeaderLabels(headers);
        }

        ui->tableWidget->insertRow(row);
        QTableWidgetItem* maleItem = new QTableWidgetItem(jsonObj.value("mail").toString());
        QTableWidgetItem* NameTime = new QTableWidgetItem(jsonObj.value("name").toString());
        QTableWidgetItem* SurnameItem = new QTableWidgetItem(jsonObj.value("surname").toString());
        QTableWidgetItem* DateItem = new QTableWidgetItem(jsonObj.value("date").toString());
        QTableWidgetItem* TimeItem = new QTableWidgetItem(jsonObj.value("time").toString());

        ui->tableWidget->setItem(row, 0, maleItem);
        ui->tableWidget->setItem(row, 1, NameTime);
        ui->tableWidget->setItem(row, 2, SurnameItem);
        ui->tableWidget->setItem(row, 3, DateItem);
        ui->tableWidget->setItem(row, 4, TimeItem);
        row++;
    }
}
