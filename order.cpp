#include "order.h"
#include "ui_order.h"

order::order(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::order)
{
    ui->setupUi(this);
    connect(ui->comboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(SeeAmount()));
}

order::~order()
{
    items = QJsonDocument();
    clients = QJsonDocument();
    delete ui;
}

void order::SeeAmount()
{
    QString curItem = ui->comboBox->currentText();
    QJsonArray jsonArray = items.array();
    int amount;
    for (const auto& jsonValue : jsonArray)
    {
        QJsonObject jsonObj = jsonValue.toObject();
        if (jsonObj.value("item_name").toString() == curItem)
        {
            amount = jsonObj.value("amount").toInt();
            break;
        }
    }
    ui->havee->setText("В наличии:\t" + QString::number(amount));
}

void order::on_order_2_clicked()
{
    QString name = ui->name->text();
    QString surname = ui->surname->text();
    QString mail = ui->mail->text();
    QString phone = ui->phone->text();
    int am = ui->amount->text().toInt();
    QString curItem = ui->comboBox->currentText();
    QJsonArray jsonArray = items.array();

    for (int i = 0; i < jsonArray.size(); i++)
    {
        QJsonObject jsonObj = jsonArray[i].toObject();
        if (jsonObj.value("item_name").toString() == curItem)
        {
            int amount = jsonObj.value("amount").toInt();
            if (amount < am) //проверка для того, чтобы число товаров не стало отрицательным // в потенциале можно добавить уход в минус для
                //взаимодействия с потребностями клиентов.
            {
                QMessageBox::warning(this, "Ошибка!\t", "Количество желаемого товара превышает количество имеющегося!");
                ui->amount->clear();
                return;
            }
            else
            {
                QJsonArray jsArray = clients.array();
                for (int j = 0; j < jsArray.size(); j++)
                {
                    QJsonObject jsObj = jsArray[j].toObject();
                    if (jsObj.value("name").toString() == name && jsObj.value("surname").toString() == surname)
                    {
                        QMessageBox msgBox;
                        msgBox.setText("Такой пользователь уже есть.");
                        msgBox.setInformativeText("Хотите изменить контактные данные?");
                        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
                        msgBox.setDefaultButton(QMessageBox::Save);
                        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
                        msgBox.setDefaultButton(QMessageBox::Save);
                        msgBox.setButtonText(QMessageBox::Save, "Изменить");
                        msgBox.setButtonText(QMessageBox::Discard, "Оставить");
                        msgBox.setButtonText(QMessageBox::Cancel, "Отменить");
                        int ret = msgBox.exec();
                        if (ret == QMessageBox::Save)
                        {
                            jsObj["mail"] = mail;
                            jsObj["phone"] = phone;
                            jsArray[j] = jsObj;
                            break;

                        }
                        else if (ret == QMessageBox::Cancel) return;
                    }
                    else
                    {
                        QJsonObject newClient;
                        newClient["name"] = name;
                        newClient["surname"] = surname;
                        newClient["mail"] = mail;
                        newClient["phone"] = phone;
                        jsArray.append(newClient);
                        break;
                    }


                    clients.setArray(jsArray); // Добавить изменение данных!!!!
                }
            }
            jsonObj["amount"] = amount - am; //осуществление продажи (умненьшение ассортимента)
            jsonArray[i] = jsonObj;
            items.setArray(jsonArray);
            break;
        }
    }
    emit broadcastdata(items, clients);
    this->close();
    ui->name->clear();
    ui->surname->clear();
    ui->mail->clear();
    ui->phone->clear();
    ui->amount->clear();
    ui->comboBox->clear();
    ui->price->clear();
}

void order::setClients(QString json)
{
    QJsonParseError error;
    clients = QJsonDocument::fromJson(json.toUtf8(), &error);
}

void order::setItems(QString json)
{
    QJsonParseError error;
    items = QJsonDocument::fromJson(json.toUtf8(), &error);
}

void order::on_back_clicked()
{
    ui->name->clear();
    ui->surname->clear();
    ui->mail->clear();
    ui->phone->clear();
    ui->amount->clear();
    ui->comboBox->clear();
    ui->price->clear();
    emit backToSm();
    this->close();
}

void order::addInComboBox(QString jsonString)
{
    QJsonParseError error;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonString.toUtf8(), &error);

    QJsonArray jsonArray = jsonDoc.array();

    for (const auto& jsonValue : jsonArray)
    {
        QJsonObject jsonObj = jsonValue.toObject();

        if (jsonObj.value("amount").toInt() > 0)
            ui->comboBox->addItem(jsonObj.value("item_name").toString());
    }
}
