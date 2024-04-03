#ifndef ITEMS_H
#define ITEMS_H

#include <QWidget>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QDebug>

namespace Ui {
class items;
}

class items : public QWidget
{
    Q_OBJECT

public:
    explicit items(QWidget *parent = nullptr);
    ~items();

    void outTable(const QString &jsonString);


private:


private slots:
    void on_pushButton_clicked();

signals:
    void backtosm();

private:
    Ui::items *ui;
};

#endif // ITEMS_H
