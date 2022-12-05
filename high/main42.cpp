#include <iostream>
using namespace std;
//可转换为函数指针的类对象

//定义普通函数
void show(int a, const string &b)
{
    cout << a << " " << b << endl;
}
struct AA //可以被转换的函数指针类
{
    using fun = void (*)(int, const string &);
    operator fun()
    {
        // return show2; //报错 :返回值类型与函数类型不匹配
        return show; //返回普通函数
    }
    void show2(int a, const string &b)
    {
        cout << a << " " << b << endl;
    }
};

void test()
{
    AA a;
    a(1, "a1");
}
int main()
{
    test();
    return 0;
}