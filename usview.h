#ifndef USVIEW_H
#define USVIEW_H

#include <QWidget>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>

namespace Ui {
class usview;
}

class usview : public QWidget
{
    Q_OBJECT

public:
    explicit usview(QWidget *parent = nullptr);
    ~usview();
    void OutTable(QString);

private slots:
    void on_back_clicked();

signals:
    void back();

private:
    Ui::usview *ui;
};

#endif // USVIEW_H
