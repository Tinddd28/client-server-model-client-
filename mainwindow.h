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

private slots:
    void on_pushButton_clicked();
    void slotReadyRead();

    void on_lineEdit_2_returnPressed();

    void on_checkBox_stateChanged();

private:
    QTcpSocket *socket;
    QByteArray Data;
    void SendToServer();
    quint16 nextBlockSize;
    void SendLogin(QString user, QString password);
    sales_manager* sm;


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
