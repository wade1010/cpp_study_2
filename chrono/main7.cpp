#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>
using namespace std;

void test()
{
    using chrono::system_clock;
    auto tt = system_clock::to_time_t(system_clock::now());
    tm *plt = localtime(&tt);
    cout << "current time:" << put_time(plt, "%Y-%m-%d %H:%M:%S") << endl;
    plt->tm_min++;
    cout << "sleep until  " << put_time(plt, "%Y-%m-%d %H:%M:%S") << endl;
    this_thread::sleep_until(system_clock::from_time_t(mktime(plt)));
    cout << "ok,current time:" << put_time(plt, "%Y-%m-%d %H:%M:%S") << endl;
}
int main()
{
    test();
    return 0;
}
/* current time:2022-12-02 11:34:57
sleep until  2022-12-02 11:35:57
ok,current time:2022-12-02 11:35:57 */