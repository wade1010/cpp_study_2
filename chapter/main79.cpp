#include "iostream"
using namespace std;
template <class T1, class T2>
class BB
{
public:
    T1 m_x;
    T2 m_y;
    BB(T1 x, T2 y) : m_x(x), m_y(y)
    {
        cout << "调用了BB的构造函数" << endl;
    }
    void func2() const
    {
        cout << "调用了func2函数:x" << m_x << ",y=" << m_y << endl;
    }
};

class AA : public BB<int, string>
{
public:
    int m_a;
    AA(int a, int x, string y) : BB(x, y), m_a(a)
    {
        cout << "调用了AA的构造函数" << endl;
    }
    void func1()
    {
        cout << "调用了func1()函数:m_a=" << m_a << endl;
    }
};

void test()
{
    AA aa(1, 2, "hello");
    aa.func1();
    aa.func2();
}
int main()
{
    test();
    return 0;
}
/*调用了BB的构造函数
调用了AA的构造函数
调用了func1()函数:m_a=1
调用了func2函数:x2,y=hello*/