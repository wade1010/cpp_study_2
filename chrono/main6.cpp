#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <thread>
using namespace std;

void test()
{
    time_t tt = chrono::system_clock::to_time_t(chrono::system_clock::now());
    tm *ptm = localtime(&tt);
    cout << "current time:" << put_time(ptm, "%Y-%m-%d %H:%M:%S") << endl;
    cout << "waiting for the next minute to begin..." << endl;
    ptm->tm_min++;
    ptm->tm_sec = 0;
    this_thread::sleep_until(chrono::system_clock::from_time_t(mktime(ptm)));
    cout << put_time(ptm, "%Y-%m-%d %H:%M:%S") << "reached!" << endl;
}
int main()
{
    test();
    return 0;
}
/* current time:2022-12-02 11:12:24
waiting for the next minute to begin...
2022-12-02 11:13:00reached! */