#include"controler.h"

Controler::Controler(QWidget *parent) :
    QWidget(parent),
    m_input(new input()),
    m_mainWindow(new MainWindow()),
    m_backup(new backup())
{
    connect(m_backup->backupui->browseSourceButton, &QPushButton::clicked, this, &Controler::on_BrowseSource_Clicked);
    connect(m_backup->backupui->browseTargetButton, &QPushButton::clicked, this, &Controler::on_BrowseTarget_Clicked);
    connect(m_backup->backupui->closebutton, &QPushButton::clicked, this, &Controler::kill);

    connect(m_mainWindow->ui->pushButton, &QPushButton::clicked, this, &Controler::on_ChangeRootPath_Clicked);
    connect(m_mainWindow->ui->pushButton_2, &QPushButton::clicked, this, &Controler::on_ChoosePath_Clicked);
    connect(m_mainWindow->ui->pushButton_3, &QPushButton::clicked, this, &Controler::on_MainWindow2backup_Clicked);

    connect(m_input->inputui->pushButton, &QPushButton::clicked, this, &Controler::on_ChooseRootPath_Clicked);
    connect(m_input->inputui->pushButton_2, &QPushButton::clicked, this, &Controler::on_Input2MainWindow_Clicked);
}

Controler::~Controler()
{
    delete m_input;
    delete m_mainWindow;
    delete m_backup;
}

void Controler::show()
{
    m_backup->show();
}

void Controler::kill()
{
    exit(0);
}

void Controler::on_BrowseSource_Clicked()
{
    m_backup->hide();
    m_mainWindow->findSource = true;
    m_mainWindow->show();
}

void Controler::on_BrowseTarget_Clicked()
{
    m_backup->hide();
    m_mainWindow->findTarget = true;
    m_mainWindow->show();
}

void Controler::on_ChangeRootPath_Clicked()
{
    m_mainWindow->hide();
    m_input->show();
}

void Controler::on_ChooseRootPath_Clicked()
{
    QString text = m_input->inputui->textEdit->toPlainText().trimmed();
    if (!text.isEmpty() && QDir(text).exists())
    {
        m_mainWindow->updateRootPath(text);
        m_mainWindow->show();
    } else {
        m_input->inputui->textEdit->setPlaceholderText("路径不存在，请重新输入！");
        m_input->inputui->textEdit->clear();
        return;
    }
    m_input->hide();
}

void Controler::on_Input2MainWindow_Clicked()
{
    m_input->hide();
    m_mainWindow->show();
}

void Controler::on_ChoosePath_Clicked()
{
    if (m_mainWindow->m_selectedPath.isEmpty())
    {
        QMessageBox::warning(this, "提示", "请先在左侧选择一个文件或目录！");
        return;
    }
    QFileInfo fileInfo(m_mainWindow->m_selectedPath);
    if(m_mainWindow->findSource)
    {
        if(!fileInfo.exists())
        {
            QMessageBox::warning(this, "提示", "所选路径不存在，请重新选择！");
            return;
        }
        m_backup->updateSourcePath(m_mainWindow->m_selectedPath);
        m_mainWindow->findSource = false;
    }
    else if(m_mainWindow->findTarget)
    {
        if(!fileInfo.exists())
        {
            QMessageBox::warning(this, "提示", "所选路径不存在，请重新选择！");
            return;
        }
        else if(!fileInfo.isDir())
        {
            QMessageBox::warning(this, "提示", "目标路径必须是一个目录，请重新选择！");
            return;
        }
        m_backup->updateTargetPath(m_mainWindow->m_selectedPath);
        m_mainWindow->findTarget = false;
    }
    m_mainWindow->hide();
    m_backup->show();
}

void Controler::on_MainWindow2backup_Clicked()
{
    m_mainWindow->hide();
    m_backup->show();
}