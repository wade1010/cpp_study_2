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
void func(unique_ptr<AA> &pu)
{
    cout << "func:" << pu->m_name << endl;
}

void func2(unique_ptr<AA> *pu)
{
    cout << "func2:" << (*pu)->m_name << endl;
}
void test()
{

    AA *ppp = new AA("aaa");
    unique_ptr<AA> pu(ppp);
    cout << "��ָ���ֵ��:" << ppp << endl;
    // cout << "pu����Ľ����:" << pu << endl; // VS����ִ��
    cout << "pu.get()����Ľ����:" << pu.get() << endl;
    cout << "pu�ĵ�ַ��:" << &pu << endl;

    func(pu); //����ָ���Ƕ���,�е�ַ,������ò�Ҫ����ַ,�Ƚ��鷳,����
    func2(&pu);

    unique_ptr<AA> up(new AA("hello"));
    AA *p = up.get();
    // up.reset(new AA("world"));
    cout << p << endl;

    unique_ptr<AA> up2(new AA("world"));

    cout << "before swap" << endl;
    cout << up->m_name << endl;
    cout << up2->m_name << endl;
    cout << up.get() << endl;
    cout << up2.get() << endl;
    cout << "after swap" << endl;
    up.swap(up2);
    cout << up->m_name << endl;
    cout << up2->m_name << endl;
    cout << up.get() << endl;
    cout << up2.get() << endl;
    // exit(1);//���������������

    unique_ptr<AA[]> parr(new AA[3]{string("a"), string("b"), string("c")});
    cout << parr[0].m_name << endl;
    cout << parr[1].m_name << endl;
    cout << parr[2].m_name << endl;
}
int main()
{
    test();
    return 0;
}
/* ���ù��캯��AA(const string &name),aaa
��ָ���ֵ��:0x1011710
pu.get()����Ľ����:0x1011710
pu�ĵ�ַ��:0x61fc98
func:aaa
func2:aaa
���ù��캯��AA(const string &name),hello
0x1011a80
���ù��캯��AA(const string &name),world
before swap
hello
world
0x1011a80
0x1011ab0
after swap
world
hello
0x1011ab0
0x1011a80
���ù��캯��AA(const string &name),a
���ù��캯��AA(const string &name),b
���ù��캯��AA(const string &name),c
a
b
c
������������,c
������������,b
������������,a
������������,hello
������������,world
������������,aaa */