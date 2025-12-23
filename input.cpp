#include "input.h"
#include "ui_input.h"
input::input(QWidget *parent) :
    QWidget(parent),
    myui(new Ui::input)
{
    myui->setupUi(this);
}

input::~input()
{
    delete myui;
}

void input::on_pushButton_clicked()
{
    QString text = myui->textEdit->toPlainText();
    othermenu *om = new othermenu(nullptr,text);
    this->close();
    om->show();
}

void input::on_pushButton_2_clicked()
{
    MainWindow *ui = new MainWindow();
    this->close();
    ui->show();
}