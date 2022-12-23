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
//����func1()����һ��ָ��,���������ָ�븺��
void func1(const AA *a)
{
    cout << "call func1:" << a->m_name << endl;
}
//����func2()��Ҫһ��ָ��,���Ҷ����ָ�븺��
void func2(AA *a)
{
    cout << "call func2" << a->m_name << endl;
    delete a;
}

//����func3()��Ҫһ��unique_ptr,��������unique_ptr����
void func3(const unique_ptr<AA> &p)
{
    cout << "call func3:" << p->m_name << endl;
}
//����func4()��Ҫһ��unique_ptr,���һ�����unique_ptr����
void func4(unique_ptr<AA> p)
{
    cout << "call func4:" << p->m_name << endl;
}
void test()
{
    unique_ptr<AA> p(new AA("a1"));
    cout << "��ʼ���ú���" << endl;
    // func1(p.get()); //����func1()��Ҫһ��ָ��,���������ָ�븺��
    // func2(p.release()); //����func2()��Ҫһ��ָ��,���Ҷ����ָ�븺��
    // func3(p); //����func3()��Ҫһ��unique_ptr,��������unique_ptr����
    func4(move(p)); //����func4()��Ҫһ��unique_ptr,���һ�����unique_ptr����   ��ֵ,�����Ǵ�����
    cout << "�������ú���" << endl;
}
int main()
{
    test();
    return 0;
}
/* ���ù��캯��AA(const string &name),a1
��ʼ���ú���
call func4:a1
������������,a1
�������ú��� */