#include <iostream>
#include <thread>
#include <chrono>
#include <pthread.h>
using namespace std;
void func()
{
    for (int i = 0; i < 10; i++)
    {
        cout << i << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
}
void test()
{
    thread t1(func);
    this_thread::sleep_for(chrono::seconds(5));
    pthread_t theadid = t1.native_handle(); // 获取操作系统原生的线程句柄。
    pthread_cancel(theadid);

    t1.join();
}
int main()
{
    test();
    return 0;
}
//线程第五秒的时候被取消了,所以输出的结果不全
/* 0
1
2
3
4 */