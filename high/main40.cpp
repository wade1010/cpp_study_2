#include <iostream>
using namespace std;

void test()
{
    auto func = [](int a, const string &b)
    {
        cout << a << " " << b << endl;
    };
    func(1, "a"); //用lambda对象调用仿函数

    //引用lambda
    auto &func2 = func;
    func2(2, "b"); //引用lambda对象的引用调用仿函数
}
int main()
{
    test();
    return 0;
}