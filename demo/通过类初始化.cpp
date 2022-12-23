#include <iostream>
#include <memory>
// 在main函数之前执行代码
class A
{
public:
    A() { std::cout << "构造" << __FUNCTION__ << std::endl; }
    ~A() { std::cout << "析构:" << __FUNCTION__ << std::endl; }
};

// A a; 或者 lambda表达式,但是lambada表达式需要注意 析构函数的调用

// 不会调用A的析构函数
// A *a = []
// {
//     return new A;
// }(); //()调用初始化

// 使用智能指针
std::unique_ptr<A> p = []
{
    return std::unique_ptr<A>(new A);
}();

int main(int argc, char const *argv[])
{
    std::cout << __FUNCTION__ << std::endl;
    return 0;
}
