#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <chrono>
#include <condition_variable>
#include <functional>
using namespace std;

void show(const string &msg)
{
    cout << "普通函数处理数据:" << msg << endl;
}
struct BB
{
    void show(const string &msg)
    {
        cout << "类成员函数处理数据:" << msg << endl;
    }
};

class AA
{
    mutex m_mutex;
    condition_variable m_cond;
    queue<string> m_q;
    function<void(const string &)> m_callback; //回调函数对象

public:
    template <typename Fn, typename... Args>
    void callback(Fn &&fn, Args &&...args) //可变参数,主要是为了适配类的普通成员函数
    {
        m_callback = bind(forward<Fn>(fn), forward<Args>(args)..., placeholders::_1);
    }
    void incache(int num)
    {
        lock_guard<mutex> lock(m_mutex);
        for (int i = 0; i < num; i++)
        {
            static int id = 1;
            string msg = to_string(id++) + "号选手";
            m_q.push(msg);
        }
        m_cond.notify_all();
    }
    void outcache()
    {
        while (true)
        {
            unique_lock<mutex> lock(m_mutex);
            m_cond.wait(lock, [this]
                        { return !m_q.empty(); });

            string msg = m_q.front();
            m_q.pop();
            cout << "线程:" << this_thread::get_id() << "," << msg << endl;
            lock.unlock();
            if (m_callback)
                m_callback(msg);
        }
    }
};

void test()
{
    AA aa;
    // aa.callback(show);
    BB bb;
    aa.callback(&BB::show, &bb);

    thread t1(&AA::outcache, &aa);
    thread t2(&AA::outcache, &aa);
    thread t3(&AA::outcache, &aa);

    this_thread::sleep_for(chrono::seconds(2));
    aa.incache(2);

    this_thread::sleep_for(chrono::seconds(3));
    aa.incache(5);

    t1.join();
    t2.join();
    t3.join();
}
int main()
{
    test();
    return 0;
}