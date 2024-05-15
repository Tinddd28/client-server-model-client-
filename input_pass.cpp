#include "input_pass.h"
#include "ui_input_pass.h"

input_pass::input_pass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::input_pass)
{
    ui->setupUi(this);
    ui->fpass->setEchoMode(QLineEdit::Password);
    ui->spass->setEchoMode(QLineEdit::Password);
}

input_pass::~input_pass()
{
    delete ui;
}

void input_pass::on_ok_clicked()
{
    QString fpass = ui->fpass->text();
    QString spass = ui->spass->text();
    if (fpass != spass)
    {
        QMessageBox::warning(this, "Ошибка", "Пароли не совпадают!");
        ui->fpass->clear();
        ui->spass->clear();
        return;
    }
    QByteArray passwordData = fpass.toUtf8();
    QByteArray passwordHash = QCryptographicHash::hash(passwordData, QCryptographicHash::Sha256).toHex();
    pass = passwordHash;

    emit change_pass(pass);
    this->close();
}


void input_pass::on_checkBox_stateChanged(int arg1)
{
    if (ui->checkBox->isChecked())
    {
        ui->fpass->setEchoMode(QLineEdit::Normal);
        ui->spass->setEchoMode(QLineEdit::Normal);
    }
    else
    {
        ui->fpass->setEchoMode(QLineEdit::Password);
        ui->spass->setEchoMode(QLineEdit::Password);
    }
}

