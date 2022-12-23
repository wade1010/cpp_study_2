#include <iostream>
#include <iomanip>
using namespace std;
//????
void test()
{
    time_t timep;
    time(&timep);
    printf("time():%d \n", timep);
    struct tm *p = localtime(&timep);
    timep = mktime(p);
    printf("time()->localtime()->mktime():%d\n", timep);
}
int main()
{
    test();
    return 0;
}
