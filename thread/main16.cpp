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
    timed_mutex m_mutex;           //������
    condition_variable_any m_cond; //��������
    queue<string> m_q;             //�������
public:
    void incache(int num) //��������,numָ�����ݵĸ���
    {
        lock_guard<timed_mutex> lock(m_mutex);
        for (int i = 0; i < num; i++)
        {
            static int id = 1;
            string msg = to_string(id++) + "��ѡ��";
            m_q.push(msg); //�������������������
        }
        m_cond.notify_all(); //�������б���ǰ���������������߳�
    }

    void outcache() //�������߳�������
    {
        string msg;
        while (true)
        {
            {
                unique_lock<timed_mutex> lock(m_mutex);
                // while (m_q.empty())
                // {
                //     m_cond.wait(lock);
                //     cout << "�߳�:" << this_thread::get_id() << "��������" << endl;
                // }

                m_cond.wait(lock, [this]()
                            { return !m_q.empty(); }); //Ч��ͬ����while,������ص�wait��������Ҳ�и�whileѭ��

                //���ݳ���
                msg = m_q.front();
                m_q.pop();
                cout << "�߳�:" << this_thread::get_id() << "��������," << msg << endl;
            }
            this_thread::sleep_for(chrono::seconds(5));
        }
    }
};
void test()
{
    AA aa;
    //���̴߳��������ͨ��Ա����
    thread t1(&AA::outcache, &aa); //�����������߳�t1
    thread t2(&AA::outcache, &aa); //�����������߳�t2
    thread t3(&AA::outcache, &aa); //�����������߳�t3

    this_thread::sleep_for(chrono::seconds(2));
    aa.incache(3); //���ɵ��������������߳���3��

    t1.join();
    t2.join();
    t3.join();
}
int main()
{
    test();
    return 0;
}
