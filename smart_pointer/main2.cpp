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
unique_ptr<AA> func()
{
    unique_ptr<AA> p(new AA("a3"));
    return p;
}
// unique_ptr<AA> sp(new AA("a4"));
// unique_ptr<AA> func2()
// {
//     return sp;
// }
void test()
{
    unique_ptr<AA> pu1(new AA("a1"));
    unique_ptr<AA> pu2;
    // pu2 = pu1; //错误
    pu2 = unique_ptr<AA>(new AA("a2")); //用匿名对象赋值
    cout << "调用func()之前." << endl;
    // unique_ptr类的赋值函数已经被删除了,但是这一行还能赋值,神奇之一
    // pu2不可能管理多个资源,所以,它先释放了a2,再接手a3
    //但是如果把func()函数中的unique_ptr声明放在外面,如func2(),报错,编译不通过
    pu2 = func();
    cout << "调用func()之后" << endl;
    AA *optr = pu2.release();
    cout << optr << endl;
    cout << "结束" << endl;
}
int main()
{
    test();
    return 0;
}
/*调用构造函数AA(const string &name),a1
调用构造函数AA(const string &name),a2
调用func()之前.
调用构造函数AA(const string &name),a3
调用析构函数,a2
调用func()之后
0xef1ab0
结束
调用析构函数,a1*/