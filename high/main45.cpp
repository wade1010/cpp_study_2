#include <iostream>
#include <functional>
using namespace std;
//普通函数
void show(int a, const string &b)
{
    cout << a << b << endl;
}

//类中有静态成员函数
struct AA
{
    static void show(int a, const string &b)
    {
        cout << a << b << endl;
    }
};

//仿函数
struct BB
{
    void operator()(int a, const string &b)
    {
        cout << a << b << endl;
    }
};
//类中有普通函数
struct CC
{
    void show(int a, const string &b)
    {
        cout << a << b << endl;
    }
};

//可以被转换为普通函数指针的类
struct DD
{
    using Fun = void (*)(int, const string &);
    operator Fun()
    {
        return show; //返回普通函数show的地址
    }
};

void test()
{
    // 1 不使用包装器function
    function<void(int, const string &)> pf1 = bind(show, placeholders::_1, placeholders::_2);
    pf1(1, "a1");

    //类的静态成员函数
    function<void(int, const string &)> pf2 = bind(AA::show, placeholders::_1, placeholders::_2);
    pf2(2, "a2");

    //仿函数
    BB bb;
    function<void(int, const string &)> pf3 = bind(bb, placeholders::_1, placeholders::_2);
    pf3(3, "a3");

    //创建lambda对象
    auto lambfunc = [](int a, const string &b)
    {
        cout << a << b << endl;
    };
    function<void(int, const string &)> pf4 = bind(lambfunc, placeholders::_1, placeholders::_2);
    pf4(4, "a4");

    //类的非静态成员函数    这里是最大的优化
    CC cc;
    /* function<void(CC &, int, const string &)> pf5 = bind(&CC::show, placeholders::_1, placeholders::_2, placeholders::_3);
    pf5(cc, 5, "a5"); */
    //上面代码是需要传进去对象,但是实际开发中,不希望传的,因为这样不能用于模板.
    //为了解决这个问题,可以把对象cc提前绑定,代码如下

    function<void(int, const string &)> pf5 = bind(&CC::show, cc, placeholders::_1, placeholders::_2);
    // function<void(int, const string &)> pf5 = bind(&CC::show, CC(), placeholders::_1, placeholders::_2);
    pf5(5, "a5");

    //可以被转换的函数指针的类
    DD dd;
    // function<void(int, const string &)> pf6 = bind(dd, placeholders::_1, placeholders::_2);
    function<void(int, const string &)> pf6 = bind(DD(), placeholders::_1, placeholders::_2);
    pf6(6, "a6");
}
int main()
{
    test();
    return 0;
}
/*
1a1
2a2
3a3
4a4
5a5
6a6 */