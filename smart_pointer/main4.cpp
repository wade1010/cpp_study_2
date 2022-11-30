#include <iostream>
#include <memory>
using namespace std;
class AA
{
public:
    string m_name;
    AA()
    {
        cout << m_name << "���ù��캯��AA()" << endl;
    }
    AA(const string &name) : m_name(name)
    {
        cout << "���ù��캯��AA(const string &name)," << m_name << endl;
    }
    ~AA() { cout << "������������," << m_name << endl; }
};

void test()
{
    /* // AA *parr1 = new AA[2]{string("a1"), string("a2")};//ָ������Ԫ�صĳ�ʼֵ,���������д���
    AA *parr1 = new AA[2]; //��ָͨ������
    parr1[0].m_name = "a1";
    cout << "parr1[0].m_name=" << parr1[0].m_name << endl;
    parr1[1].m_name = "a2";
    cout << "parr1[1].m_name=" << parr1[1].m_name << endl;
    delete[] parr1; */

    // unique_ptr<AA[]> pu(new AA[2]{string("a1"), string("a2")});
    unique_ptr<AA[]> pu(new AA[2]);
    pu[0].m_name = "a1";
    cout << "pu[0].m_name=" << pu[0].m_name << endl;
    pu[1].m_name = "a2";
    cout << "pu[0].m_name=" << pu[1].m_name << endl;
}
int main()
{
    test();
    return 0;
}
/* ���ù��캯��AA()
���ù��캯��AA()
pu[0].m_name=a1
pu[0].m_name=a2
������������,a2
������������,a1*/