#include "iostream"
using namespace std;
//在arr中查找key,成功返回key在arr中的数组下标,失败返回-1
int search(int arr[], int len, int key)
{
    int low = 0, high = len - 1, mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        cout << arr[low] << " " << arr[mid] << " " << arr[high] << endl;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
int myCompareAsc(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}
void test()
{
    int a[10] = {321, 43, 54, 65, 723, 212, 32, 54, 65, 765};
    //必须得排好序
    qsort(a, 10, sizeof(int), myCompareAsc);

    if (search(a, 10, 32) >= 0)
    {
        cout << "在数组中查找32成功" << endl;
    }
    else
    {
        cout << "查找失败" << endl;
    }
}
int main()
{
    test();
    return 0;
}