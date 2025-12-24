#include "utils.h"

using namespace std;

// aes所用数据
typedef bitset<8> mybyte;
typedef bitset<32> word;

const int Nr = 10; // AES-128需要10轮加密
const int Nk = 4;  // Nk 表示输入密钥的 word 个数

extern const mybyte S_Box[16][16];

extern const mybyte Inv_S_Box[16][16];

// 轮常数，密钥扩展中用到。（AES-128只需要10轮）
extern const word Rcon[10];
class AES
{
public:
    AES(/* args */);
    ~AES();
    void charToByte(mybyte out[16], const char s[16]);           // char字符转换为二进制存入mybyte
    void divideToByte(mybyte out[16], bitset<128> &data);        // 连续128存入一个数组
    bitset<128> mergeByte(mybyte in[16]);                        // 16个mybyte合成128位
    void SubBytes(mybyte mtx[4 * 4]);                            // S盒变换函数
    void ShiftRows(mybyte mtx[4 * 4]);                           // 行变换函数
    mybyte GFMul(mybyte a, mybyte b);                                // 有限域上的乘法
    void MixColumns(mybyte mtx[4 * 4]);                          // 列变换
    void AddRoundKey(mybyte mtx[4 * 4], word k[4]);              // 轮密钥加变换
    void InvSubBytes(mybyte mtx[4 * 4]);                         // 逆黑盒变换
    void InvShiftRows(mybyte mtx[4 * 4]);                        // 逆行变换
    void InvMixColumns(mybyte mtx[4 * 4]);                       // 逆列变换
    word Word(mybyte &k1, mybyte &k2, mybyte &k3, mybyte &k4);         // 4个mybyte转换为一个Word
    word RotWord(word &rw);                                    // 按字节循环
    word SubWord(word &sw);                                    // 对Word中的每个字节进行S盒变换
    void KeyExpansion(mybyte key[4 * Nk], word w[4 * (Nr + 1)]); // 密钥扩展函数
    void encrypt(mybyte in[4 * 4], word w[4 * (Nr + 1)]);        // 加密
    void decrypt(mybyte in[4 * 4], word w[4 * (Nr + 1)]);        // 解密
};