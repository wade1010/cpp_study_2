#include <iostream>
using namespace std;

void test()
{
//不同操作系统的宏:__linux_  _WIN32
#ifdef _WIN32
    cout << "这是windows系统" << endl;
    typedef long long int64;
#else
    cout << "这不是windows系统" << endl;
    typedef long int64;
#endif
    int64 a = 10;
    cout << "a=" << a << endl;
}
int main()
{
    test();
    return 0;
}