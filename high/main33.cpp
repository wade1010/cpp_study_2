#include <iostream>
using namespace std;
//完美转发
void func1(int &i)
{
    cout << "参数是左值=" << i << endl;
}
void func1(int &&i)
{
    cout << "参数是右值=" << i << endl;
}
void func2(int i)
{
    func1(i);
}
void func3(int &&i)
{
    func1(i);
}
void func3(int &i)
{
    func1(i);
}

void func4(int &&i)
{
    func1(move(i));
}
void func4(int &i)
{
    func1(i);
}

template <typename T>
void func5(T &&i)
{
    func1(move(i));
}
template <typename T>
void func5(T &i)
{
    func1(i);
}

template <typename T>
void func6(T &&i)
{
    func1(forward<T>(i));
}

void func7(int &&i)
{
    func1(forward<int>(i));
}

void test()
{
    int i = 3;
    func1(i);
    func1(33);
    /* 参数是左值=3
    参数是右值=33  */
    //上面代码调用,不会出现问题,但是如果不是字节调用,中间由其它函数中专,那中专的函数该怎么写呢?

    func2(i);
    func2(33);
    /* 参数是左值=3
参数是左值=33 */
    //上面代码输出结果可以看出,不是我们想要的,我们想要的是:func2()把参数传给func1()的时候,也要有左值和右值之分
    //如果参数在传递的过程中不能保持左/右值的属性,那就不能实现移动语义了.
    func3(i);
    func3(33);
    /*参数是左值=3
参数是左值=33  */
    //上面代码也不是我们想要的

    func4(i);
    func4(33);
    /*参数是左值=3
参数是右值=33 */
    //上面代码是我们想要的,但是该方法不是最好的,类似的还有下面的，改成两个模板

    func5(i);
    func5(33);
    /*参数是左值=3
参数是右值=33 */
    cout << "------------------" << endl;
    //使用最佳,C++11提供完美语义
    func6(i);
    func6(33);
}
int main()
{
    test();
    return 0;
}
/* 参数是左值=3
参数是右值=33
参数是左值=3
参数是左值=33
参数是左值=3
参数是左值=33
参数是左值=3
参数是右值=33
参数是左值=3
参数是右值=33
------------------
参数是左值=3
参数是右值=33 */