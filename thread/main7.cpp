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
    pthread_t theadid = t1.native_handle(); // ��ȡ����ϵͳԭ�����߳̾����
    pthread_cancel(theadid);

    t1.join();
}
int main()
{
    test();
    return 0;
}
//�̵߳������ʱ��ȡ����,��������Ľ����ȫ
/* 0
1
2
3
4 */