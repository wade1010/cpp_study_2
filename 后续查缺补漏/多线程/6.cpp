#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
// 单例模式
mutex mtx;
once_flag o_flag;
class SingleCls
{
private:
    SingleCls() { cout << "call constructor" << endl; }
    static SingleCls *m_instance;

    static void createInstance()
    {
        m_instance = new SingleCls;
        static GC gc;
    }

public:
    // 方式一
    static SingleCls *GetInstance()
    {
        if (m_instance == nullptr) // 双重否定或者叫双重检查,提高性能,因为new一般就执行一次,所以不需要频繁的加锁
        {
            unique_lock<mutex> my_lock(mtx);
            if (m_instance == nullptr)
            {
                m_instance = new SingleCls;
                static GC gc;
            }
        }
        return m_instance;
    }
    // 方式二
    static SingleCls *GetInstance2()
    {
        if (m_instance == nullptr)
        {
            call_once(o_flag, createInstance);
        }
        return m_instance;
    }

    class GC // 类中类,用来释放对象
    {
    public:
        ~GC()
        {
            if (SingleCls::m_instance != nullptr)
            {
                delete SingleCls::m_instance;
                SingleCls::m_instance = nullptr;
            }
        }
    };
};

SingleCls *SingleCls::m_instance = nullptr;

void getSingle()
{
    SingleCls::GetInstance();
}
void getSingle2()
{
    SingleCls::GetInstance2();
}
int main()
{
    thread t1(getSingle2);
    thread t2(getSingle2);
    thread t3(getSingle2);
    thread t4(getSingle2);
    thread t5(getSingle2);
    thread t6(getSingle2);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    return 0;
}