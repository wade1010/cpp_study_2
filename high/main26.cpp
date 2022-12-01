#include <iostream>
using namespace std;

class AA // ���ࡣ
{
public:
    int m_a;
    int m_b;
    // ��һ�������Ĺ��캯������ʼ��m_a
    AA(int a) : m_a(a) { cout << " AA(int a)" << endl; }
    // �����������Ĺ��캯������ʼ��m_a��m_b
    AA(int a, int b) : m_a(a), m_b(b) { cout << " AA(int a, int b)" << endl; }
};

class BB : public AA // �����ࡣ
{
public:
    double m_c;
    using AA::AA; // ʹ�û���Ĺ��캯����
    // �����������Ĺ��캯��������A(a,b)��ʼ��m_a��m_b��ͬʱ��ʼ��m_c
    BB(int a, int b, double c) : AA(a, b), m_c(c)
    {
        cout << " BB(int a, int b, double c)" << endl;
    }
    void show() { cout << "m_a=" << m_a << ",m_b=" << m_b << ",m_c=" << m_c << endl; }
};

int main()
{
    // ��ʹ�û�����һ�������Ĺ��캯������ʼ��m_a
    BB b1(10);
    b1.show();

    // ��ʹ�û��������������Ĺ��캯������ʼ��m_a��m_b
    BB b2(10, 20);
    b2.show();

    // ��ʹ���������Լ������������Ĺ��캯��������A(a,b)��ʼ��m_a��m_b��ͬʱ��ʼ��m_c
    BB b3(10, 20, 10.58);
    b3.show();
}