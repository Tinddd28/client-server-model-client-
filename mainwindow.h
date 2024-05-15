#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QTcpSocket>
#include <QDataStream>
#include <QMessageBox>
#include <QTimer>
#include <QCryptographicHash>
#include <sales_manager.h>
#include <director.h>
#include <markmanager.h>
#include <QDebug>

#include <reset_pass.h>
#include <input_pass.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    reset_pass *r_p;
    sales_manager* sm;
    director* dir;
    markmanager* mm;
    input_pass* i_p;

private slots:
    void on_pushButton_clicked();
    void slotReadyRead();

    void on_lineEdit_2_returnPressed();

    void on_checkBox_stateChanged();

    void connectToServer();

    void checkConnection();

    void on_pushButton_2_clicked();

    void send_data_for_reset(QString, QString, QString, QString);

    void open_window_for_change_pass(QString name, QString sname, QString login, QString mail);

    void change_pass(QString);

private:
    QString server_ip = "127.0.0.1";
    int server_port = 2323;
    QTcpSocket *socket;
    QByteArray Data;
    void SendLogin(QString user, QString password);
    void selection_role(int id);
    int flag_auth = 0;
    QTimer *timer;
    QString name;
    QString sname;
    QString mail;
    QString login;


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
