#include <iostream>
#include <thread>
// #include <windows.h>//windows Sleep(num)
#include <unistd.h> //sleep(1000)
using namespace std;

//��ͨ����
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
    // 2 �߳� ��ͨ����
    thread t1(show, 1, "hello");
    thread t2(show, 2, "world");

    // 3 lambda����
    auto func = [](int no, const string &str)
    {
        for (int i = 0; i < 10; i++)
        {
            cout << no << "   " << str << endl;
            sleep(1);
        }
    };
    thread t3(func, 3, "lambda");

    // 4 ʹ�÷º���
    thread t4(AA(), 4, "�º���");

    // 5 ��ľ�̬��Ա����
    thread t5(AA::show, 5, "��ľ�̬��Ա����");

    // 6 �����ͨ��Ա���� !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    AA a;                                            //�����ȴ�����Ķ���,���뱣֤������������ڱ����߳�Ҫ��
    thread t6(AA::show2, &a, 6, "�����ͨ��Ա����"); //�ڶ�����������������thisָ��(���Ը���Ա����Ĭ�ϻᴫthis����һ�����)

    // 1 ���߳�����
    cout << "����ʼ" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "����ִ����....." << endl;
        // Sleep(1000);//��λΪ����
        sleep(1); //��λΪ��
    }
    cout << "�������" << endl;
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