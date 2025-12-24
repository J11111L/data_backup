#include "backup.h"
#include "ui_backup.h"

using namespace std;

backup::backup(QWidget *parent) :
    QWidget(parent),
    backupui(new Ui::backup)
{
    backupui->setupUi(this);
}

void backup::updateSourcePath(const QString& newPath)
{
    backupui->textEdit->setText(newPath);
}

void backup::updateTargetPath(const QString& newPath)
{
    backupui->textEdit_2->setText(newPath);
}

backup::~backup()
{
    delete backupui;
}
