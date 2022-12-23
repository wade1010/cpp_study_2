#include <iostream>
#include <chrono>
#include <iomanip> //put_time()函数需要包含的头文件
#include <sstream>
using namespace std;

void test()
{
    // 1 静态成员函数chrono::system_clock::now()用于获取系统时间 (C++时间)
    // chrono::time_point<chrono::system_clock> now = chrono::system_clock::now();
    auto now = chrono::system_clock::now();

    // 2 静态成员函数chrono::system_clock::to_time_t()把系统时间转换为time_t.(UTC时间)
    // time_t t_now = chrono::system_clock::to_time_t(now);
    auto t_now = chrono::system_clock::to_time_t(now);

    // 3 std::localtime()函数把time_t转换成本地时间 (北京时间)
    // localtime()不是线程安全的,VS用localtime_s代替,Linux用localtime_r代替//vscode g++ 里面没有这两
    // tm *tm_now = std::localtime(&t_now);
    auto *tm_now = std::localtime(&t_now);

    // 4 格式化输出tm结构体中的成员
    cout << put_time(tm_now, "%Y-%m-%d %H:%M:%S") << endl;
    cout << put_time(tm_now, "%Y-%m-%d") << endl;
    cout << put_time(tm_now, "%H:%M:%S") << endl;
    cout << put_time(tm_now, "%Y%m%d%H%M%S") << endl;

    stringstream ss; //创建stringstream对象ss,需要包含头文件 <sstream>
    ss << put_time(tm_now, "%Y-%m-%d %H:%M:%S");
    string time_str = ss.str();
    cout << time_str << endl;

    //时间偏移
    t_now += 24 * 3600;

    auto *tm_now2 = std::localtime(&t_now);
    cout << "偏移后:" << put_time(tm_now2, "%Y-%m-%d %H:%M:%S") << endl;
}
int main()
{
    test();
    return 0;
}
/* 2022-12-01 19:36:19
2022-12-01
19:36:19
20221201193619
2022-12-01 19:36:19
偏移后:2022-12-02 19:36:19 */