#include "iostream"
#include <cstring>
using namespace std;

void test()
{
    int arr[3] = {1, 2, 3};
    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    //清空数组
    memset(arr, 0, sizeof(arr));

    for (int i = 0; i < 3; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    //复制数组
    int arr2[3] = {22, 33, 44};
    int copyArr[sizeof(arr2) / sizeof(arr2[0])];
    memcpy(copyArr, arr2, sizeof(arr));
    for (int i = 0; i < 3; i++)
    {
        cout << copyArr[i] << " ";
    }
    cout << endl;
}
int main()
{
    test();
    return 0;
}