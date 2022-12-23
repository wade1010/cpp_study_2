#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <chrono>
#include <condition_variable>
using namespace std;
class AA
{
    mutex m_mutex;             //������
    condition_variable m_cond; //��������
    queue<string> m_q;         //�������
public:
    void incache(int num) //��������,numָ�����ݵĸ���
    {
        lock_guard<mutex> lock(m_mutex);
        for (int i = 0; i < num; i++)
        {
            static int id = 1;
            string msg = to_string(id++) + "��ѡ��";
            m_q.push(msg); //�������������������
        }
        m_cond.notify_one(); //����һ������ǰ���������������߳�
    }

    void outcache() //�������߳�������
    {
        string msg;
        while (true)
        {
            //��һ��������,��������  unique_lock�Զ��ͷ���
            {
                //�ѻ�����ת����unique_lock<mutex>,���������
                unique_lock<mutex> lock(m_mutex);
                //������п�,����ѭ��,�����ֽڴ�������,������ѭ��,������if
                while (m_q.empty())
                {
                    m_cond.wait(lock);
                }

                //���ݳ���
                msg = m_q.front();
                m_q.pop();
            }

            //������ӵ�����
            cout << "���������Ϊ:" << msg << endl;
            this_thread::sleep_for(chrono::milliseconds(1)); //���账��������Ҫ����1����
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
    aa.incache(3);

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
/* ���������Ϊ:1��ѡ��
���������Ϊ:2��ѡ��
���������Ϊ:3��ѡ��
���������Ϊ:4��ѡ��
���������Ϊ:5��ѡ��
���������Ϊ:6��ѡ��
���������Ϊ:7��ѡ��
���������Ϊ:8��ѡ�� */