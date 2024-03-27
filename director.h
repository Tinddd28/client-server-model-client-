#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <QWidget>

namespace Ui {
class director;
}

class director : public QWidget
{
    Q_OBJECT

public:
    explicit director(QWidget *parent = nullptr);
    ~director();

private:
    Ui::director *ui;
};

#endif // DIRECTOR_H
