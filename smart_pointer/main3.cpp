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
//函数func1()需用一个指针,但不对这个指针负责
void func1(const AA *a)
{
    cout << "call func1:" << a->m_name << endl;
}
//函数func2()需要一个指针,并且对这个指针负责
void func2(AA *a)
{
    cout << "call func2" << a->m_name << endl;
    delete a;
}

//函数func3()需要一个unique_ptr,不会对这个unique_ptr负责
void func3(const unique_ptr<AA> &p)
{
    cout << "call func3:" << p->m_name << endl;
}
//函数func4()需要一个unique_ptr,并且会对这个unique_ptr负责
void func4(unique_ptr<AA> p)
{
    cout << "call func4:" << p->m_name << endl;
}
void test()
{
    unique_ptr<AA> p(new AA("a1"));
    cout << "开始调用函数" << endl;
    // func1(p.get()); //函数func1()需要一个指针,但不对这个指针负责
    // func2(p.release()); //函数func2()需要一个指针,并且对这个指针负责
    // func3(p); //函数func3()需要一个unique_ptr,不会对这个unique_ptr负责
    func4(move(p)); //函数func4()需要一个unique_ptr,并且会对这个unique_ptr负责   传值,而不是传引用
    cout << "结束调用函数" << endl;
}
int main()
{
    test();
    return 0;
}
/* 调用构造函数AA(const string &name),a1
开始调用函数
call func4:a1
调用析构函数,a1
结束调用函数 */