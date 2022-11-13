#include "iostream"
using namespace std;

void wrongFunc(int arr[])
{
    cout << "sizeof(arr)=" << sizeof(arr) << endl;
    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void func(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void test()
{
    int a[5] = {1, 2, 3, 4, 5};
    cout << "sizeof(a)=" << sizeof(a) << endl;
    func(a, 5);
    wrongFunc(a);
}
int main()
{
    test();
    return 0;
}