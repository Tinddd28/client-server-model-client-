#ifndef INPUT_PASS_H
#define INPUT_PASS_H

#include <QDialog>
#include <QMessageBox>
#include <QCryptographicHash>
#include <QDebug>

namespace Ui {
class input_pass;
}

class input_pass : public QDialog
{
    Q_OBJECT

public:
    explicit input_pass(QWidget *parent = nullptr);
    ~input_pass();

private:
    QString pass;

private slots:
    void on_ok_clicked();


    void on_checkBox_stateChanged(int arg1);

signals:
    void change_pass(QString);

private:
    Ui::input_pass *ui;
};

#endif // INPUT_PASS_H
