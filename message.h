#ifndef MESSAGE_H
#define MESSAGE_H

#include <QWidget>
#include <QJsonParseError>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QMessageBox>
#include <QDebug>
#include <QVector>
#include <QDataStream>

namespace Ui {
class message;
}

class message : public QWidget
{
    Q_OBJECT

public:
    explicit message(QWidget *parent = nullptr);
    ~message();
    void setClients(const QString&);

private:
    QJsonDocument jsonDoc;
    struct ForMes
    {
        QString mail;
        QString name;
        QString surname;
        QString message;

        // Метод сериализации структуры ForMes в QByteArray
        QByteArray serialize() const
        {
            QByteArray byteArray;
            QDataStream stream(&byteArray, QIODevice::WriteOnly);
            stream << mail << name << surname << message;
            return byteArray;
        }

        // Статический метод десериализации QByteArray в структуру ForMes
        static ForMes deserialize(const QByteArray& byteArray)
        {
            ForMes fm;
            QDataStream stream(byteArray);
            stream >> fm.mail >> fm.name >> fm.surname >> fm.message;
            return fm;
        }
    };
    QByteArray serializeVector(const QVector<ForMes>& vector)
    {
        QByteArray byteArray;
        QDataStream stream(&byteArray, QIODevice::WriteOnly);

        // Сначала записываем размер вектора
        stream << vector.size();

        // Затем сериализуем каждую структуру в векторе
        for (const ForMes& item : vector)
        {
            // Записываем данные каждой структуры в поток
            stream << item.mail << item.name << item.surname << item.message;
        }

        return byteArray;
    }


private slots:
    void ShowComboBox();

    void on_send_clicked();

    void on_back_clicked();

    //void setCombo();
signals:
    void backToMm();
    void SendMes(QByteArray);
private:
    Ui::message *ui;
};

#endif // MESSAGE_H
