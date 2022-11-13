#include "iostream"
using namespace std;

void test()
{
    int a[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "数组a第0个元素的地址:" << a << endl;
    cout << "数组a的地址:" << &a << endl;

    cout << "数组a的第0个元素的地址+1:" << a + 1 << endl;
    cout << "数组a的地址+1:" << &a + 1 << endl;

    int *p1 = a;
    int(*p2)[10] = &a;

    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int(*p3)[3] = arr;
}
int main()
{
    test();
    return 0;
}