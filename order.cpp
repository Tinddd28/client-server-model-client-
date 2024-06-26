#include "order.h"
#include "ui_order.h"

order::order(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::order)
{
    ui->setupUi(this);
    QIntValidator *intValidator = new QIntValidator;
    QDoubleValidator *doubleValidator = new QDoubleValidator;
    ui->amount->setValidator(intValidator);
    ui->price->setValidator(doubleValidator);
    connect(ui->comboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(SeeAmount()));
    connect(ui->amount, SIGNAL(textChanged(QString)), this, SLOT(setPrice()));
}

void order::setPrice()
{
    QJsonArray jsonArray = items.array();

    for (int i = 0; i < jsonArray.size(); i++)
    {
        QJsonObject jsonObj = jsonArray[i].toObject();
        if (jsonObj["item_name"].toString() == ui->comboBox->currentText())
        {
            double pr = jsonObj["price"].toDouble();
            ui->price->setText(QString::number(pr * ui->amount->text().toInt()));
        }
    }
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
    QJsonArray jsArray = clients.array();
    int amount;
    for (int i = 0; i < jsonArray.size(); i++)
    {
        QJsonObject jsonObj = jsonArray[i].toObject();
        if (jsonObj.value("item_name").toString() == curItem)
        {
            amount = jsonObj.value("amount").toInt();
            if (amount < am) //проверка для того, чтобы число товаров не стало отрицательным // в потенциале можно добавить уход в минус для
                //взаимодействия с потребностями клиентов.
            {
                QMessageBox::warning(this, "Ошибка!\t", "Количество желаемого товара превышает количество имеющегося!");
                ui->amount->clear();
                return;
            }
            else
            {
                bool clientFound = false;

                for (int j = 0; j < jsArray.size(); j++)
                {
                    QJsonObject jsObj = jsArray[j].toObject();
                    if (jsObj.value("name").toString() == name && jsObj.value("surname").toString() == surname)
                    {
                        clientFound = true;
                        QMessageBox msgBox;
                        msgBox.setText("Такой пользователь уже есть.");
                        msgBox.setInformativeText("Хотите изменить контактные данные?");
                        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
                        msgBox.setDefaultButton(QMessageBox::Save);
                        msgBox.setButtonText(QMessageBox::Save, "Изменить");
                        msgBox.setButtonText(QMessageBox::Discard, "Оставить");
                        msgBox.setButtonText(QMessageBox::Cancel, "Отменить");
                        int ret = msgBox.exec();
                        if (ret == QMessageBox::Save) {
                            jsObj["mail"] = mail;
                            jsObj["phone"] = phone;
                            jsArray[j] = jsObj;
                        } else if (ret == QMessageBox::Cancel) {
                            return;
                        }
                        break;
                    }
                }

                if (!clientFound)
                {
                    QJsonObject newClient;
                    newClient["name"] = name;
                    newClient["surname"] = surname;
                    newClient["mail"] = mail;
                    newClient["phone"] = phone;
                    jsArray.append(newClient);
                }
            }
            clients.setArray(jsArray);
            jsonObj["amount"] = amount - am; //осуществление продажи (умненьшение ассортимента)
            jsonArray[i] = jsonObj;
            items.setArray(jsonArray);
            break;
        }
    }
    double pr = ui->price->text().toDouble();
    emit broadcastdata(items, clients, pr, name, surname, curItem);
    QMessageBox::information(this, "Успешно!\t", "Заказ оформлен!");
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
