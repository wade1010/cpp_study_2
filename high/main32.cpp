#include <iostream>
#include <cstring>
using namespace std;
// 移动语义
class AA
{
public:
    int *m_data = nullptr;
    AA() = default;
    void alloc()
    {
        m_data = new int;
        memset(m_data, 0, sizeof(int));
    }

    AA(const AA &a)
    {
        cout << "调用了拷贝构造函数" << endl;
        if (this == &a)
        {
            return;
        }
        if (m_data == nullptr)
        {
            alloc();
        }
        memcpy(m_data, a.m_data, sizeof(int)); //把数据从源对象中拷贝过来
    }
    //移动构造函数
    AA(AA &&a) //因为需要操作被转移对象中的指针,所以不能用const
    {
        cout << "调用了移动构造函数" << endl;
        if (m_data != nullptr)
        {
            delete m_data; //如果已经分配内存,先释放掉
        }
        m_data = a.m_data;  //把资源从源对象中转移过来
        a.m_data = nullptr; //把源对象中的指针置空
    }
    AA &operator=(const AA &a)
    {
        cout << "调用了赋值函数" << endl;
        if (this == &a)
        {
            return *this;
        }
        if (m_data == nullptr)
        {
            alloc();
        }
        memcpy(m_data, a.m_data, sizeof(int));
        return *this;
    }

    //移动赋值函数
    AA &operator=(AA &&a)
    {
        cout << "调用了移动赋值函数" << endl;
        if (this == &a)
        {
            return *this;
        }
        if (m_data != nullptr)
        {
            delete m_data;
        }
        m_data = a.m_data;
        a.m_data = nullptr;
        return *this;
    }
    ~AA()
    {
        cout << "调用了析构函数" << endl;
        if (m_data != nullptr)
        {
            delete m_data;
            m_data = nullptr;
        }
    }
};
AA func()
{
    AA a;
    a.alloc();
    *a.m_data = 19;
    return a;
}
void test()
{
    AA a1;
    a1.alloc();
    *a1.m_data = 3;
    cout << "a1.m_data=" << *a1.m_data << endl;

    AA a2 = a1;
    cout << "a2.m_data=" << *a2.m_data << endl;

    AA a3;
    a3 = move(a1); //调用了移动赋值函数 但是注意不能move多次,且move后,后面使用就要注意空指针了
    // a3 = a1;       //调用了赋值函数
    cout << "a3.m_data=" << *a3.m_data << endl;
}
int main()
{
    test();
    return 0;
}
/* a1.m_data=3
调用了拷贝构造函数
a2.m_data=3
调用了移动赋值函数
a3.m_data=3
调用了析构函数
调用了析构函数
调用了析构函数 */