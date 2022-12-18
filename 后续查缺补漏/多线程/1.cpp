#include <iostream>
#include <thread>
using namespace std;

// void myprint(const int &argi, char *pch)
// void myprint(const int argi, char *pch)
void myprint(const int argi, const string &pch) // 发生隐式转换
{
    cout << argi << endl; // 分析认为:argi并不是外部i的引用,实际是值传递,则认为即使th执行了detach,那么子线程中用i值仍然是安全的
    // cout << pch << endl;  // 指针在detach子线程时,绝对是会有问题的
    cout << pch.c_str() << endl; // 指针在detach子线程时,绝对是会有问题的
}

int main()
{
    // 一: 创建临时对象作为线程参数
    //(1.1)要避免的陷阱(解释1)
    int i = 1;
    int &ri = i;
    char ch[] = "hello world";
    // 因为是引用 i和&ri的地址是一样的
    thread th(myprint, ri, ch); // 形参是指针 数组名也是指针,指向同一地址
    // th.join();
    th.detach(); // 使用detach的时候,不推荐用引用,绝对不能用指针
    cout << "end main" << endl;
    return 0;
}
/*
上面代码运行时正常的,看似没有问题,
但是传参的时候,ch到底是什么时候转成string的,
如果main函数执行完,你再转成string,那也就是有问题的,因为这时候ch已经被系统回收了,再转的结果就是不可预料

事实上存在,ch都被回收了(main函数执行完了),系统才用ch去转string的可能性

经过查资料,最终应该改成
thread th(myprint, ri, string(ch));//临时构造一个string对象作为实参传递,不用发生隐式转换


那么如何确定string(ch)确实是在main函数结束前执行的呢?
下面通过一个自定义类来验证
  */