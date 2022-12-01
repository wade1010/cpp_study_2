#include <iostream>
using namespace std;
//左值 右值
class AA
{
};
AA getTemp()
{
    return AA();
}

AA &getTemp2(AA &a)
{
    return a;
}
void test()
{
    int i = 3;          // i是左值,3是右值
    int j = i + 3;      // j是左值,i+8是右值
    AA a = getTemp();   // a是左值,getTemp()的返回值是右值(临时变量)
    AA b = getTemp2(a); // b是左值,getTemp2(a)的返回值是引用,是左值.
    AA c;
    getTemp2(a) = c;
}
int main()
{
    test();
    return 0;
}