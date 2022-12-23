#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <chrono>
#include <condition_variable>
using namespace std;
// condition_variable_any
class AA
{
    timed_mutex m_mutex;           //互斥锁
    condition_variable_any m_cond; //条件变量
    queue<string> m_q;             //缓存队列
public:
    void incache(int num) //生产数据,num指定数据的个数
    {
        lock_guard<timed_mutex> lock(m_mutex);
        for (int i = 0; i < num; i++)
        {
            static int id = 1;
            string msg = to_string(id++) + "号选手";
            m_q.push(msg); //把生产出来的数据入队
        }
        m_cond.notify_all(); //唤醒所有被当前条件变量阻塞的线程
    }

    void outcache() //消费者线程任务函数
    {
        string msg;
        while (true)
        {
            {
                unique_lock<timed_mutex> lock(m_mutex);
                // while (m_q.empty())
                // {
                //     m_cond.wait(lock);
                //     cout << "线程:" << this_thread::get_id() << "被唤醒了" << endl;
                // }

                m_cond.wait(lock, [this]()
                            { return !m_q.empty(); }); //效果同上面while,这个重载的wait函数里面也有个while循环

                //数据出队
                msg = m_q.front();
                m_q.pop();
                cout << "线程:" << this_thread::get_id() << "处理数据," << msg << endl;
            }
            this_thread::sleep_for(chrono::seconds(5));
        }
    }
};
void test()
{
    AA aa;
    //给线程传递类的普通成员函数
    thread t1(&AA::outcache, &aa); //创建消费者线程t1
    thread t2(&AA::outcache, &aa); //创建消费者线程t2
    thread t3(&AA::outcache, &aa); //创建消费者线程t3

    this_thread::sleep_for(chrono::seconds(2));
    aa.incache(3); //生成的数量比消费者线程数3少

    t1.join();
    t2.join();
    t3.join();
}
int main()
{
    test();
    return 0;
}
