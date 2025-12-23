#ifndef BACKUP_H
#define BACKUP_H

#include "utils.h"
#include "mainwindow.h"
//#include "advanced.h"
//#include "compressANDdecompress.h"
//#include "encryptANDdecode.h"
//#include "packANDunpack.h"
//#include "primary.h"
//#include "warning.h"
//#include "output.h"

namespace Ui {
class backup;
}

class backup : public QWidget
{
    Q_OBJECT

public:
    explicit backup(QWidget *parent = nullptr);
    ~backup();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::backup *backupui;
};

#endif // BACKUP_H
