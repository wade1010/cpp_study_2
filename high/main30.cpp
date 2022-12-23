#include <iostream>
using namespace std;
//左值 右值
class AA
{
public:
    string m_a;
};
AA getTemp()
{
    return AA();
}

void test()
{
    int &&a = 3;
    int b = 78;
    int &&c = b + 1;
    // int &&d = c; //错误,因为右值有了名字之后就成了左值,所以再对左值进行右值引用,报错
    int &d = c; //正确

    AA &&aa = getTemp();
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << aa.m_a << endl;

    //常量左值引用
    int aaa = 1;
    int &bbb1 = aaa;
    const int &bbb2 = aaa;

    const int &bbb3 = 1;
    int &&ccc = 1;
}
int main()
{
    test();
    return 0;
}