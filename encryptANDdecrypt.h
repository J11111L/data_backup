#ifndef ENCRYPTANDDECRYPT
#define ENCRYPTANDDECRYPT

#include "advanced.h"
#include "aes.h"
#include "md5.h"

using namespace std;

class encrypt_worker : public ADBackuper, public MD5, public AES
{

public:
    encrypt_worker(/* args */);
    ~encrypt_worker();
    string getPSWD();                                                                           // 密码输入用星号遮掩
    bool encyptFile(string md5ofpwd, string md5md5ofpwd, string sourcefile, string targetdir);  // 对sourcefile进行aes加密，targetdir为加密文件存放目录
    bool decryptFile(string md5ofpwd, string md5md5ofpwd, string sourcefile, string targetdir); // 对sourcefile进行aes解密，targetdir为解密文件存放目录
};

#endif //ENCRYPTANDDECRYPT