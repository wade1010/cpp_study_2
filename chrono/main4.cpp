#include <iostream>
#include <chrono>
using namespace std;

void test()
{
    //��̬��Ա����chrono::steady_clock::now()��ȡ��ʼ��ʱ���
    // chrono::steady_clock::time_point start = chrono::steady_clock::now();
    auto start = chrono::steady_clock::now();

    // ִ��һЩ����,����һЩʱ��
    cout << "��ʼ��ʱ" << endl;
    for (size_t i = 0; i < 1000000; i++)
    {
    }
    cout << "��ʱ���" << endl;

    auto diff = (chrono::steady_clock::now() - start).count();
    //��λ������ ���л���
    cout << "��ʱ:" << diff << "����(" << diff / 1000000 << "����)" << endl;
}
int main()
{
    test();
    return 0;
}
/* ��ʼ��ʱ
��ʱ���
��ʱ:3419700����(3����) */