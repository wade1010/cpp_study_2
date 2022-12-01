#include <iostream>
#include <chrono>
using namespace std;

void test()
{
    chrono::hours c1(1);                     // 1个小时
    chrono::minutes c2(60);                  // 60分钟
    chrono::seconds c3(3600);                // 3600秒
    chrono::milliseconds c4(60 * 60 * 1000); //毫秒
    // chrono::microseconds c5(60 * 60 * 1000 * 1000);//警告:整数溢出
    if (c1 == c2)
    {
        cout << "c1==c2" << endl;
    }
    if (c1 == c3)
    {
        cout << "c1==c3" << endl;
    }
    if (c1 == c4)
    {
        cout << "c1==c4" << endl;
    }

    chrono::microseconds c6(12);
    //获取时钟周期的值
    cout << "c6=" << c6.count() << endl;

    cout << "ok" << endl;
}
int main()
{
    test();
    return 0;
}