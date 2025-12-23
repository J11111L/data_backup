#ifndef CONTROLER_H
#define CONTROLER_H

#include"utils.h"
#include"input.h"
#include"mainwindow.h"
#include"backup.h"
#include"ui_backup.h"
#include"ui_mainwindow.h"
#include"ui_input.h"

class Controler : public QWidget
{
    Q_OBJECT

public:
    explicit Controler(QWidget* parent = nullptr);
    ~Controler();
    void show();
private:
    input* m_input;
    MainWindow* m_mainWindow;
    backup* m_backup;

    void kill();

    void on_BrowseSource_Clicked();

    void on_BrowseTarget_Clicked();

    void on_ChangeRootPath_Clicked();

    void on_ChooseRootPath_Clicked();

    void on_Input2MainWindow_Clicked();

    void on_ChoosePath_Clicked();

    void on_MainWindow2backup_Clicked();

};
#endif // CONTROLER_H