#include <iostream>
#include <thread>
#include <chrono>
#include <unistd.h>
using namespace std;
//��ͨ����

void func(int no, const string &str)
{
    cout << "���߳�:" << this_thread::get_id() << endl;
    for (int i = 0; i < 10; i++)
    {

        cout << no << " " << str << endl;
        // sleep(1);
        // this_thread::sleep_for(chrono::seconds(1));
        //���ߵ���ǰʱ������1��
        std::this_thread::sleep_until(std::chrono::steady_clock::now() + std::chrono::seconds(1));
    }
}
int main()
{
    thread t1(func, 1111, "hello");
    thread t2(func, 2222, "world");
    cout << "���߳�:" << this_thread::get_id() << endl;
    t1.join(); //�����߳�t1����Դ
    t2.join(); //�����߳�t2����Դ
}
