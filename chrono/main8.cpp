#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
//时间转换
time_t strTime2Unix(string &timestr)
{
    tm tm;
    memset(&tm, 0, sizeof(tm));
    sscanf(timestr.c_str(), "%d-%d-%d %d:%d:%d",
           &tm.tm_year, &tm.tm_mon, &tm.tm_mday, &tm.tm_hour, &tm.tm_min, &tm.tm_sec);
    tm.tm_year -= 1900;
    tm.tm_mon--;
    return mktime(&tm);
}
void test()
{
    string str = "2022-12-2 11:58:29";
    time_t tt = strTime2Unix(str);
    cout << tt << endl;
    cout << ctime(&tt) << endl;
}
int main()
{
    test();
    return 0;
}
/* 1669953509
Fri Dec 02 11:58:29 2022 */