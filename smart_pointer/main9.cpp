#include <iostream>
#include <memory>
using namespace std;
//使用weak_ptr解决循环依赖
class BB;
class AA
{
public:
    string m_name;
    AA() { cout << "调用构造函数AA()" << endl; }
    AA(const string &name) : m_name(name)
    {
        cout << "调用构造函数AA(const string &name)" << endl;
    }
    ~AA()
    {
        cout << "调用AA析构函数" << endl;
    }
    weak_ptr<BB> sp;
};

class BB
{
public:
    string m_name;
    BB() { cout << "调用构造函数BB()" << endl; }
    BB(const string &name) : m_name(name)
    {
        cout << "调用构造函数BB(const string &name)" << endl;
    }
    ~BB()
    {
        cout << "调用BB析构函数" << endl;
    }
    weak_ptr<AA> sp;
};
void test()
{
    //问题开始  下面这段代码线程不安全
    /* {

        shared_ptr<AA> spa = make_shared<AA>("a1");
        {
            shared_ptr<BB> spb = make_shared<BB>("b1");
            spa->sp = spb;
            spb->sp = spa;

            //下面的if else 如果执行expired==true再执行lock 这两步不是原子操作,
            //资源可能在这两个步骤之间已经被其它线程释放
            if (spa->sp.expired() == true)
            {
                cout << "语句块内部:spa->sp已经过期" << endl;
            }
            else
            {
                cout << "语句块内部:spa->sp.lock()->m_name=" << spa->sp.lock()->m_name << endl;
            }
        }
        if (spa->sp.expired() == true)
        {
            cout << "语句块外部:spa->sp已过期" << endl;
        }
        else
        {
            cout << "语句块外部:spa->sp.lock()->m_name=" << spa->sp.lock()->m_name << endl;
        }
    } */
    //问题结束

    //正确开始
    {
        shared_ptr<AA> spa = make_shared<AA>("a1");
        {
            shared_ptr<BB> spb = make_shared<BB>("b1");
            spa->sp = spb;
            spb->sp = spa;

            //把weak_ptr提升为shared_ptr
            shared_ptr<BB> tmp = spa->sp.lock();
            if (tmp == nullptr)
            {
                cout << "语句块内部:spa->sp已经过期" << endl;
            }
            else
            {
                cout << "语句块内部:spa->sp.lock()->m_name=" << tmp->m_name << endl;
            }
        }

        shared_ptr<BB> tmp = spa->sp.lock();
        if (tmp == nullptr)
        {
            cout << "语句块外部:spa->sp已过期" << endl;
        }
        else
        {
            cout << "语句块外部:spa->sp.lock()->m_name=" << tmp->m_name << endl;
        }
    }
    //正确结束
}
int main()
{
    test();
    return 0;
}
/*
调用构造函数AA(const string &name)
调用构造函数BB(const string &name)
语句块内部:spa->sp.lock()->m_name=b1
调用BB析构函数
语句块外部:spa->sp已过期
调用AA析构函数  */