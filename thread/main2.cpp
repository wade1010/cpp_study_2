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
    thread t1(func, 1, "hello");
    thread t2(func, 2, "world");
    cout << "start" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "doing" << endl;
        sleep(1);
    }
    cout << "end" << endl;
    return 0;  //���߳���ǰ�˳�,�������лᱨ��
    t1.join(); //�����߳�t1����Դ
    t2.join(); //�����߳�t2����Դ
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