#include "iostream"
using namespace std;
// 非约束模板友元
template <class T1, class T2>
class AA
{
    template <typename T>
    friend void show(T &a);
    T1 m_x;
    T2 m_y;

public:
    AA(const T1 x, const T2 y) : m_x(x), m_y(y) {}
};

template <typename T>
void show(T &a) //通用的函数模板
{
    cout << "通用:x=" << a.m_x << ",y=" << a.m_y << endl;
}

template <>
void show(AA<int, string> &a) //函数模板的具体版本
{
    cout << "具体<int,string>:x=" << a.m_x << ",y=" << a.m_y << endl;
}

void test()
{
    AA<int, string> aa(3, "hello");
    show(aa);

    AA<char, string> bb('a', "world");
    show(bb);
}
int main()
{
    test();
    return 0;
}