#include "reset_pass.h"
#include "ui_reset_pass.h"

reset_pass::reset_pass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::reset_pass)
{
    ui->setupUi(this);
}



reset_pass::~reset_pass()
{
    delete ui;
}

void reset_pass::handle_flag(int flag)
{
    if (!flag)
    {
        QMessageBox::warning(this, "Ошибка", "Пользователь с такими данными отстутствует!");
        return;
    }
    else
    {
        QString name = ui->name->text();
        QString sname = ui->surname->text();
        QString login = ui->login->text();
        QString mail = ui->mail->text();
        emit send_request_for_open(name, sname, login, mail);
        this->close();
        ui->name->clear();
        ui->surname->clear();
        ui->login->clear();
        ui->mail->clear();
    }
}

void reset_pass::on_reset_clicked()
{
    QString name = ui->name->text();
    QString sname = ui->surname->text();
    QString login = ui->login->text();
    QString mail = ui->mail->text();
    emit send_data_for_reset(name, sname, login, mail);

}


void reset_pass::on_surname_returnPressed()
{
    QString name = ui->name->text();
    QString sname = ui->surname->text();
    QString login = ui->login->text();
    QString mail = ui->mail->text();
    emit send_data_for_reset(name, sname, login, mail);
}


void reset_pass::on_reset_2_clicked()
{
    this->close();
    emit back();
}

