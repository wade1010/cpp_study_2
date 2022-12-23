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
template <class T1, class T2>
class AA : public BB<T1, T2>
{
public:
    int m_a;
    AA(int a, T1 x, T2 y) : BB<T1, T2>(x, y), m_a(a)
    {
        cout << "调用了AA的构造函数" << endl;
    }
    void func1()
    {
        cout << "调用了func1()函数:m_a=" << m_a << endl;
    }
};

template <class T, class T1, class T2>
class CC : public BB<T1, T2>
{
public:
    T m_aa;
    CC(const T a, const T1 x, const T2 y) : m_aa(a), BB<T1, T2>(x, y)
    {
        cout << "调用了CC的构造函数" << endl;
    }
    void func3()
    {
        cout << "调用了func3的函数,m_aa=" << m_aa << endl;
    }
};
void test()
{
    AA<int, string> aa(1, 2, "hello");
    aa.func1();
    aa.func2();
}
void test2()
{
    CC<int, int, string> cc(1, 2, "hello");
    cc.func2();
    cc.func3();
}
int main()
{
    test2();
    return 0;
}
/*调用了BB的构造函数
调用了CC的构造函数
调用了func2函数:x2,y=hello
调用了func3的函数,m_aa=1*/