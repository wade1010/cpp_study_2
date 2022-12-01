#include <iostream>
#include <vector>
using namespace std;

void test() noexcept
{
    if (!noexcept(throw "aaaa"))
    {
        cout << "�׳��쳣" << endl;
    }

    //����һ����ڴ�
    double *ptr = nullptr;
    try
    {
        ptr = new double[1110001111111100];
    }
    catch (bad_alloc &e)
    {
        cout << "�����ڴ�ʧ��," << e.what() << endl;
    }
    if (ptr != nullptr)
    {
        delete ptr;
    }

    double *ptr2 = new (nothrow) double[1110001111111100];
    if (ptr2 == nullptr)
    {
        cout << "�ڴ����ʧ��" << endl;
    }
    else
    {
        delete ptr2;
    }

    try
    {
        vector<int> v{1, 2, 3};
        // v.at(3) = 20;
        v[3] = 20;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
int main()
{
    test();
    return 0;
}
// �׳��쳣