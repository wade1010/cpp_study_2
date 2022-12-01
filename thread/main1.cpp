#include <iostream>
#include <thread>
// #include <windows.h>//windows Sleep(num)
#include <unistd.h> //sleep(1000)
using namespace std;

//普通函数
void show(int no, const string &str)
{
    for (int i = 0; i < 10; i++)
    {
        cout << no << "   " << str << endl;
        sleep(1);
    }
}

class AA
{
public:
    static void show(int no, const string &str)
    {
        for (int i = 0; i < 10; i++)
        {
            cout << no << "   " << str << endl;
            sleep(1);
        }
    }
    void show2(int no, const string &str)
    {
        for (int i = 0; i < 10; i++)
        {
            cout << no << "   " << str << endl;
            sleep(1);
        }
    }
    void operator()(int no, const string &str)
    {
        for (int i = 0; i < 10; i++)
        {
            cout << no << "   " << str << endl;
            sleep(1);
        }
    }
};
void test()
{
    // 2 线程 普通函数
    thread t1(show, 1, "hello");
    thread t2(show, 2, "world");

    // 3 lambda函数
    auto func = [](int no, const string &str)
    {
        for (int i = 0; i < 10; i++)
        {
            cout << no << "   " << str << endl;
            sleep(1);
        }
    };
    thread t3(func, 3, "lambda");

    // 4 使用仿函数
    thread t4(AA(), 4, "仿函数");

    // 5 类的静态成员函数
    thread t5(AA::show, 5, "类的静态成员函数");

    // 6 类的普通成员函数 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    AA a;                                            //必须先创建类的对象,必须保证对象的声明周期比子线程要长
    thread t6(AA::show2, &a, 6, "类的普通成员函数"); //第二个参数必须填对象的this指针(可以跟成员函数默认会传this参数一样理解)

    // 1 单线程任务
    cout << "任务开始" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "任务执行中....." << endl;
        // Sleep(1000);//单位为毫秒
        sleep(1); //单位为秒
    }
    cout << "任务完成" << endl;
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
}

int main()
{
    test();
    return 0;
}