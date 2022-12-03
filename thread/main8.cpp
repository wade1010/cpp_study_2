#include <iostream>
#include <thread>
using namespace std;
//线程不安全
int aa = 0;
void func()
{
    for (int i = 0; i < 1000000; i++)
    {
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