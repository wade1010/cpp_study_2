#include "iostream"
using namespace std;

void test()
{
    char a;
    cout << "sizeof(char)=" << sizeof(char) << endl;
    short b;
    cout << "sizeof(short)=" << sizeof(short) << endl;
    int c;
    cout << "sizeof(int)=" << sizeof(int) << endl;
    double d;
    cout << "sizeof(double)=" << sizeof(double) << endl;

    cout << "a的地址是:" << (void *)&a << endl;
    cout << "a的地址+1是:" << (void *)(&a + 1) << endl;
    cout << "b的地址是:" << (void *)&b << endl;
    cout << "b的地址+1是:" << (void *)(&b + 1) << endl;
    cout << "c的地址是:" << (void *)&c << endl;
    cout << "c的地址+1是:" << (void *)(&c + 1) << endl;
    cout << "d的地址是:" << (void *)&d << endl;
    cout << "d的地址+1是:" << (void *)(&d + 1) << endl;
}
int main()
{
    test();
    return 0;
}
