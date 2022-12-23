#include <iostream>
#include <thread>
using namespace std;

class A
{
public:
    int m_i;
    A(int a) : m_i(a) { cout << "构造函数执行,thread_id:" << this_thread::get_id() << endl; }
    A(const A &a) : m_i(a.m_i) { cout << "拷贝构造函数执行,thread_id:" << this_thread::get_id() << endl; }
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
    // thread th(myprint, A(j));
    thread th(myprint, j);
    th.join();
    // th.detach();
    cout << "end main" << endl;
    return 0;
}
/*
两种情况
1:使用 thread th(myprint, A(j));

主线程id:1
构造函数执行,thread_id:1
拷贝构造函数执行,thread_id:1
析构函数执行,thread_id:1
0x1b601f026a8 2
析构函数执行,thread_id:2
end main

2:使用 thread th(myprint, j);

主线程id:1
构造函数执行,thread_id:2
0x68b65ffb2c 2
析构函数执行,thread_id:2
end main
 */