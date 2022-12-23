#include <iostream>
using namespace std;

class AA // 基类。
{
public:
    int m_a;
    int m_b;
    // 有一个参数的构造函数，初始化m_a
    AA(int a) : m_a(a) { cout << " AA(int a)" << endl; }
    // 有两个参数的构造函数，初始化m_a和m_b
    AA(int a, int b) : m_a(a), m_b(b) { cout << " AA(int a, int b)" << endl; }
};

class BB : public AA // 派生类。
{
public:
    double m_c;
    using AA::AA; // 使用基类的构造函数。
    // 有三个参数的构造函数，调用A(a,b)初始化m_a和m_b，同时初始化m_c
    BB(int a, int b, double c) : AA(a, b), m_c(c)
    {
        cout << " BB(int a, int b, double c)" << endl;
    }
    void show() { cout << "m_a=" << m_a << ",m_b=" << m_b << ",m_c=" << m_c << endl; }
};

int main()
{
    // 将使用基类有一个参数的构造函数，初始化m_a
    BB b1(10);
    b1.show();

    // 将使用基类有两个参数的构造函数，初始化m_a和m_b
    BB b2(10, 20);
    b2.show();

    // 将使用派生类自己有三个参数的构造函数，调用A(a,b)初始化m_a和m_b，同时初始化m_c
    BB b3(10, 20, 10.58);
    b3.show();
}