#ifndef OTHERMENU_H
#define OTHERMENU_H

#include "utils.h"
#include "input.h"
#include "backup.h"

namespace Ui {
class othermenu;
}

class othermenu : public QWidget
{
    Q_OBJECT

public:

    ~othermenu();
    explicit othermenu(QWidget *parent = nullptr, QString text="");


private slots:
    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::othermenu *myui;
    QFileSystemModel* m_fsmodel;

};

#endif // OTHERMENU_H
