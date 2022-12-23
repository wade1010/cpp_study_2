#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std;

once_flag onceflag; // once_flagȫ�ֱ���,������ȡֵΪ0��1����
//���߳���,����ֻ����һ�εĺ���
void call_once_func(int no, const string &str)
{
    cout << "call_once_func:" << no << " " << str << endl;
}
void func(int no, const string &str)
{
    call_once(onceflag, call_once_func, no, str);

    for (int i = 0; i < 10; i++)
    {
        cout << no << str << endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
}
int main()
{
    thread t1(func, 1, "hello");
    thread t2(func, 2, "world");
    t1.join();
    t2.join();
    return 0;
}
/* 2world
1hello
1hello
2world
1hello
2world
2world
1hello
2world
1hello
1hello
2world
1hello
2world
1hello
2world
1hello
2world
1hello
2world */