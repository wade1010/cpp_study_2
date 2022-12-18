#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx;

class SingleCls
{
private:
    SingleCls() { cout << "call constructor" << endl; }
    static SingleCls *m_instance;

public:
    static SingleCls *GetInstance()
    {
        // c++11之前可以用下面代码加锁
        // unique_lock<mutex> my_lock(mtx);
        // c++11这种写法是安全的,不用加锁,由static保证
        if (m_instance == nullptr)
        {
            m_instance = new SingleCls;
            static GC gc;
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
int main()
{
    thread t1(getSingle);
    thread t2(getSingle);
    t1.join();
    t2.join();
    return 0;
}