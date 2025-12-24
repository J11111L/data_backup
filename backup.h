#ifndef BACKUP_H
#define BACKUP_H

#include "utils.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class backup;
}
QT_END_NAMESPACE

class backup : public QWidget
{
    Q_OBJECT

public:
    Ui::backup *backupui;

    explicit backup(QWidget *parent = nullptr);

    ~backup();
    
    void updateSourcePath(const QString& newPath);
    
    void updateTargetPath(const QString& newPath);
    
};

#endif // BACKUP_H
