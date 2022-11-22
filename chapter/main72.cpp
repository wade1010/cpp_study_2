#include "iostream"
using namespace std;
// template <class T1, class T2>
template <class T1, class T2 = double> //使用缺省
class AA
{
public:
    T1 m_a;
    T2 m_b;
    AA()
    {
        // 模板类的成员函数使用了才会创建，不适用不会创建
        m_a.aaaaaaaaaaa();
    }
    AA(T1 a, T2 b) : m_a(a), m_b(b)
    {
        // 模板类的成员函数使用了才会创建，不适用不会创建
        m_b.aaaaaaaaaaa();
    }
    T1 geta()
    {
        T1 a = 2;
        return m_a + a;
    }
    T2 getb();
};
void test()
{
    AA<int, double> *a; //只声明指针,不创建对象,编译 运行都没问题
    // AA<int, double> *a = new AA<int, double>(3, 3.3); //创建对象,这里就会报错了
}
int main()
{
    test();
    return 0;
}