#include <iostream>
#include <fstream>
using namespace std;

void test()
{
    // 文件名一般用全路径，书写的方法如下：
    //  1）"D:\data\txt\test.txt"       // 错误。
    //  2）R"(D:\data\txt\test.txt)"   // 原始字面量，C++11标准。
    //  3）"D:\\data\\txt\\test.txt"   // 转义字符。
    //  4）"D:/tata/txt/test.txt"        // 把斜线反着写。
    //  5）"/data/txt/test.txt"          //  Linux系统采用的方法。
    string filename = R"(W:\workspace\cpp\practice\cpp_basics_2\test.txt)";
    ofstream ofs(filename);
    //如果目录不存在,则会打开失败,如果目录存在,但是文件不存在,会自动创建文件
    if (!ofs.is_open())
    {
        cout << "打开失败" << endl;
        return;
    }

    ofs << "1,2,3\n";
    ofs << "4,5,6\n";

    ofs.close();
    cout << "ok" << endl;
}
int main()
{
    test();
    return 0;
}