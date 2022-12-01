#include <iostream>
using namespace std;
//委托构造
class AA
{
    int m_a;
    int m_b;
    double m_c;

public:
    AA(double c)
    {
        m_c = c + 3;
        cout << "AA(double c)" << endl;
    }
    AA(int a, int b)
    {
        m_a = a + 1;
        m_b = b + 2;
        cout << "AA(int a,int b)" << endl;
    }
    // 构造函数委托AA(int a, int b)初始化m_a和m_b
    AA(int a, int b, const string &str) : AA(a, b)
    {
        cout << m_a << m_b << str << endl;
    }
    // 构造函数委托AA(double c)初始化m_c
    AA(double c, const string &str) : AA(c)
    {
        cout << "m_c=" << m_c << ",str=" << str << endl;
    }
};
void test()
{
    AA a1(1, 2, "222");
    cout << endl;
    AA a2(2.2, "hello");
}
int main()
{
    test();
    return 0;
}