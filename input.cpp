#include "input.h"
#include "ui_input.h"
input::input(QWidget *parent) :
    QWidget(parent),
    inputui(new Ui::input)
{
    inputui->setupUi(this);
}

input::~input()
{
    delete inputui;
}