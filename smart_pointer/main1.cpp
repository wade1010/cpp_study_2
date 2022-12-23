#include <iostream>
#include <memory>
using namespace std;
class AA
{
public:
    string m_name;
    AA()
    {
        cout << m_name << "调用构造函数AA()" << endl;
    }
    AA(const string &name) : m_name(name)
    {
        cout << "调用构造函数AA(const string &name)," << m_name << endl;
    }
    ~AA() { cout << "调用析构函数," << m_name << endl; }
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
    cout << "裸指针的值是:" << ppp << endl;
    // cout << "pu输出的结果是:" << pu << endl; // VS可以执行
    cout << "pu.get()输出的结果是:" << pu.get() << endl;
    cout << "pu的地址是:" << &pu << endl;

    func(pu); //智能指针是对象,有地址,但是最好不要传地址,比较麻烦,如下
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
    // exit(1);//不会调用析构函数

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
/* 调用构造函数AA(const string &name),aaa
裸指针的值是:0x1011710
pu.get()输出的结果是:0x1011710
pu的地址是:0x61fc98
func:aaa
func2:aaa
调用构造函数AA(const string &name),hello
0x1011a80
调用构造函数AA(const string &name),world
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
调用构造函数AA(const string &name),a
调用构造函数AA(const string &name),b
调用构造函数AA(const string &name),c
a
b
c
调用析构函数,c
调用析构函数,b
调用析构函数,a
调用析构函数,hello
调用析构函数,world
调用析构函数,aaa */