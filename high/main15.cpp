#include <iostream>
#include <array>
using namespace std;
// array容器
void test()
{
    int aa[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    array<int, 10> ab = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // array迭代有4种方法
    for (int i = 0; i < 10; i++)
    {
        cout << ab[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < ab.size(); i++)
    {
        cout << ab[i] << " ";
    }
    cout << endl;

    for (auto it = ab.begin(); it != ab.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    for (auto val : ab)
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