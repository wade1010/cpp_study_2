#include "iostream"
using namespace std;

//冗余的模板友元
template <class T1, class T2>
class AA
{
    T1 m_x;
    T2 m_y;

public:
    AA(const T1 x, const T2 y) : m_x(x), m_y(y)
    {
    }
    friend void show(const AA<int, string> &a);
    friend void show(const AA<char, string> &a);
};

void show(const AA<int, string> &a)
{
    cout << a.m_x << endl;
    cout << a.m_y << endl;
}

void show(const AA<char, string> &a)
{
    cout << a.m_x << endl;
    cout << a.m_y << endl;
}

void test()
{
    AA<int, string> aa(1, "hello");
    show(aa);

    AA<char, string> bb('a', "hello");
    show(bb);
}
int main()
{
    test();
    return 0;
}