#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QTcpServer>
#include <QDataStream>
#include <QMessageBox>
#include <QTimer>
#include <QCryptographicHash>
#include <sales_manager.h>

#include <QDebug>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    sales_manager* sm;

private slots:
    void on_pushButton_clicked();
    void slotReadyRead();

    void on_lineEdit_2_returnPressed();

    void on_checkBox_stateChanged();

    void connectToServer();


private:
    QString server_ip = "192.168.6.133";
    int server_port = 2323;
    QTcpSocket *socket;
    QByteArray Data;
    void SendLogin(QString user, QString password);
    void selection_role(int id);
    int flag_auth = 0;


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
