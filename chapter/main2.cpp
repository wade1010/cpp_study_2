#include "iostream"
using namespace std;
void func(int no, string str)
{
    cout << "hello" << no << str << endl;
}
void test()
{
    int a;
    char b;
    cout << "a=" << (void *)&a << endl;
    cout << "b=" << (void *)&b << endl;

    //函数指针
    //普通调用
    int no = 3;
    string msg = "你好";
    func(no, msg);
    //函数指针调用
    void (*f)(int, string); //声明函数的函数指针
    f = func;               //对函数指针赋值,语法是   函数指针名 = 函数名
    f(no, msg);             //用函数指针名调用函数  C++
    (*f)(no, msg);          //用函数指针名调用函数  C
}
void zs()
{
    cout << "zs" << endl;
}
void ls()
{
    cout << "ls" << endl;
}
void show(void (*pf)())
{
    cout << "hello" << endl;
    pf();
    cout << "world" << endl;
}
void test2()
{
    show(zs);
}

int sum(int a, int b)
{
    return a + b;
}

void show2(int (*pf)(int, int), int a, int b)
{
    cout << "show2 start" << endl;
    int sum = pf(a, b);
    cout << "sum=" << sum << endl;
    cout << "show2 end" << endl;
}

void test3()
{
    show2(sum, 2, 3);
}
int main()
{
    test();
    test2();
    test3();
    return 0;
}