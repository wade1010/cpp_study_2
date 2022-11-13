#include "iostream"
using namespace std;

void test()
{
    char name1[11];             //可以存放1个字符，没有初始化，里面是垃圾值,但不影响使用
    char name2[11] = "hello";   //初始化内容为 hello
    char name3[] = {"hello"};   //初始化内容为 hello,系统会自动添加\0,数组长度是6.
    char name4[11] = {"hello"}; //初始化内容为 hello
    char name5[11]{"hello"};    //初始化内容为 hello
    char name6[11] = {0};       //把全部的元素初始化为\0    这种方法用的最多
    for (int i = 0; i < 11; i++)
    {
        cout << (int)name1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 11; i++)
    {
        cout << (int)name2[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 11; i++)
    {
        cout << (int)name3[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 11; i++)
    {
        cout << (int)name4[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 11; i++)
    {
        cout << (int)name5[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 11; i++)
    {
        cout << (int)name6[i] << " ";
    }
    cout << endl;
}
int main()
{
    test();
    return 0;
}