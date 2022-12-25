#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
using namespace std;
// 指针是原子类型不代表它指向的对象时原子类型
int aa = 0;

atomic<int *> ptr(&aa);

void func()
{
    for (int i = 0; i < 1000000; i++)
    {
        (*ptr)++;
        // *ptr = *ptr + 1; // 不是原子操作
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
/* 输出结果不是2000000
aa=1207026
 */