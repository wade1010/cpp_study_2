#include <iostream>
#include <thread>
using namespace std;

class A
{
public:
    int m_i;
    A(int a) : m_i(a) { cout << "构造函数执行,thread_id:" << this_thread::get_id() << endl; }
    A(const A &a) : m_i(a.m_i) { cout << "拷贝构造函数执行,thread_id:" << this_thread::get_id() << ",&a=" << &a << ",&this:" << this << endl; }
    // A(A &&a) : m_i(a.m_i) { cout << "移动函数执行" << endl; }
    ~A() { cout << "析构函数执行,thread_id:" << this_thread::get_id() << endl; }
};

void myprint(const A &a)
{
    cout << &a << ' ' << this_thread::get_id() << endl;
}

int main()
{
    cout << "主线程id:" << this_thread::get_id() << endl;
    int j = 10;
    thread th(myprint, A(j));
    // thread th(myprint, j);
    th.join();
    cout << "end main" << endl;
    return 0;
}

/*
1:使用 void myprint(const A &a);

主线程id:1
构造函数执行,thread_id:1
拷贝构造函数执行,thread_id:1,&a=0xef1bdff5f8,&this:0x25f927803a8
析构函数执行,thread_id:1
0x25f927803a8 2
析构函数执行,thread_id:2
end main


2:使用 void myprint(const A a);

主线程id:1
构造函数执行,thread_id:1
拷贝构造函数执行,thread_id:1,&a=0x67a15ff5f8,&this:0x1e00aaa4758
析构函数执行,thread_id:1
拷贝构造函数执行,thread_id:2,&a=0x1e00aaa4758,&this:0x67a1dff88c
0x67a1dff88c 2
析构函数执行,thread_id:2
析构函数执行,thread_id:2
end main
 */