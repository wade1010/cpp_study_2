#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

int aa = 0;

mutex mtx;

void func()
{
    for (int i = 0; i < 1000000; i++)
    {
        cout << "线程:" << this_thread::get_id() << "申请加锁..." << endl;
        mtx.lock();
        cout << "线程:" << this_thread::get_id() << "加锁成功" << endl;
        aa++;
        this_thread::sleep_for(chrono::seconds(5));
        mtx.unlock();
        cout << "线程:" << this_thread::get_id() << "释放了锁" << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
}
void test()
{
    thread t1(func);
    thread t2(func);
    t1.join();
    t2.join();
    cout << "aa=" << aa << endl;
}
int main()
{
    test();
    return 0;
}
/* .....
线程:2释放了锁
线程:3加锁成功
线程:2申请加锁...
线程:3释放了锁
线程:2加锁成功
线程:3申请加锁...
线程:2释放了锁
..... */