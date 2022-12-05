#include <iostream>
using namespace std;
//类的非静态成员函数  （这个与众不同，所以需要包装器和绑定器）
//普通函数
void show(int a, const string &b)
{
    cout << a << " " << b << endl;
}

struct AA
{
    void show(int a, const string &b)
    {
        cout << a << " " << b << endl;
    }
};
void test()
{
    AA aa;
    aa.show(1, "a1");

    // 1 传统C风格
    void (*pft1)(int, const string &) = show;  //普通函数指针,普通函数可以省略&,也可以不省略
    void (*pft2)(int, const string &) = &show; //普通函数指针,普通函数可以省略&,也可以不省略

    void (AA::*pf)(int, const string &) = &AA::show; //定义类的成员函数的指针,&AA::show,取地址的符号&不能省略
    (aa.*pf)(2, "a2");                               //用类的成员函数的指针调用成员函数

    // 2 C++11风格

    //类成员函数的指针类型  起别名
    using pFun = void (AA::*)(int, const string &);
    pFun pf1 = &AA::show; //让类成员函数的指针指向类的成员函数的地址
    (aa.*pf1)(11, "aa1"); //用类成员函数的指针调用类的成员函数
}
int main()
{
    test();
    return 0;
}