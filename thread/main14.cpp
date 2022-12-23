#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <chrono>
#include <condition_variable>
using namespace std;
//
class AA
{
    mutex m_mutex;             //互斥锁
    condition_variable m_cond; //条件变量
    queue<string> m_q;         //缓存队列
public:
    void incache(int num) //生产数据,num指定数据的个数
    {
        lock_guard<mutex> lock(m_mutex);
        for (int i = 0; i < num; i++)
        {
            static int id = 1;
            string msg = to_string(id++) + "号选手";
            m_q.push(msg); //把生产出来的数据入队
        }
        // m_cond.notify_one(); //唤醒一个被当前条件变量阻塞的线程
        m_cond.notify_all(); //唤醒所有被当前条件变量阻塞的线程
    }

    void outcache() //消费者线程任务函数
    {
        string msg;
        while (true)
        {
            //加一个作用域,出作用域  unique_lock自动释放锁. 不加作用域也行,可以手动释放锁
            {
                //把互斥锁转换成unique_lock<mutex>,并申请加锁
                cout << "线程:" << this_thread::get_id() << ",申请加锁..." << endl;
                unique_lock<mutex> lock(m_mutex);
                cout << "线程:" << this_thread::get_id() << ",加锁成功" << endl;
                //如果队列空,进入循环,否则字节处理数据,必须用循环,不能用if
                while (m_q.empty())
                {
                    cout << "进入休眠" << endl;
                    m_cond.wait(lock);
                }

                //数据出队
                msg = m_q.front();
                m_q.pop();
                cout << "线程:" << this_thread::get_id() << "处理数据," << msg << endl;
            }

            //处理出队的数据
            this_thread::sleep_for(chrono::milliseconds(1)); //假设处理数据需要消耗1毫秒
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

    t1.join();
    t2.join();
    t3.join();
}
int main()
{
    test();
    return 0;
}

/* 线程:4,申请加锁...
线程:4,加锁成功
进入休眠
线程:3,申请加锁...
线程:3,加锁成功
进入休眠
线程:2,申请加锁...
线程:2,加锁成功
进入休眠 */