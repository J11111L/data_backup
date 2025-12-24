#ifndef MAINWINDOW_CPP
#define MAINWINDOW_CPP

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    findSource = false;
    findTarget = false;
    ui->setupUi(this);
    QStringList filters;
    filters << "*";

    m_fsmodel = new QFileSystemModel(this);
    m_fsmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files | QDir::System);
    m_fsmodel->setNameFilters(filters);
    m_fsmodel->setNameFilterDisables(false);
    m_fsmodel->sort(0, Qt::AscendingOrder);
    m_fsmodel->setReadOnly(true);
    m_fsmodel->setRootPath(QDir::homePath());

    ui->treeView->setModel(m_fsmodel);
    ui->treeView->setColumnHidden(1,true);
    ui->treeView->setColumnHidden(2,true);
    ui->treeView->setColumnHidden(3,true);
    ui->treeView->setRootIndex(m_fsmodel->index(QDir::homePath()));
    ui->treeView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->treeView->setSelectionBehavior(QAbstractItemView::SelectRows);

    connect(ui->treeView->selectionModel(), SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)),
            this, SLOT(on_treeView_selectionChanged()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateRootPath(const QString& newPath)
{
    if (!newPath.isEmpty() && QDir(newPath).exists())
    {
        m_fsmodel->setRootPath(newPath);
        ui->treeView->setRootIndex(m_fsmodel->index(newPath));
    }
}

void MainWindow::on_treeView_selectionChanged()
{
    QModelIndexList selectedIndexes = ui->treeView->selectionModel()->selectedIndexes();
    
    if (!selectedIndexes.isEmpty())
    {
        QModelIndex selectedIndex = selectedIndexes.first();
        
        m_selectedPath = m_fsmodel->filePath(selectedIndex);
    } else {
        m_selectedPath = "";
    }
}

#endif // MAINWINDOW_CPP