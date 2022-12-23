#include <iostream>
#include <thread>
#include <chrono>
#include <unistd.h>
using namespace std;
//普通函数

void func(int no, const string &str)
{
    for (int i = 0; i < 10; i++)
    {

        cout << "id=" << this_thread::get_id() << "," << no << " " << str << endl;
        // sleep(1);
        this_thread::sleep_for(chrono::seconds(1));
        //休眠到当前时间往后1秒
        // std::this_thread::sleep_until(std::chrono::steady_clock::now() + std::chrono::seconds(1));
    }
}
int main()
{
    thread t1(func, 1111, "hello");
    thread t2(func, 2222, "world");
    cout << "主线程:" << this_thread::get_id() << endl;
    cout << "子线程t1:" << t1.get_id() << endl;
    cout << "子线程t2:" << t2.get_id() << endl;
    t1.swap(t2);
    cout << "交换后" << endl;
    cout << "子线程t1:" << t1.get_id() << endl;
    cout << "子线程t2:" << t2.get_id() << endl;

    // thread t3 = t2;//错误
    thread t3 = move(t2);

    t1.join(); //回收线程t1的资源
               // t2.join(); //move后,不再代表线程,join会报错
    t3.join(); //回收线程t3的资源
}
