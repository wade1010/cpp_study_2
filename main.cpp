#include <iostream>
#include <thread>
using namespace std;

class A
{
public:
    A() { cout << "+++构造" << endl; }
    A(const A &a) : age(a.age) { cout << "拷贝构造" << endl; }
    ~A() { cout << "---析构" << endl; }
    int age;
};

void threadMain(int a, float b, string str, A aa)
{
    cout << "begin sub thread main " << this_thread::get_id() << endl;
    this_thread::sleep_for(chrono::milliseconds(1));
    cout << a << ' ' << b << ' ' << str << ' ' << aa.age << endl;
}

int main()
{
    cout << "begin main thread id:" << this_thread::get_id() << endl;
    thread th;
    {
        float f1 = 111.2f;
        A a;
        a.age = 1;
        th = thread(threadMain, 11, f1, "test", a);
    }
    th.join();
    return 0;
}
