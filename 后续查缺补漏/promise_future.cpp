#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std;

void testFuture(promise<string> p)
{
    this_thread::sleep_for(chrono::seconds(1));
    cout << "begin set value" << endl;
    p.set_value("hello world");
    this_thread::sleep_for(chrono::seconds(1));
    cout << "end set value" << endl;
}
void test()
{
    // 异步传输变量 存储
    promise<string> pStr;
    // 用来获取线程异步值
    auto future = pStr.get_future();

    thread t(testFuture, move(pStr));

    cout << "begin future get()" << endl;
    auto ret = future.get();
    cout << "future get() = " << ret << endl;
    cout << "end future get()" << endl;

    t.join();
}
int main()
{
    test();
    return 0;
}

/*
begin future get()
begin set value
future get() = hello world
end future get()
end set value
 */