#include "iostream"
using namespace std;
class Person
{
public:
    int m_rank;
    Person() {}
    template <typename T>
    Person(T a)
    {
        cout << "a=" << a << endl;
    }
    //�������麯��
    // template <typename T>
    // virtual void show(T b)
    // {
    //     cout << "b=" << b << endl;
    // }
};

template <typename T>
void mySwap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
    cout << "ʹ��ģ��" << endl;
}

template <typename T>
void mySwap2()
{
    cout << "call mySwap2" << endl;
}

template <typename T>
T Add(T a, T b)
{
    return a + b;
}

template <typename T>
void func(T a)
{
    cout << "func(T a)" << endl;
}
template <typename T1, typename T2>
void func(T1 a, T2 b)
{
    cout << "func(T1 a,T2 b)" << endl;
}

template <typename T1, typename T2, typename T3>
void func(T1 a, T2 b, T3 c)
{
    cout << "func(T1 a,T2 b,T3 c)" << endl;
}

void test()
{
    // int a = 10;
    // int b = 10;
    // mySwap(a, b);

    // int a = 10;
    // char b = 10;
    // mySwap(a, b);//����

    mySwap2<int>();
    mySwap2<char>(); // int char ...����,ֻҪ��һ���������;Ϳ���

    //����Add��ʱ��,������������������ǿ��Ե�,���ǵ����������(���Ǹ���������+��),������ע������3

    int c = 10;
    char d = 20;
    int f = Add<int>(c, d); //ָ������,�ᷢ����ʽ����ת��
    cout << "f=" << f << endl;

    //ע������6
    func(1);
    func(1, 2);
    func(1, 2, 3);
}

//���廯
/* template <>
void mySwap<Person>(Person &p1, Person &p2)
ͬ��
*/
template <>
void mySwap(Person &p1, Person &p2)
{
    int temp = p1.m_rank;
    p1.m_rank = p2.m_rank;
    p2.m_rank = temp;
    cout << "ʹ�þ��廯" << endl;
}
void test2()
{
    Person p1;
    p1.m_rank = 1;
    Person p2;
    p2.m_rank = 2;
    cout << p1.m_rank << endl;
    mySwap(p1, p2);
    cout << p1.m_rank << endl;
}
int main()
{
    // test();
    test2();
    return 0;
}