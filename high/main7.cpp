#include <iostream>
#include <vector>
using namespace std;
//���ڷ�Χ��forѭ��
class AA
{
public:
    string m_name;
    AA() { cout << "Ĭ�Ϲ��캯��AA()" << endl; }
    AA(const string &name) : m_name(name)
    {
        cout << "���캯��,name=" << m_name << endl;
    }
    AA(const AA &a) : m_name(a.m_name)
    {
        cout << "�������캯��,name=" << m_name << endl;
    }
    AA &operator=(const AA &a)
    {
        m_name = a.m_name;
        cout << "��ֵ����,name=" << m_name << endl;
        return *this;
    }
    ~AA()
    {
        cout << "��������,name=" << m_name << endl;
    }
};
void test()
{
    vector<int> vv = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto val : vv)
    {
        cout << val << " ";
    }
    cout << endl;
    for (auto val : vv)
    {
        cout << val << " ";
    }
    cout << endl;

    vector<AA> va;
    cout << va.capacity() << endl;
    va.emplace_back("p1");
    cout << va.capacity() << endl;
    va.emplace_back("p2");
    cout << va.capacity() << endl;
    va.emplace_back("p3");
    cout << va.capacity() << endl;

    for (const auto &a : va)
    {
        cout << a.m_name << " ";
    }
    cout << endl;
}
int main()
{
    test();
    return 0;
}