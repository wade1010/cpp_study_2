#include <iostream>
#include <memory>
using namespace std;
//ʹ��weak_ptr���ѭ������
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
    weak_ptr<BB> sp;
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
    weak_ptr<AA> sp;
};
void test()
{
    shared_ptr<AA> spa = make_shared<AA>("a1");
    shared_ptr<BB> spb = make_shared<BB>("b1");
    cout << "spa.use_count()" << spa.use_count() << endl;
    cout << "spb.use_count()" << spb.use_count() << endl;
    spa->sp = spb;
    spb->sp = spa;
    //���ü������ᷢ���仯
    cout << "spa.use_count()" << spa.use_count() << endl;
    cout << "spb.use_count()" << spb.use_count() << endl;
}
int main()
{
    test();
    return 0;
}