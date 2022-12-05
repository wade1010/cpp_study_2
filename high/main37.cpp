#include <iostream>
using namespace std;

using Fun = void(int, const string &); //普通函数类型的别名

Fun show; //声明普通函数,这一行效果等同于下面这一行
// void show(int, const string &);//声明普通函数

void test()
{
    show(1, "a1"); //直接调用普通函数

    // 1 C风格的

    void (*pf)(int, const string &) = show; //声明函数指针,指向普通函数
    pf(2, "a2");
    void (&rf)(int, const string &) = show; //声明函数引用,引用普通函数
    rf(3, "a3");

    // 2 C++风格的

    //声明函数指针,指向普通函数
    Fun *pf2 = show;
    pf2(4, "a4");

    //声明函数引用,引用普通函数
    Fun &rf2 = show;
    rf2(5, "a5");
}
int main()
{
    test();
    return 0;
}
//定义普通函数
void show(int a, const string &b)
{
    cout << a << " " << b << endl;
}

//以下代码是错误的,不能用函数类型定义函数的实体.
// Fun show(int a, const string &b)
// {
//     cout << a << " " << b << endl;
// }
/* 1 a1
2 a2
3 a3
4 a4
5 a5 */