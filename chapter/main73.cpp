#include "iostream"
using namespace std;
//模板类的实例-栈 简单实现
template <class T>
class Stack
{
private:
    T *m_items; //栈数组
    int m_size;
    int m_top;

public:
    Stack(int size) : m_size(size), m_top(0)
    {
        m_items = new T[m_size];
    }
    ~Stack()
    {
        delete[] m_items;
        m_items = nullptr;
    }
    bool isempty() const
    {
        return m_top == 0;
    }
    bool isfull() const
    {
        return m_top == m_size;
    }
    bool push(const T &item)
    {
        if (isfull())
        {
            return false;
        }
        m_items[m_top++] = item;
        return true;
    }
    bool pop(T &item)
    {
        if (isempty())
        {
            return false;
        }
        item = m_items[--m_top];
        return true;
    }
};
void test()
{
    Stack<string> s(4);
    //入栈
    s.push("a");
    s.push("b");
    s.push("c");
    s.push("d");
    s.push("e"); //这个入栈失败的
    //出栈
    string item;
    while (!s.isempty())
    {
        s.pop(item);
        cout << "item=" << item << endl;
    }
}
int main()
{
    test();
    return 0;
}