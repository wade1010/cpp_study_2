#include <iostream>
#include <atomic>
using namespace std;

void test()
{
    atomic<int> a(3);
    cout << "a=" << a.load() << endl; //��ȡԭ�ӱ���a��ֵ
    a.store(11);
    cout << "a=" << a.load() << endl; //��ȡԭ�ӱ���a��ֵ

    int old;              //���ڴ��ԭֵ
    old = a.fetch_add(5); //��ԭ�ӱ���a��ֵ��5���,����ԭֵ
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