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
        // m_cond.notify_one(); //����һ������ǰ���������������߳�
        m_cond.notify_all(); //�������б���ǰ���������������߳�
    }

    void outcache() //�������߳�������
    {
        string msg;
        while (true)
        {
            //��һ��������,��������  unique_lock�Զ��ͷ���. ����������Ҳ��,�����ֶ��ͷ���
            {
                //�ѻ�����ת����unique_lock<mutex>,���������
                cout << "�߳�:" << this_thread::get_id() << ",�������..." << endl;
                unique_lock<mutex> lock(m_mutex);
                cout << "�߳�:" << this_thread::get_id() << ",�����ɹ�" << endl;
                //������п�,����ѭ��,�����ֽڴ�������,������ѭ��,������if
                while (m_q.empty())
                {
                    cout << "��������" << endl;
                    m_cond.wait(lock);
                }

                //���ݳ���
                msg = m_q.front();
                m_q.pop();
                cout << "�߳�:" << this_thread::get_id() << "��������," << msg << endl;
            }

            //������ӵ�����
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

    t1.join();
    t2.join();
    t3.join();
}
int main()
{
    test();
    return 0;
}

/* �߳�:4,�������...
�߳�:4,�����ɹ�
��������
�߳�:3,�������...
�߳�:3,�����ɹ�
��������
�߳�:2,�������...
�߳�:2,�����ɹ�
�������� */