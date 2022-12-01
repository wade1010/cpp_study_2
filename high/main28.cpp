#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void test()
{
    int ii = 19;
    double dd = 222.222;
    auto func = [=](const int &no) -> void
    {
        cout << ii << endl;
        cout << dd << endl;
        cout << no << endl;
    };
    func(22);
}
int main()
{
    test();
    return 0;
}