#include <iostream>
#include <chrono>
using namespace std;

void test()
{
    //静态成员函数chrono::steady_clock::now()获取开始的时间点
    // chrono::steady_clock::time_point start = chrono::steady_clock::now();
    auto start = chrono::steady_clock::now();

    // 执行一些代码,消耗一些时间
    cout << "开始计时" << endl;
    for (size_t i = 0; i < 1000000; i++)
    {
    }
    cout << "计时完成" << endl;

    auto diff = (chrono::steady_clock::now() - start).count();
    //单位是纳秒 自行换算
    cout << "耗时:" << diff << "纳秒(" << diff / 1000000 << "毫秒)" << endl;
}
int main()
{
    test();
    return 0;
}
/* 开始计时
计时完成
耗时:3419700纳秒(3毫秒) */