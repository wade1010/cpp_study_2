#include "tools.h"
#include "girls.h"
void test()
{
    cout << "max(4,6)=" << max(4, 6) << endl;
    cout << "min(4,6)=" << min(4, 6) << endl;

    cout << "全局变量a=" << a << endl;
    cout << "全局变量b=" << b << endl;
}
int main()
{
    test();
    return 0;
}