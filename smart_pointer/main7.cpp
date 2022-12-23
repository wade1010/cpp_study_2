#include <iostream>
#include <memory>
using namespace std;
//循环依赖 造成shared_ptr失效,内存泄漏
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
    shared_ptr<BB> sp;
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
    shared_ptr<AA> sp;
};
void test()
{
    shared_ptr<AA> spa = make_shared<AA>("a1");
    shared_ptr<BB> spb = make_shared<BB>("b1");
    spa->sp = spb;
    spb->sp = spa;
    //上面代码是循环引用,不会调用构造函数,导致内存泄漏
    //为了解决上述问题,C++引入了weak_ptr
}
int main()
{
    test();
    return 0;
}