#include "iostream"
using namespace std;

// 1 如果函数的返回值<0 那么a所指向的元素会排在8所指向元素的前面
// 2 如果函数的返回值==0 那么a所指向的元素与8所指向元素的顺序不确定
// 3 如果函数的返回值>0 那么a所指向的元素会排在8所指向元素的后面
int myCompareAsc(const void *a, const void *b)
{
    // int aa = *((int *)a);
    // int bb = *((int *)b);
    // if (aa < bb)
    // {
    //     return -1;
    // }
    // else if (aa == bb)
    // {
    //     return 0;
    // }
    // return 1;
    return *((int *)a) - *((int *)b);
}
int myCompareDesc(const void *a, const void *b)
{
    return *((int *)b) - *((int *)a);
}
void test()
{
    int a[8] = {2, 12, 4, 542, 1, 5, 65, 3};
    //函数的原型
    // qsort(void *_Base,size_t _NumOfElements,size_t _SizeOfElements,int (__cdecl *_PtFuncCompare)(const void *,const void *));
    qsort(a, sizeof(a) / sizeof(a[0]), sizeof(a[0]), myCompareAsc);
    for (int i = 0; i < 8; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    qsort(a, sizeof(a) / sizeof(a[0]), sizeof(a[0]), myCompareDesc);
    for (int i = 0; i < 8; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
    test();
    return 0;
}