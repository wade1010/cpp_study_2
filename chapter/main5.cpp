#include "iostream"
using namespace std;

void test()
{
    int a[5] = {1, 2, 3, 4, 5};
    //用数组表示法操作数组
    for (int i = 0; i < 5; i++)
    {
        cout << "a[" << i << "]value is:" << a[i] << endl;
    }
    cout << endl;

    for (int i = 0; i < 100; i++)
    {
        a[i] = 100 + i;
        cout << "a[" << i << "]value is:" << a[i] << endl;
    }
    cout << endl;

    //用指针法操作数组
    cout << "-------------------------------------" << endl;

    int b[5] = {1, 2, 3, 4, 5};
    int *p = b;
    for (int i = 0; i < 5; i++)
    {
        cout << "*(p+" << i << ")value is:" << *(p + i) << endl;
    }
    cout << endl;

    for (int i = 0; i < 100; i++)
    {
        *(p + i) = 100 + i;
        cout << "*(p+" << i << ")value is:" << *(p + i) << endl;
    }
    cout << endl;
}
int main()
{
    test();
    return 0;
}