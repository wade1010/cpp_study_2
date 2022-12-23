#include <iostream>
#include <future>
#include <thread>
#include <vector>
using namespace std;

int mythread(int a)
{
    cout << a << endl;
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

vector<packaged_task<int(int)>> mytasks;

int main()
{
    /*
    std::packaged_task:打包任务,把任务包装起来
    是个类模板,它的模板参数是  各种可调用对象;通过std::packaged_task来把各种可调用对象包装起来,方便将来作为线程入口函数来调用
    packaged_task包装起来的可调用对象还可以直接调用,所以这个角度来讲,packaged_task对象,也是一个可调用对象
     */
    cout << "main start,thread id:" << this_thread::get_id() << endl;
    // std::packaged_task<int(int)> mypt(mythread); // 我们把函数mythread通过packaged_task包装起来

    std::packaged_task<int(int)> mypt([](int a)
                                      {
          cout << a << endl;
    cout << "mythread() start,thread id=" << this_thread::get_id() << endl;
    this_thread::sleep_for(chrono::milliseconds(5000));
    cout << "mythread() end,thread id=" << this_thread::get_id() << endl;
    return 5; });

    std::thread t1(std::ref(mypt), 1); // 1是线程入口函数的参数
    t1.join();
    std::future<int> result = mypt.get_future();
    cout << result.get() << endl;

    // packaged_task包装起来的可调用对象还可以直接调用,所以这个角度来讲,packaged_task对象,也是一个可调用对象
    std::packaged_task<int(int)> mypt2(mythread);
    mypt2(2); // 直接调用,相当于函数调用,不会创建子线程,直接在主线程中执行
    std::future<int> result2 = mypt2.get_future();
    cout << result2.get() << endl;

    std::packaged_task<int(int)> mypt3(mythread);
    mytasks.push_back(std::move(mypt3));
    std::packaged_task<int(int)> mypt4;
    auto iter = mytasks.begin();
    mypt4 = std::move(*iter); // 移动语义
    mytasks.erase(iter);      // 删除第一个元素,迭代已经失效了,所以后续代码不可以再使用iter了
    mypt4(1111);
    std::future<int> result3 = mypt4.get_future();
    cout << result3.get() << endl;

    return 0;
}
