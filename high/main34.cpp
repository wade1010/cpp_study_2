#include <iostream>
using namespace std;
//可变参数模板

template <typename T>
void show(T str)
{
    cout << "show=" << str << endl;
}

//递归终止时调用的非模板函数,函数名要与展开参数包的递归函数模板相同.
void print()
{
    cout << "递归终止" << endl;
}
//展开参数包的递归函数模板
template <typename T, typename... Args>
void print(T arg, Args... args)
{
    cout << "参数:" << arg << endl;
    show(arg);

    cout << "还有" << sizeof...(args) << "个参数未展开." << endl;

    print(args...);
}

template <typename... Args>
void func(const string &str, Args... args)
{
    cout << "口号:" << str << endl;
    print(args...);
    cout << "ok" << endl;
}

void test()
{
    print(1, "hello", 3.3, 'c');
    cout << endl;
    print(2, 3, "world");
    cout << endl;
    func("hello", "a1", "a2", "a2");
}
int main()
{
    test();
    return 0;
}
/* 参数:1
show=1
还有3个参数未展开.
参数:hello
show=hello
还有2个参数未展开.
参数:3.3
show=3.3
还有1个参数未展开.
参数:c
show=c
还有0个参数未展开.
递归终止

参数:2
show=2
还有2个参数未展开.
参数:3
show=3
还有1个参数未展开.
参数:world
show=world
还有0个参数未展开.
递归终止

口号:hello
参数:a1
show=a1
还有2个参数未展开.
参数:a2
show=a2
还有1个参数未展开.
参数:a2
show=a2
还有0个参数未展开.
递归终止
ok */