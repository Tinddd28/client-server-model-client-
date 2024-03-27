#ifndef MARKMANAGER_H
#define MARKMANAGER_H

#include <QWidget>

namespace Ui {
class markmanager;
}

class markmanager : public QWidget
{
    Q_OBJECT

public:
    explicit markmanager(QWidget *parent = nullptr);
    ~markmanager();

private:
    Ui::markmanager *ui;
};

#endif // MARKMANAGER_H
