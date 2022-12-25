#include <iostream>
#include <future>
#include <thread>
using namespace std;
void mythread(std::promise<int> &p, int x)
{
    x++;
    x *= 10;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    p.set_value(x);
    cout << "thread id=" << this_thread::get_id() << endl;
}

void mythread2(std::future<int> &myFuture)
{
    cout << "mythread2 result:" << myFuture.get() << endl;
    cout << "thread id=" << this_thread::get_id() << endl;
}

int main()
{
    /*
    std::promise,类模板
    我们能够在某个线程中给它赋值,然后能在其它线程中把这个值取出来用

    总结:通过promise保存一个值,在将来某个时刻我们通过把一个future绑定到这个promise上,来得到这个绑定的值;

     */

    std::promise<int> myPromise;
    std::thread t1(mythread, std::ref(myPromise), 22);
    t1.join();
    // 获取结果
    std::future<int> myFuture = myPromise.get_future(); // promise和future绑定,用于获取线程返回值
    cout << myFuture.get() << endl;                     // get只能调用一次

    // 传给另外一个线程
    std::thread t2(mythread2, std::ref(myFuture));
    t2.join();

    return 0;
}
