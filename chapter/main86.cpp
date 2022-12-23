#include "iostream"
using namespace std;

//冗余的模板友元
template <class T1, class T2>
class AA
{
    T1 m_x;
    T2 m_y;

public:
    AA(const T1 x, const T2 y) : m_x(x), m_y(y)
    {
    }

    //下面的友元称为:非模板友元:友元函数不是模板函数,而是利用模板类参数生成的函数,只能在类内实现
    //下面这种方案的本质,是编译器利用模板参数帮我们生成了友元函数,使用起来很方便,但是有个细节
    //编译器利用模板参数生成的友元函数,但是这个函数不是模板函数
    //编译器创建模板类实例的时候,会用这些代码生成友元函数的实体,如果把下面注释的代码打开,就会出现冲突,导致报错
    friend void show(const AA<T1, T2> &a)
    {
        cout << a.m_x << endl;
        cout << a.m_y << endl;
    }
    // friend void show(const AA<int, string> &a);
    // friend void show(const AA<char, string> &a);
};

// void show(const AA<int, string> &a)
// {
//     cout << a.m_x << endl;
//     cout << a.m_y << endl;
// }

// void show(const AA<char, string> &a)
// {
//     cout << a.m_x << endl;
//     cout << a.m_y << endl;
// }

void test()
{
    AA<int, string> aa(1, "hello");
    show(aa);

    AA<char, string> bb('a', "hello");
    show(bb);
}
int main()
{
    test();
    return 0;
}