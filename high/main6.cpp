#include <iostream>
#include <vector>
using namespace std;

void test()
{
    vector<int> v = {1, 2, 3, 4, 5};
    auto it1 = v.begin();
    *it1 = 10;
    it1++;
    *it1 = 20;
    for (vector<int>::const_iterator it2 = v.cbegin(); it2 != v.end(); it2++)
        cout << *it2 << endl;

    vector<int> vv = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto it = vv.begin(); it != vv.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    //用基于范围的for循环遍历容器vv
    for (auto val : vv)
    {
        cout << val << " ";
    }
    cout << endl;

    int vv2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //不能用迭代器了,但是基于范围的for循环遍历可以
    for (auto val : vv2)
    {
        cout << val << " ";
    }
    cout << endl;
    //第二部分也可以直接用统一初始化列表
    for (auto val : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10})
    {
        cout << val << " ";
    }
    cout << endl;
}
int main()
{
    test();
    return 0;
}