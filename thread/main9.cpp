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
        cout << "�߳�:" << this_thread::get_id() << "�������..." << endl;
        mtx.lock();
        cout << "�߳�:" << this_thread::get_id() << "�����ɹ�" << endl;
        aa++;
        this_thread::sleep_for(chrono::seconds(5));
        mtx.unlock();
        cout << "�߳�:" << this_thread::get_id() << "�ͷ�����" << endl;
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
�߳�:2�ͷ�����
�߳�:3�����ɹ�
�߳�:2�������...
�߳�:3�ͷ�����
�߳�:2�����ɹ�
�߳�:3�������...
�߳�:2�ͷ�����
..... */