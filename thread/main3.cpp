#include <iostream>
#include <thread>
#include <unistd.h>
using namespace std;
//��ͨ����

void func(int no, const string &str)
{
    for (int i = 0; i < 10; i++)
    {
        cout << no << " " << str << endl;
        sleep(1);
    }
}
int main()
{
    /*     thread t1(func, 1, "hello");
        thread t2(func, 2, "world");
        cout << "start" << endl;
        for (int i = 0; i < 15; i++)
        {
            cout << "doing" << endl;
            sleep(1);
        }
        cout << "end" << endl;
        return 0;  //���߳���ǰ�˳�,���߳���Դû�л���,�������лᱨ��
        t1.join(); //�����߳�t1����Դ
        t2.join(); //�����߳�t2����Դ */

    /* thread t1(func, 1, "hello");
    thread t2(func, 2, "world");
    cout << "start" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "doing" << endl;
        sleep(1);
    }
    cout << "end" << endl;
    t1.join(); //�����߳�t1����Դ
    t2.join(); //�����߳�t2����Դ */

    thread t1(func, 1, "hello");
    thread t2(func, 2, "world");
    t1.detach();
    t2.detach();
    sleep(15);
}
