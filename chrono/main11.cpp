#include <iostream>
#include <time.h>
#include <sys/time.h>
#include <chrono>
using namespace std;
int64_t getTimeStamp()
{

    int mSecond = 0;
#if defined(WIN32)
    SYSTEMTIME sys;
    GetLocalTime(&sys);
    mSecond = sys.wMilliseconds;
#else
    // linux
    struct timeval tv;
    struct timezone tz;
    struct tm *p;
    gettimeofday(&tv, &tz);
    cout << tv.tv_sec << endl;
    cout << tv.tv_usec << endl;
    p = localtime((time_t *)&tv.tv_sec);
    mSecond = tv.tv_usec / 1000;
#endif
    int64_t timeStamp = ((int64_t)time(NULL)) * 1000 + mSecond;
    return timeStamp;
}
void test()
{
    int64_t timestamp = getTimeStamp();
    cout << timestamp << endl;
}
int main()
{
    test();
    return 0;
}