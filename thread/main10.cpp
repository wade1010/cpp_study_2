#include <iostream>
#include <mutex>
using namespace std;
class AA
{
    // mutex m_mtx;//本demo直接用mutex会发生死锁
    recursive_mutex m_mtx;

public:
    void func1()
    {
        m_mtx.lock();
        cout << "func1" << endl;
        m_mtx.unlock();
    }
    void func2()
    {
        m_mtx.lock();
        cout << "func2" << endl;
        func1();
        m_mtx.unlock();
    }
};
void test()
{
    AA a;
    // a.func1();
    //死锁,普通的互斥锁必须在解锁后才能加锁,就算是同一个线程也不能例外.这时候可以用 recursive_mutex
    a.func2();
}
int main()
{
    test();
    return 0;
}