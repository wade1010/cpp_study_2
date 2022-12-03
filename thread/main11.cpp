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
        lock_guard<mutex> lockguard(mtx);
        aa++;
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
