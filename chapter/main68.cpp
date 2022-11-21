#include "iostream"
using namespace std;

double func(int a, double b, const char *c, float d, short e, long f)
{
    cout << "call func" << endl;
    return 5.5;
}

void test()
{
    double (*pf)(int, double, const char *, float, short, long);
    pf = func;
    pf(1, 1, "a", 1, 1, 1);
    //使用auto自动推导
    auto pf2 = func;
    pf2(1, 1, "a", 1, 1, 1);
}
int main()
{
    test();
    return 0;
}