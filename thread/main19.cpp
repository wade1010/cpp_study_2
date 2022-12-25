#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
using namespace std;
// ָ����ԭ�����Ͳ�������ָ��Ķ���ʱԭ������
int aa = 0;

atomic<int *> ptr(&aa);

void func()
{
    for (int i = 0; i < 1000000; i++)
    {
        (*ptr)++;
        // *ptr = *ptr + 1; // ����ԭ�Ӳ���
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
/* ����������2000000
aa=1207026
 */