#include <iostream>
#include <fstream>
using namespace std;

void test()
{
    ifstream ifs("test.txt");
    if (!ifs.is_open())
    {
        cout << "打开失败" << endl;
        return;
    }
    //第一种方式
    // string buffer;
    // while (getline(ifs, buffer))
    // {
    //     cout << buffer << endl;
    // }
    // ifs.close();

    //第二种方式
    //注意一定要保证缓冲区足够大,否则超过缓冲区那一行以及后面的所有行都不会读取出来
    //搞太大浪费空间,所以不建议使用
    // char buffer[16];
    // while (ifs.getline(buffer, 15))
    // {
    //     cout << buffer << endl;
    // }
    // ifs.close();

    //第三种方式
    string buffer;
    while (ifs >> buffer)
    {
        cout << buffer << endl;
    }
    ifs.close();

    //读取文件还有别的方式,但是不怎么推荐
}
int main()
{
    test();
    return 0;
}