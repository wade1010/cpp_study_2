#include <iostream>
#include <thread>
#include <functional>
using namespace std;
void show1()
{
    cout << "普通函数" << endl;
}
void show2(const string &msg)
{
    cout << "带参数的普通函数" << msg << endl;
}
struct CC
{
    void show3(int a, const string &b)
    {
        cout << "类的普通成员函数," << a << " " << b << endl;
    }
};

/* //返回值 void
template <typename Fn, typename... Args>

void show(Fn fn, Args... args)
{
    cout << "start show" << endl;
    auto pf = bind(fn, args...); //利用bind的提前绑定
    pf();
    cout << "end show" << endl;
} */
/*
//返回函数对象
template <typename Fn, typename... Args>
auto show(Fn fn, Args... args) -> decltype(bind(fn, args...))
{
    auto pf = bind(fn, args...); //利用bind的提前绑定
    return pf;
} */

//最终版
//上面的两个示例,只支持拷贝语义,不支持移动语义,如果实参是右值,传着传着就丢了右值属性
template <typename Fn, typename... Args>
auto show(Fn &&fn, Args &&...args) -> decltype(bind(forward<Fn>(fn), forward<Args>(args)...))
{
    cout << "start show" << endl;
    auto pf = bind(forward<Fn>(fn), forward<Args>(args)...); //利用bind的提前绑定,且实用完美转发,保证属性不变
    pf();
    cout << "end show" << endl;
    return pf;
}

int main()
{
    // thread t1(show1);
    // thread t2(show2, "hello");
    // thread t3(&CC::show3, CC(), 1, "HELLO");

    // t1.join();
    // t2.join();
    // t3.join();

    show(show1);
    show(show2, "hello");
    show(&CC::show3, CC(), 1, "hello");
    cout << "----有返回值----" << endl;

    auto pf = show(show2, "hello");
    pf();

    return 0;
}
/*
start show
普通函数
end show
start show
带参数的普通函数hello
end show
start show
类的普通成员函数,1 hello
end show
----有返回值----
start show
带参数的普通函数hello
end show
带参数的普通函数hello */