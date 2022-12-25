#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std;

int mythread()
{
    cout << "mythread thread id = " << this_thread::get_id() << endl;
    return 111;
}

int main()
{
    cout << "main thread id = " << this_thread::get_id() << endl;
    std::future<int> result = std::async(mythread);
    std::future_status status = result.wait_for(chrono::seconds(1));
    if (status == std::future_status::deferred)
    {
        // 线程被延迟执行了(系统资源紧张了,系统给我采用了std::launch::deferred策略)
        cout << result.get() << endl;
    }
    else
    {
        // 任务没有被推迟,已经开始运行了,线程被创建
        if (status == std::future_status::ready)
        {
            cout << "线程成功执行完毕并返回" << endl;
            cout << result.get() << endl;
        }
        else if (status == std::future_status::timeout)
        {
            cout << "超时线程没执行完" << endl;
            cout << result.get() << endl;
        }
    }

    return 0;
}