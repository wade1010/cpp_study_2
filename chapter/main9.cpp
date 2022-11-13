#include "iostream"
using namespace std;

void test()
{
    int *p = new (std::nothrow) int[10000022222220001];
    if (p == nullptr)
    {
        cout << "申请失败" << endl;
    }
    else
    {
        p[10000022222220000] = 10;
        cout << p[10000022222220000] << endl;
    }

    cout << "111" << endl;
}
int main()
{
    test();
    return 0;
}