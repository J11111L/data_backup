#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "utils.h"

QT_BEGIN_NAMESPACE
namespace Ui
{ 
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Ui::MainWindow *ui;
    bool findSource;
    bool findTarget;
    QString m_selectedPath;

    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();
    
    void updateRootPath(const QString& newPath);

private slots:
    void on_treeView_selectionChanged();

private:
    QFileSystemModel* m_fsmodel;
};

#endif // MAINWINDOW_H
