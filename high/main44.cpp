#include <iostream>
#include <functional>
using namespace std;
// bind

void show(int a, const string &b)
{
    cout << a << " " << b << endl;
}

void test()
{
    function<void(int, const string &)> f1 = show;
    function<void(int, const string &)> f2 = bind(show, placeholders::_1, placeholders::_2);
    f1(1, "A1");
    f2(2, "A2");

    function<void(const string &, int)> f3 = bind(show, placeholders::_2, placeholders::_1);
    f3("A3", 3);
    //上面代码,如果不用bind,要实现这个需求,可以把普通函数show()重载一个版本,把参数的位置调换
    //但是没有bind好用
    //实际开发中,调换位置的情况不多,最常见的是少一个参数

    function<void(const string &)> f4 = bind(show, 1, placeholders::_1);
    f4("A4");

    // 用bind()提前绑定有一个细节要注意，被绑定的参数缺省值是值传递，
    int aa = 11;
    function<void(const string &)> f5 = bind(show, aa, placeholders::_1);
    aa = 200;
    f5("A5"); //输出的是 11 A5 而不是 200 A5

    //传引用
    int aaa = 11;
    function<void(const string &)> f6 = bind(show, std::ref(aaa), placeholders::_1);
    aaa = 200;
    f6("A6"); //输出的是 200 A6 而不是 11 A6

    //如果function对象需要的参数比show更多
    function<void(int, const string &, int)> f7 = bind(show, placeholders::_1, placeholders::_2);
    f7(7, "a7", 1);
}
int main()
{
    test();
    return 0;
}
/*
1 A1
2 A2
3 A3
1 A4
11 A5
200 A6
7 a7 */