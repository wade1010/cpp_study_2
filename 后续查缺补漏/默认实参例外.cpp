#include <iostream>
using namespace std;
// 默认实参
void f(int, int, int = 10);
void f(int, int = 6, int);
void f(int = 4, int, int);

void ff(int a, int b, int c)
{
    cout << a << ' ' << b << ' ' << c << endl;
}

/*
一般看到的规则都是说" 拥有默认实参的形参必须位于函数的右侧是最后一个形参或者旁边是默认实参? "
实际上这条规则很不严谨,代码如上,是可以执行的
原因:在函数声明中,所有在拥有默认实参的形参之后的形参必须拥有在这个或同一作用域中先前的声明中所提供的的默认实参.

你看觉得上面说的很绕,其实就是,你可以给任何形参默认实参,但是,你需要在当前作用域提前给你已经声明了默认实参的形参后面的形参默认实参.

比如下面的书序就是错误的

void f(int,int = 6 int);
void f(int, int, int = 10);
void f(int = 4, int, int);

因为第二个形参拥有了默认实参没有问题,但是在此之前,他后面的第三个形参必须也拥有默认实参才可以 ,只要调换以下位置,让它作为第一个函数声明,就错了.

另外还有例外情况,除非该形参是从某个形参包睁开得到的或是函数形参包,如下


template <class... Args>
struct A
{
    void func(int n = 0, Args... args)
    {
        std::cout << n << endl;
    }
};

template <class... Args>
void func(int n = 6, Args... args)
{
    std::cout << n << endl;
}

int main()
{
    func(1);
    func(1, 2);
    A<int>().func(11, 22);
    return 0;
}

 */