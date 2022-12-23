#include <iostream>
#include <memory>
using namespace std;
//ѭ������ ���shared_ptrʧЧ,�ڴ�й©
class BB;
class AA
{
public:
    string m_name;
    AA() { cout << "���ù��캯��AA()" << endl; }
    AA(const string &name) : m_name(name)
    {
        cout << "���ù��캯��AA(const string &name)" << endl;
    }
    ~AA()
    {
        cout << "����AA��������" << endl;
    }
    shared_ptr<BB> sp;
};

class BB
{
public:
    string m_name;
    BB() { cout << "���ù��캯��BB()" << endl; }
    BB(const string &name) : m_name(name)
    {
        cout << "���ù��캯��BB(const string &name)" << endl;
    }
    ~BB()
    {
        cout << "����BB��������" << endl;
    }
    shared_ptr<AA> sp;
};
void test()
{
    shared_ptr<AA> spa = make_shared<AA>("a1");
    shared_ptr<BB> spb = make_shared<BB>("b1");
    spa->sp = spb;
    spb->sp = spa;
    //���������ѭ������,������ù��캯��,�����ڴ�й©
    //Ϊ�˽����������,C++������weak_ptr
}
int main()
{
    test();
    return 0;
}