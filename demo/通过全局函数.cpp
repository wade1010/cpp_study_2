#include <iostream>
// 在main函数之前执行代码
int func()
{
    std::cout << __FUNCTION__ << std::endl;
    return 1;
}

int a = func();

int main(int argc, char const *argv[])
{
    std::cout << __FUNCTION__ << std::endl;
    return 0;
}
