#include "iostream"
#include <cstring>
using namespace std;

void test()
{
    char name[11];

    memset(name, 0, sizeof(name)); //打开注释,name打印,除了hel则3个字符,后面就全部是0了

    // strncpy(name, "hello",8);//会自动补0
    strncpy(name, "hello", 3); //不会自动补0,可以用memset(name,0,sizeof(name))先清空name;
    for (int i = 0; i < 11; i++)
    {
        cout << (int)name[i] << " ";
    }
    cout << endl;
    char name2[11] = "hello";   //初始化内容为 hello
    char name3[] = {"hello"};   //初始化内容为 hello,系统会自动添加\0,数组长度是6.
    char name4[11] = {"hello"}; //初始化内容为 hello
    char name5[11]{"hello"};    //初始化内容为 hello
    char name6[11] = {0};       //把全部的元素初始化为\0    这种方法用的最多
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