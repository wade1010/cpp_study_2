#include <iostream>
#include <atomic>
using namespace std;

void test()
{
    atomic<int> a(3);
    cout << "a=" << a.load() << endl; //读取原子变量a的值
    a.store(11);
    cout << "a=" << a.load() << endl; //读取原子变量a的值

    int old;              //用于存放原值
    old = a.fetch_add(5); //把原子变量a的值与5相加,返回原值
    cout << "old=" << old << ",a=" << a.load() << endl;

    old = a.fetch_sub(6);
    cout << "old=" << old << ",a=" << a.load() << endl;
}
int main()
{
    test();
    return 0;
}
/* a=3
a=11
old=11,a=16
old=16,a=10 */