#include <iostream>
#include <vector>
using namespace std;
//基于范围的for循环
class AA
{
public:
    string m_name;
    AA() { cout << "默认构造函数AA()" << endl; }
    AA(const string &name) : m_name(name)
    {
        cout << "构造函数,name=" << m_name << endl;
    }
    AA(const AA &a) : m_name(a.m_name)
    {
        cout << "拷贝构造函数,name=" << m_name << endl;
    }
    AA &operator=(const AA &a)
    {
        m_name = a.m_name;
        cout << "赋值函数,name=" << m_name << endl;
        return *this;
    }
    ~AA()
    {
        cout << "析构函数,name=" << m_name << endl;
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