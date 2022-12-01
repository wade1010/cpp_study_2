#include <iostream>
#include <thread>
#include <unistd.h>
using namespace std;
//普通函数

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
        return 0;  //主线程提前退出,子线程资源没有回收,程序运行会报错
        t1.join(); //回收线程t1的资源
        t2.join(); //回收线程t2的资源 */

    /* thread t1(func, 1, "hello");
    thread t2(func, 2, "world");
    cout << "start" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "doing" << endl;
        sleep(1);
    }
    cout << "end" << endl;
    t1.join(); //回收线程t1的资源
    t2.join(); //回收线程t2的资源 */

    thread t1(func, 1, "hello");
    thread t2(func, 2, "world");
    t1.detach();
    t2.detach();
    sleep(15);
}
