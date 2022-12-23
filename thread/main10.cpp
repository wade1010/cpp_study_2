#include <iostream>
#include <mutex>
using namespace std;
class AA
{
    // mutex m_mtx;//��demoֱ����mutex�ᷢ������
    recursive_mutex m_mtx;

public:
    void func1()
    {
        m_mtx.lock();
        cout << "func1" << endl;
        m_mtx.unlock();
    }
    void func2()
    {
        m_mtx.lock();
        cout << "func2" << endl;
        func1();
        m_mtx.unlock();
    }
};
void test()
{
    AA a;
    // a.func1();
    //����,��ͨ�Ļ����������ڽ�������ܼ���,������ͬһ���߳�Ҳ��������.��ʱ������� recursive_mutex
    a.func2();
}
int main()
{
    test();
    return 0;
}