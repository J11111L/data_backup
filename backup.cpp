#include "backup.h"
#include "ui_backup.h"

using namespace std;
/*struct stat sbuf;
string targetFile;
string password;
char source_path[PATH_MAX];
primaryBackuper user;*/

backup::backup(QWidget *parent) :
    QWidget(parent),
    backupui(new Ui::backup)
{
    backupui->setupUi(this);
    connect(backupui->pushButton, &QPushButton::clicked, this, &backup::on_pushButton_clicked);
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

void backup::on_pushButton_clicked()
{
    /*
    QString text = backupui->textEdit->toPlainText();
    QString text1 = backupui->textEdit_2->toPlainText();
    string sourceDirOrFile = text.toStdString();
    string targetDir = text1.toStdString();
    */
    //hard
    if (backupui->radioButton->isChecked())
    {
        cout << "暂不支持硬链接备份功能，敬请期待！\n";
        // if (access(sourceDirOrFile.c_str(), F_OK))
        //     {
        //         warning *ui = new warning();
        //         this->close();
        //         ui->show();
        //     }
        // lstat(sourceDirOrFile.c_str(), &sbuf);
        // if (!(S_ISFIFO(sbuf.st_mode) || S_ISLNK(sbuf.st_mode) || S_ISREG(sbuf.st_mode)))
        //     {
        //         warning *ui = new warning();
        //         this->close();
        //         ui->show();
        //     }

        // strcpy(source_path, sourceDirOrFile.c_str());
        // targetFile = targetDir + '/' + basename(source_path);

        // ADBackuper adworker;
        // adworker.backupRegFile(sourceDirOrFile, targetFile);
    }
    //soft
    if (backupui->radioButton_2->isChecked())
    {
        cout << "暂不支持软链接备份功能，敬请期待！\n";
        // if (access(sourceDirOrFile.c_str(), F_OK))
        // {
        //     warning *ui = new warning();
        //     this->close();
        //     ui->show();
        // }
        // lstat(sourceDirOrFile.c_str(), &sbuf);
        // if (!S_ISLNK(sbuf.st_mode))
        // {
        //     warning *ui = new warning();
        //     this->close();
        //     ui->show();
        // }

        // strcpy(source_path, sourceDirOrFile.c_str());
        // targetFile = targetDir + '/' + basename(source_path);

        // ADBackuper ADworker;
        // ADworker.backupLINK(sourceDirOrFile, targetFile);
    }
    //pipe
    if (backupui->radioButton_3->isChecked())
    {
        cout << "暂不支持管道文件备份功能，敬请期待！\n";
        // if (access(sourceDirOrFile.c_str(), F_OK))
        // {
        //     warning *ui = new warning();
        //     this->close();
        //     ui->show();
        // }
        // lstat(sourceDirOrFile.c_str(), &sbuf);
        // if (!S_ISFIFO(sbuf.st_mode))
        // {
        //     warning *ui = new warning();
        //     this->close();
        //     ui->show();
        // }

        // strcpy(source_path, sourceDirOrFile.c_str());
        // targetFile = targetDir + '/' + basename(source_path);

        // ADBackuper ADworker;
        // ADworker.backupFIFO(sourceDirOrFile, targetFile);
    }
    //directory
    if (backupui->radioButton_4->isChecked())
    {
        cout << "暂不支持目录备份功能，敬请期待！\n";
        // if (access(sourceDirOrFile.c_str(), F_OK))
        // {
        //     warning *ui = new warning();
        //     this->close();
        //     ui->show();
        // }
        // stat(sourceDirOrFile.c_str(), &sbuf);
        // if (!S_ISDIR(sbuf.st_mode))
        // {
        //     warning *ui = new warning();
        //     this->close();
        //     ui->show();
        // }

        // if (strcmp(sourceDirOrFile.c_str(), targetDir.c_str()) == 0)
        // {
        //     warning *ui = new warning();
        //     this->close();
        //     ui->show();
        // }
        // ADBackuper ADworker;
        // ADworker.ADBackupDir(sourceDirOrFile, targetDir);
    }
    //restore
    if (backupui->radioButton_5->isChecked())
    {
        cout << "暂不支持还原功能，敬请期待！\n";
        // if (access(sourceDirOrFile.c_str(), F_OK))
        // {
        //     warning *ui = new warning();
        //     this->close();
        //     ui->show();
        // }
        // lstat(sourceDirOrFile.c_str(), &sbuf);
        // if (!(S_ISFIFO(sbuf.st_mode) || S_ISLNK(sbuf.st_mode) || S_ISREG(sbuf.st_mode) || S_ISDIR(sbuf.st_mode)))
        // {
        //     warning *ui = new warning();
        //     this->close();
        //     ui->show();
        // }
        // stat(sourceDirOrFile.c_str(), &sbuf);
        // // 若移动目录时出现同名，退出移动
        // if ((strcmp(sourceDirOrFile.c_str(), targetDir.c_str()) == 0) && (S_ISDIR(sbuf.st_mode)))
        // {
        //     warning *ui = new warning();
        //     this->close();
        //     ui->show();
        // }

        // ADBackuper ADworker;
        // ADworker.ADmoveFileOrDir(sourceDirOrFile, targetDir);
    }
    //pack
    if (backupui->radioButton_6->isChecked())
    {
        cout << "暂不支持打包功能，敬请期待！\n";
        // if (access(sourceDirOrFile.c_str(), F_OK) || user.EmptyDir(sourceDirOrFile))
        // {
        //     warning *ui = new warning();
        //     this->close();
        //     ui->show();
        // }
        // else
        // {
        //     pack_worker paworker;
        //     paworker.packDir(sourceDirOrFile, targetDir);
        // }
    }
    //unpack
    if (backupui->radioButton_7->isChecked())
    {
        cout << "暂不支持解包功能，敬请期待！\n";
        // if (access(sourceDirOrFile.c_str(), F_OK))
        // {
        //     warning *ui = new warning();
        //     this->close();
        //     ui->show();
        // }
        // else
        // {
        //     pack_worker paworker;
        //     if (access(targetDir.c_str(), F_OK))
        //     {
        //         paworker.mkDir(targetDir);
        //     }
        //     paworker.unpackBag(sourceDirOrFile, targetDir);
        // }
    }
    //compress
    if (backupui->radioButton_8->isChecked())
    {
        cout << "暂不支持压缩功能，敬请期待！\n";
        // if (access(sourceDirOrFile.c_str(), F_OK))
        // {
        //     warning *ui = new warning();
        //     this->close();
        //     ui->show();
        // }
        // else
        // {
        //     compress_worker cpworker;
        //     cpworker.compress(sourceDirOrFile, targetDir);
        // }
    }
    //decompress
    if (backupui->radioButton_9->isChecked())
    {
        cout << "暂不支持解压功能，敬请期待！\n";
        // if (access(sourceDirOrFile.c_str(), F_OK))
        // {
        //     warning *ui = new warning();
        //     this->close();
        //     ui->show();
        // }
        // else
        // {
        //     if (access(targetDir.c_str(), F_OK))
        //     {
        //         user.mkDir(targetDir);
        //     }
        // }
        // compress_worker cpworker;
    }
    //encrypt
    if (backupui->radioButton_10->isChecked())
    {
        cout << "暂不支持加密功能，敬请期待！\n";
        // if (access(sourceDirOrFile.c_str(), F_OK))
        // {
        //     warning *ui = new warning();
        //     this->close();
        //     ui->show();
        // }
        // else
        // {
        //     string md5, md5md5;
        //     encrypt_worker worker;
        //     password = worker.getPSWD();
        //     md5 = worker.encode(password);
        //     md5md5 = worker.encode(md5);
        //     if (access(targetDir.c_str(), F_OK))
        //     {
        //         user.mkDir(targetDir);
        //     }
        //     worker.encyptFile(md5, md5md5, sourceDirOrFile, targetDir);
        // }
    }
    //decrypt
    if (backupui->radioButton_11->isChecked())
    {
        cout << "暂不支持解密功能，敬请期待！\n";
        // if (access(sourceDirOrFile.c_str(), F_OK))
        // {
        //     warning *ui = new warning();
        //     this->close();
        //     ui->show();
        // }
        // else
        // {
        //     string md5, md5md5;
        //     encrypt_worker worker;
        //     password = worker.getPSWD();
        //     md5 = worker.encode(password);
        //     md5md5 = worker.encode(md5);
        //     if (access(targetDir.c_str(), F_OK))
        //     {
        //         user.mkDir(targetDir);
        //     }
        //     worker.decryptFile(md5, md5md5, sourceDirOrFile, targetDir);
        // }
    }
}