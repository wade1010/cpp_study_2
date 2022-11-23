#include "iostream"
using namespace std;
class AA
{
public:
    AA() { cout << "调用了AA的构造函数AA()" << endl; }
    AA(int a) { cout << "调用了AA的构造函数AA(int a)" << endl; }
};

class BB
{
public:
    BB() { cout << "调用了BB的构造函数BB()" << endl; }
    BB(int a) { cout << "调用了BB的构造函数BB(int a)" << endl; }
};
class CC
{
public:
    CC() { cout << "调用了CC的构造函数CC()" << endl; }
    CC(int a) { cout << "调用了CC的构造函数CC(int a)" << endl; }
};

template <class T>
class DD
{
public:
    DD() { cout << "调用了DD的构造函数DD()" << endl; }
    DD(int a) { cout << "调用了DD的构造函数DD(int a)" << endl; }
};

template <class T>
class EE : public T //模板类继承模板参数给出的基类.
{
public:
    EE() : T() { cout << "调用了EE的构造函数EE()" << endl; }
    EE(int a) : T(a) { cout << "调用了EE的构造函数EE(int a)" << endl; }
};

void test()
{
    EE<AA> ea1;      // AA作为基类
    EE<BB> eb1;      // BB作为基类
    EE<DD<int>> ed1; // DD<int>作为基类
    // EE<DD> ed1;//DD作为基类,错误
}
int main()
{
    test();
    return 0;
}
/* 调用了AA的构造函数AA()
调用了EE的构造函数EE()
调用了BB的构造函数BB()
调用了EE的构造函数EE()
调用了DD的构造函数DD()
调用了EE的构造函数EE() */