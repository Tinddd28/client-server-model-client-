#ifndef MESSAGE_H
#define MESSAGE_H

#include <QWidget>

namespace Ui {
class message;
}

class message : public QWidget
{
    Q_OBJECT

public:
    explicit message(QWidget *parent = nullptr);
    ~message();

private slots:

    void on_send_clicked();

    void on_back_clicked();
signals:
    void backToMm();
    void SendMes();
private:
    Ui::message *ui;
};

#endif // MESSAGE_H
