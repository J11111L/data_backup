#ifndef BACKUP_H
#define BACKUP_H

#include "utils.h"
//#include "advanced.h"
//#include "compressANDdecompress.h"
//#include "encryptANDdecode.h"
//#include "packANDunpack.h"
//#include "primary.h"
//#include "warning.h"
//#include "output.h"

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

private:
    void on_pushButton_clicked();
    
};

#endif // BACKUP_H
