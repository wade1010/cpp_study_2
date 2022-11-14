#include "iostream"

//#pragma pack(1)//打开这行注释 结构体大小就是35个字节了
using namespace std;
struct people {
    char name[21];//21
    int age;//4
    double weight;//8
    char sex;//1
    bool isVIP;//1
};

void test() {
    struct people p = {0};
    cout << "结构体大小:" << sizeof(p) << endl;//默认的，不是全部成员占用的35个字节而是48个字节
//    struct people {
//        char name[21];//默认占3个8字节 24
//        int age;//默认占1个8字节  8
//        double weight;//默认占用1个8字节  8
//        char sex;//默认占用1个8字节 8
//        bool isVIP;//默认占用1个8字节,但是前面的sex没占满8字节，且字节和sex的和也不足8字节，所以和sex共同占用8字节即可
//    };

//但是如果结构体顺序如下
//    struct people {
//        char sex;
//        char name[21];
//        bool isVIP;
//        int age;
//        double weight;
//    };
    //默认情况下就是占用40个字节 sex name isVIP占用3个8字节也就是24字节
}

int main() {
    test();
    return 0;
}