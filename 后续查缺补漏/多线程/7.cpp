#include <iostream>
#include <future>
#include <thread>
using namespace std;

int mythread()
{
    cout << "mythread() start,thread id=" << this_thread::get_id() << endl;
    this_thread::sleep_for(chrono::milliseconds(5000));
    cout << "mythread() end,thread id=" << this_thread::get_id() << endl;
    return 5;
}

class A
{
public:
    int mythread(int a)
    {
        cout << "A::mythread() start,thread id=" << this_thread::get_id() << endl;
        this_thread::sleep_for(chrono::milliseconds(5000));
        cout << "A::mythread() end,thread id=" << this_thread::get_id() << endl;
        return a;
    }
};

int main()
{
    /*

    一、std::async、std::future创建后台任务并返回值
希望线程返回一个结果
std::async是个函数模板，用来启动一个异步任务，启动起来一个异步任务之后，它返回一个std::future对象，std::future是个类模板。

什么叫“启动一个异步任务”，就是自动创建一个线程并开始执行对应的线程入口函数，它返回一个std::future对象，
这个std::future对象里边就含有线程入口函数所返回的结果（线程返回的结果），我们可以通过调用future对象的成员函数get()获取结果。

future：将来的意思，有人也称呼std::future提供了一种访问异步操作结果的机制，也就是说这个结果你可能没办法马上拿到，但不久的将来，线程执行完毕的时候，你就能够拿到了结果，所以大家就这么理解：这个future（对象）里会保存一个值，在将来某个时刻能够拿到。


下面程序通过std::future对象的get()成员函数等待线程执行结束并返回结果
这个get()函数不拿到将来的返回值,就卡在这里等待返回值

我们通过额外像std::async()传递一个参数,该参数类型时std::launch类型(枚举类型),来达到 一些特殊目的;
a) std::launch::deferred:表示线程入口函数调用被延迟到std::future的wait()或者get()函数调用时才执行;
    如果wait()或者get()没有被调用,那么线程会执行吗?
    没有执行,实际上,线程根本没有创建
std::launch::deferred:延迟调用,并且没有创建新线程,是在主线程中调用的线程入口函数(可以通过打印出来的线程id发现)

b) std::launch::async:在调用async函数的时候就开始创建线程;
    //async()函数,默认用的就是std::launch::async|std::launch::deferred,系统会执行决定是异步还是同步方式去运行
     */

    cout << "main start,thread id" << this_thread::get_id() << endl;

    // 调用普通全局函数
    // future<int> result = async(mythread); // 后面即使不调用result.get()或者result.wait(),主线程退出前,都会等待该线程执行完成(若从std::async获得的std::future未被移动或绑定到引用,则在完整表达式结尾,std::future的析构函数将阻塞,直至异步计算完成)
    // 调用普通成员函数
    A a;
    // future<int> result = async(&A::mythread, a, 1);
    future<int> result = async(std::launch::async, &A::mythread, a, 1);
    cout << "continue....." << endl;
    int def;
    def = 0;
    cout << result.get() << endl; // 在这等待async线程执行完成,返回结果,而且get()只能调用一次,调用多次会报异常
    // result.wait();                // 等待线程返回,本身并不返回结果
    cout << "main end" << endl;

    return 0;
}
