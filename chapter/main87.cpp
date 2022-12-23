#include "iostream"
using namespace std;
//约束模板友元:模板实例化时,每个实例化的类对应一个友元函数
//这种友元代码比较多,不用记住,用到的时候查查就行,但是它是最好的友元方案
template <typename T>
void show(T &a); //第一步:在模板类的定义前面,声明友元函数模板

template <class T1, class T2>
class AA
{
    friend void show<>(AA<T1, T2> &a); //第二步:在模板类中,再次声明友元函数模板
    T1 m_x;
    T2 m_y;

public:
    AA(const T1 x, const T2 y) : m_x(x), m_y(y) {}
};
template <typename T>
void show(T &a)
{
    cout << "通用:x=" << a.m_x << ",y=" << a.m_y << endl;
}
template <> //第三步:具体化版本
void show(AA<int, string> &a)
{
    cout << "具体AA<int,string>:x=" << a.m_x << ",y=" << a.m_y << endl;
}

//这种友元的函数模板可以用于多个模板类
template <class T1, class T2>
class BB
{
    friend void show<>(BB<T1, T2> &a); //第二步:在模板类中,再次声明友元函数模板
    T1 m_x;
    T2 m_y;

public:
    BB(const T1 x, const T2 y) : m_x(x), m_y(y) {}
};
template <> //第三步:具体化版本
void show(BB<int, string> &a)
{
    cout << "具体BB<int,string>:x=" << a.m_x << ",y=" << a.m_y << endl;
}

void test()
{
    AA<int, string> a(2, "hello");
    show(a);

    AA<char, string> b('a', "world");
    show(b);

    BB<int, string> ba(2, "hello");
    show(ba);

    BB<char, string> bb('a', "world");
    show(b);
}
int main()
{
    test();
    return 0;
}
/* 具体AA<int,string>:x=2,y=hello
通用:x=a,y=world
具体BB<int,string>:x=2,y=hello
通用:x=a,y=world */