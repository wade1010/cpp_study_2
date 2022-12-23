#include <iostream>
#include <memory>
using namespace std;
class AA
{
public:
    string m_name;
    AA() { cout << "调用构造函数AA()," << m_name << endl; }
    AA(const string &name) : m_name(name) { cout << "调用了构造函数AA(const string &name)," << m_name << endl; }
    ~AA() { cout << "调用了析构函数~AA()," << m_name << endl; }
};
void test()
{
    // shared_ptr<AA> sp(new AA("a1"));
    shared_ptr<AA> sp = make_shared<AA>("a1");
    cout << "sp.use_count()=" << sp.use_count() << endl;
    cout << "sp->m_name=" << sp->m_name << endl;
    shared_ptr<AA> sp2(sp); //拷贝构造
    cout << "sp2.use_count()=" << sp2.use_count() << endl;
    cout << "sp2->m_name=" << sp2->m_name << endl;
    shared_ptr<AA> sp3 = sp; //赋值
    cout << "sp3.use_count()=" << sp3.use_count() << endl;
    cout << "sp3->m_name=" << sp3->m_name << endl;

    cout << "--------------------" << endl;
    shared_ptr<AA> pa0(new AA("a1"));
    shared_ptr<AA> pa1(pa0);
    shared_ptr<AA> pa2 = pa0;
    cout << "pa2.use_count()=" << pa2.use_count() << endl; //值为3

    shared_ptr<AA> pb0(new AA("b"));
    shared_ptr<AA> pb1 = pb0;
    cout << "pb0.use_count()=" << pb0.use_count() << endl; //值为2

    pb1 = pa1;
    cout << "pa2.use_count()=" << pa2.use_count() << endl; //值为4
    cout << "pb0.use_count()=" << pb0.use_count() << endl; //值为1
    cout << "end" << endl;
}
int main()
{
    test();
    return 0;
}