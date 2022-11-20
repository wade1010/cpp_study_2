#include "iostream"
using namespace std;
class A
{
public:
    int m_a;
};
class B : virtual public A
{
};
class C : virtual public A
{
};
class D : public B, public C
{
};
void test()
{
    D d;
    cout << "sizeof(d)=" << sizeof(d) << endl; //两个m_a成员,所以是8字节
    //如果直接访问m_a成员,将报错
    // d.m_a;//D::m_a" 不明确
    // d.B::m_a = 100;
    // d.C::m_a = 200;
    d.m_a = 300;
    cout << "B::m_a的地址是:" << &d.B::m_a << "值是:" << d.B::m_a << endl;
    cout << "C::m_a的地址是:" << &d.C::m_a << "值是:" << d.C::m_a << endl;
    //菱形继承存在两个问题:数据冗余和名称的二义性,为了解决这两个问题,C++引入虚继承技术
}
int main()
{
    test();
    return 0;
}
// sizeof(d)=24
// B::m_a的地址是:0x61fde0值是:300
// C::m_a的地址是:0x61fde0值是:300