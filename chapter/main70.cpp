#include "iostream"
using namespace std;

int func()
{
    cout << "调用了func函数" << endl;
    return 11;
}
auto func2(int x, double y) -> int
{
    cout << "函数体" << endl;
    return 1;
}
void test()
{
    // short b = 5;
    // short *a = &b;
    // decltype(a) da;

    // short a = 5;
    // short &ra = a;
    // short b = 10;
    // decltype(ra) da = b;

    short b = 10;
    decltype(func()) da = b; //不会调用函数
    //上面填函数调用和函数名是两回事,如果只填函数名,得到的是函数的类型,不是函数返回值的类型. 如下
    decltype(func) *da2 = func;
    da2();

    // decltype(func()) f; //本质区别,不会调用func
    auto f = func(); //本质区别,会调用func,且用auto的时候需要初始值,要不然没东西可以推导
}
// template <typename T1, typename T2>
// void func3(T1 a, T2 b)
// {
//     //其它代码

//     // ? ? ? tmp = a + b; //返回值该用什么呢?

//     //其它代码
// }

template <typename T1, typename T2>
auto func3(T1 a, T2 b) -> decltype(a + b)
{
    decltype(a + b) tmp = a + b;
    return tmp;
}

/* C++14可以如下,去掉尾随值
template <typename T1, typename T2>
auto func3(T1 a, T2 b)
{
    decltype(a + b) tmp = a + b;
    return tmp;
} */

int main()
{
    test();
    auto ret = func3(1, 3.3);
    cout << "ret=" << ret << endl;
    return 0;
}