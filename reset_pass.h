#ifndef RESET_PASS_H
#define RESET_PASS_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class reset_pass;
}

class reset_pass : public QDialog
{
    Q_OBJECT

public:
    explicit reset_pass(QWidget *parent = nullptr);
    ~reset_pass();

    void input_pass();

    void handle_flag(int flag);

private slots:
    void on_reset_clicked();

    void on_surname_returnPressed();

    void on_reset_2_clicked();

signals:
    void back();
    void send_data_for_reset(QString, QString, QString, QString);
    void send_request_for_open(QString, QString, QString, QString);

private:
    Ui::reset_pass *ui;
};

#endif // RESET_PASS_H
