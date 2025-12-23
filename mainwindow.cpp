#ifndef MAINWINDOW_CPP
#define MAINWINDOW_CPP

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    //界面初始化
    ui->setupUi(this);
    QStringList filters;
    filters << "*";//<< "*.cpp" << "*.h" << "*.txt" << "*.md";

    m_fsmodel = new QFileSystemModel(this);
    m_fsmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files);
    m_fsmodel->setNameFilters(filters);
    m_fsmodel->setNameFilterDisables(false);
    m_fsmodel->sort(0, Qt::AscendingOrder);
    m_fsmodel->setReadOnly(true);
    m_fsmodel->setRootPath(QDir::homePath());

    ui->treeView->setModel(m_fsmodel);
    //只显示名称列，隐藏大小类型修改日期
    ui->treeView->setColumnHidden(1,true);
    ui->treeView->setColumnHidden(2,true);
    ui->treeView->setColumnHidden(3,true);
    ui->treeView->setRootIndex(m_fsmodel->index(QDir::homePath()));
    connect(ui->closebutton, SIGNAL(clicked()), this, SLOT(close()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->close();
    input *inputui = new input();
    inputui->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
    backup *backupui = new  backup();
    backupui->show();
}

#endif // MAINWINDOW_CPP