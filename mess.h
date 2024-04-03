#ifndef MESS_H
#define MESS_H

#include <QWidget>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class mess;
}

class mess : public QWidget
{
    Q_OBJECT

public:
    explicit mess(QWidget *parent = nullptr);
    ~mess();
    void OutTable();
    void SetMessages(QString);
private:
    QString messages;

private slots:
    void on_back_clicked();

signals:
    void back();

private:
    Ui::mess *ui;
};

#endif // MESS_H
