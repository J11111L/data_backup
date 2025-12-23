#include "othermenu.h"
#include "ui_othermenu.h"

othermenu::othermenu(QWidget *parent, QString text) :
    QWidget(parent),
    myui(new Ui::othermenu)
{
    myui->setupUi(this);
    QStringList filters;
    filters << "*";

    m_fsmodel = new QFileSystemModel(this);
    m_fsmodel->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files);
    m_fsmodel->setNameFilters(filters);
    m_fsmodel->setNameFilterDisables(false);
    m_fsmodel->sort(0, Qt::AscendingOrder); 
    m_fsmodel->setReadOnly(true);
    m_fsmodel->setRootPath(QDir::homePath());

    myui->treeView_2->setModel(m_fsmodel);
    myui->treeView_2->setColumnHidden(1,true);
    myui->treeView_2->setColumnHidden(2,true);
    myui->treeView_2->setColumnHidden(3,true);
    myui->treeView_2->setRootIndex(m_fsmodel->index(text));
    connect(myui->closebutton, SIGNAL(clicked()), this, SLOT(close()));

}

othermenu::~othermenu()
{
    delete myui;
}

void othermenu::on_pushButton_4_clicked()
{
    input *inputui = new input();
    this->close();
    inputui->show();
}

void othermenu::on_pushButton_5_clicked()
{
    this->close();
    std::cout << "backup" << std::endl;
    /*backup *backupui = new  backup();
    backupui->show();*/
}
void othermenu::on_pushButton_6_clicked()
{

}
