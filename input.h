#ifndef INPUT_H
#define INPUT_H

#include "utils.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class input;
}
QT_END_NAMESPACE

class input : public QWidget
{
    Q_OBJECT

public:
    Ui::input* inputui;

    explicit input(QWidget* parent = nullptr);
    
    ~input();
};

#endif // INPUT_H
