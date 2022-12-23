#include <iostream>
#include <vector>
using namespace std;

void test() noexcept
{
    if (!noexcept(throw "aaaa"))
    {
        cout << "抛出异常" << endl;
    }

    //分配一大块内存
    double *ptr = nullptr;
    try
    {
        ptr = new double[1110001111111100];
    }
    catch (bad_alloc &e)
    {
        cout << "分配内存失败," << e.what() << endl;
    }
    if (ptr != nullptr)
    {
        delete ptr;
    }

    double *ptr2 = new (nothrow) double[1110001111111100];
    if (ptr2 == nullptr)
    {
        cout << "内存分配失败" << endl;
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
// 抛出异常