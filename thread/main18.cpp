#include <iostream>
#include <atomic>
using namespace std;

void test()
{
    atomic<int> ii(3); // 原子变量
    int expect = 3;    // 期待值
    // int expect = 4;    // 期待值
    int val = 5; // 打算存入原子变量的值
    // 比较原子变量的值和预期值expect，
    // 如果当两个值相等，把val存储到原子变量中；
    // 如果当两个值不相等，用原子变量的值更新预期值。
    // 执行存储操作时返回true，否则返回false。
    bool bret = ii.compare_exchange_strong(expect, val);
    cout << "bret=" << bret << endl;
    cout << "ii=" << ii << endl;
    cout << "expect=" << expect << endl;
}
int main()
{
    test();
    return 0;
}
//  int expect = 3;
/* bret=0
ii=3
expect=3 */

//  int expect = 4;
/* bret=1
ii=5
expect=3 */