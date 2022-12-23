#include "iostream"
using namespace std;
class AA
{
public:
    int m_a;
    AA(int a) : m_a(a)
    {
        cout << "调用了AA的构造函数" << endl;
    }
    void func1()
    {
        cout << "调用了func1()函数:m_a=" << m_a << endl;
    }
};

template <class T1, class T2>
class BB : public AA
{
public:
    T1 m_x;
    T2 m_y;
    BB(T1 x, T2 y, int a) : AA(a), m_x(x), m_y(y)
    {
        cout << "调用了BB的构造函数" << endl;
    }
    void func2() const
    {
        cout << "调研了func2函数:x" << m_x << ",y=" << m_y << endl;
    }
};
void test()
{
    BB<string, double> b("huluwa", 3.3, 4);
    b.func2();
    b.func1();
}
int main()
{
    test();
    return 0;
}
/* 调用了AA的构造函数
调用了BB的构造函数
调研了func2函数:xhuluwa,y=3.3
调用了func1()函数:m_a=4 */