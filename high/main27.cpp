#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void zsshow(const int &no)
{
    cout << no << endl;
}
class AA
{
public:
    void operator()(const int &no)
    {
        cout << no << endl;
    }
};
void test()
{
    vector<int> vv{1, 2, 3, 4};
    //普通函数
    for_each(vv.begin(), vv.end(), zsshow);
    //仿函数
    for_each(vv.begin(), vv.end(), AA());

    // lambda
    auto func = [](const int &no) -> void
    {
        cout << no << endl;
    };

    for_each(vv.begin(), vv.end(), func);

    func(3);

    auto func2 = []
    {
        cout << "没有参数列表,省略括号" << endl;
    };
    func2();
}
int main()
{
    test();
    return 0;
}