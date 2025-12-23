#include "main.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Controler c;
    c.show();
    return a.exec();
}