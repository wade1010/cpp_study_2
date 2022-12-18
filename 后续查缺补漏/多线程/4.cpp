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

void myprint(A &a)
{
    a.m_i = 1111;
    cout << &a << ' ' << this_thread::get_id() << endl;
}

void myprint2(unique_ptr<int> uptr)
{
    cout << this_thread::get_id() << endl;
}

int main()
{
    cout << "主线程id:" << this_thread::get_id() << endl;
    // A a(10);
    // thread th(myprint, ref(a));

    thread th(myprint2, unique_ptr<int>(new int(100)));
    // unique_ptr<int> muptr(new int(100));
    // thread th(myprint2, move(muptr));//unique_ptr已经删除了拷贝构造,所以这里得用move

    th.join();
    // th.detach();
    cout << "end main" << endl;
    return 0;
}
