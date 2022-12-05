#include <iostream>
using namespace std;

using Fun = void(int, const string &); //别名

struct AA
{
    static void show(int a, const string &b)
    {
        cout << a << " " << b << endl;
    }
};

void test()
{
    AA::show(1, "a1"); //直接调用静态成员函数

    // 1 C风格的

    void (*pf)(int, const string &) = AA::show; //声明函数指针
    pf(2, "a2");
    void (&rf)(int, const string &) = AA::show; //声明函数引用
    rf(3, "a3");

    // 2 C++风格的

    //声明函数指针
    Fun *pf2 = AA::show;
    pf2(4, "a4");

    //声明函数引用
    Fun &rf2 = AA::show;
    rf2(5, "a5");
}
int main()
{
    test();
    return 0;
}
