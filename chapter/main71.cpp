#include "iostream"
using namespace std;
// template <class T1, class T2>
template <class T1, class T2 = double> //使用缺省
class AA
{
public:
    T1 m_a;
    T2 m_b;
    AA(T1 a, T2 b) : m_a(a), m_b(b) {}
    T1 geta()
    {
        T1 a = 2;
        return m_a + a;
    }
    T2 getb();
};
//类外实现  但是这时不能用缺省 报错为 不能在类外部的类模板成员声明上指定默认模板参数
// template <class T1, class T2 = double>//报错
template <class T1, class T2>
T2 AA<T1, T2>::getb()
{
    T2 b = 1;
    return m_b + b;
}

void test()
{
    // AA<int, double> a(1, 2.2);
    AA<int> a(1, 2.2); //同上,只不过使用了缺省
    int ret = a.geta();
    double b = a.getb();
    cout << ret << endl;
    cout << b << endl;

    //用new创建模板对象
    AA<int, double> *pa = new AA<int, double>(1, 33.33);
    cout << pa->geta() << endl;
    cout << pa->getb() << endl;
}
int main()
{
    test();
    return 0;
}