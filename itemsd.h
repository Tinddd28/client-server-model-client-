#ifndef ITEMSD_H
#define ITEMSD_H

#include <QWidget>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QDebug>
#include <QMessageBox>

namespace Ui {
class itemsd;
}

class itemsd : public QWidget
{
    Q_OBJECT

public:
    explicit itemsd(QWidget *parent = nullptr);
    ~itemsd();

    void outTable(const QString &jsonString);


private:


private slots:

    void on_back_clicked();

signals:
    void backb();

private:
    Ui::itemsd *ui;
};

#endif // ITEMSD_H
