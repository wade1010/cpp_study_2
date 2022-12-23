#include <iostream>
#include <memory>
using namespace std;
//使用weak_ptr解决循环依赖
class BB;
class AA
{
public:
    string m_name;
    AA() { cout << "调用构造函数AA()" << endl; }
    AA(const string &name) : m_name(name)
    {
        cout << "调用构造函数AA(const string &name)" << endl;
    }
    ~AA()
    {
        cout << "调用AA析构函数" << endl;
    }
    weak_ptr<BB> sp;
};

class BB
{
public:
    string m_name;
    BB() { cout << "调用构造函数BB()" << endl; }
    BB(const string &name) : m_name(name)
    {
        cout << "调用构造函数BB(const string &name)" << endl;
    }
    ~BB()
    {
        cout << "调用BB析构函数" << endl;
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
    //引用计数不会发生变化
    cout << "spa.use_count()" << spa.use_count() << endl;
    cout << "spb.use_count()" << spb.use_count() << endl;
}
int main()
{
    test();
    return 0;
}