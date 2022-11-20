#include <iostream>

using namespace std;
class A
{
private:
    int m_b;

public:
    int m_a;
    A() : m_a(0), m_b(0)
    {
        cout << "调用了基类的默认构造函数A()." << endl;
    }
    A(int a, int b) : m_a(a), m_b(b)
    {
        cout << "调用了基类的构造函数A(int a,int b)" << endl;
    }
    A(const A &a) : m_a(a.m_a), m_b(a.m_b)
    {
        cout << "调用了基类的拷贝构造函数A(const A &a)" << endl;
    }
    ~A()
    {
        cout << "调用了基类的析构函数" << endl;
    }
    void showA()
    {
        cout << "m_a=" << m_a << "  m_b" << m_b << endl;
    }
};

class B : public A
{
public:
    int m_c;
    B() : m_c(0), A() //派生类的默认构造函数,指明用基类的默认构造函数(不指明也无所谓)
    {
        cout << "调用了派生类的默认构造函数" << endl;
    }
    B(int a, int b, int c) : m_c(c), A(a, b) //指明用基类的两个参数的构造函数
    {
        cout << "调用了B的构造函数B(int a, int b, int c)" << endl;
    }
    B(const A &a, int c) : A(a), m_c(c) //指明用基类的拷贝构造函数
    {
        cout << "调用了派生类的构造函数B(cosnt A &a,int c)" << endl;
    }
    //显示派生类 B的全部的成员
    void showB()
    {
        cout << "m_c=" << m_c << endl;
    }
};

void test()
{
    B b1; //调用基类磨人的构造函数
    b1.showA();
    b1.showB();

    B b2(1, 2, 3);
    b2.showA();
    b2.showB();
    A a(12, 22);
    B b3(a, 23);
    b3.showA();
    b3.showB();
}

int main()
{
    test();
    return 0;
}