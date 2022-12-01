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
    thread t1(func, 1, "hello");
    thread t2(func, 2, "world");
    cout << "start" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "doing" << endl;
        sleep(1);
    }
    cout << "end" << endl;
    return 0;  //主线程提前退出,程序运行会报错
    t1.join(); //回收线程t1的资源
    t2.join(); //回收线程t2的资源
}
/* start
doing
1 hello
2 world
doing
2 world
1 hello
2 1 hello
world
doing
1 hello
doing
2 world
2 doingworld

1 hello
1 endhello

2 world
terminate called without an active exception

[Done] exited with code=3 in 5.541 seconds */