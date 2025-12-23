#ifndef INPUT_H
#define INPUT_H

#include "utils.h"
#include "mainwindow.h"
#include "othermenu.h"

namespace Ui {
    class input;
}

class input : public QWidget
{
    Q_OBJECT

public:
    explicit input(QWidget *parent = nullptr);
    ~input();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::input *myui;
};

#endif // INPUT_H
