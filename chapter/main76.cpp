#include "iostream"
using namespace std;

template <class T>
class Stack
{
private:
    T *items;
    int stacksize;
    int top;

public:
    Stack(int size = 3) : stacksize(size), top(0)
    {
        items = new T[stacksize];
    }
    ~Stack()
    {
        delete[] items;
        items = nullptr;
    }
    Stack &operator=(const Stack &tmp) //重载赋值运算符,实现深拷贝
    {
        if (this == &tmp)
        {
            return *this;
        }
        delete[] items;
        stacksize = tmp.stacksize;
        items = new T[stacksize];
        for (int i = 0; i < stacksize; i++)
        {
            items[i] = tmp.items[i];
        }
        top = tmp.top;
        return *this;
    }

    bool isempty() const { return top == 0; }
    bool isfull() const { return top == stacksize; }
    bool push(const T &item)
    {
        if (top < stacksize)
        {
            items[top++] = item;
            return true;
        }
        return false;
    }
    bool pop(T &item)
    {
        if (top > 0)
        {
            item = items[--top];
            return true;
        }
        return false;
    }
};

template <class T, int len = 10>
class Array
{
private:
    T item[len];

public:
    Array() {}
    ~Array() {}
    T &operator[](int index)
    {
        return item[index];
    }
    const T &operator[](int index) const
    {
        return item[index];
    }
};
template <class T>
class Vector
{
private:
    int len;
    T *items;

public:
    Vector(int size = 2) : len(size)
    {
        items = new T[len];
    }
    ~Vector()
    {
        delete[] items;
        items = nullptr;
    }
    void resize(int size)
    {
        if (size <= len)
        {
            return;
        }
        T *tmp = new T[size];
        for (int i = 0; i < len; i++)
        {
            //错误原因,如果这里复制的是内置数据类型,亏,但是如果复制的是类,且类中使用了堆区内存,就存在浅拷贝的问题
            tmp[i] = items[i];
        }
        len = size;
        delete[] items;
        items = tmp;
    }
    int size() const
    {
        return len;
    }
    T &operator[](int index)
    {
        if (index >= len)
        {
            resize(index + 1);
        }
        return items[index];
    }
    const &operator[](int index) const
    {
        return items[index];
    }
    Vector &operator=(const Vector &v) //重载赋值运算符,实现深拷贝
    {
        if (this == &v)
        {
            return *this;
        }
        delete[] items;
        len = v.len;
        items = new T[len];
        for (int i = 0; i < len; i++)
        {
            items[i] = v.items[i];
        }

        return *this;
    }
};

void test()
{
    /* Vector<Stack<string>> vs;
    Stack<string> vs1[2];
    string vs2[2][3];

    vs[0].push("啊1");
    vs[0].push("啊2");
    vs[0].push("啊3");

    vs[1].push("哦1");
    vs[1].push("哦2");
    vs[1].push("哦3");

    //不打开注释,程序能正常运行,打开注释,程序报错
    // vs[2].push("吧1");
    // vs[2].push("吧2");

    for (int i = 0; i < vs.size(); i++)
    {
        while (!vs[i].isempty())
        {
            string item;
            vs[i].pop(item);
            cout << "item=" << item << endl;
        }
    } */

    //创建Stack容器,容器中的元素用Vector<string>
    Stack<Vector<string>> sv;
    Vector<string> tmp;
    tmp[0] = "a1";
    tmp[1] = "a2";
    sv.push(tmp);

    tmp[0] = "b1";
    tmp[1] = "b2";
    sv.push(tmp);

    tmp[0] = "c1";
    tmp[1] = "c2";
    tmp[2] = "c3";
    tmp[3] = "c4";
    sv.push(tmp);
    cout << "--------------------" << endl;
    while (!sv.isempty())
    {
        sv.pop(tmp);
        for (int i = 0; i < tmp.size(); i++)
        {
            cout << "vs[" << i << "]=" << tmp[i] << endl;
        }
        cout << endl;
    }

    cout << "--------------------" << endl;
    //创建Vector容器,容器中的元素用Vector<string>
    Vector<Vector<string>> vv;
    vv[0][0] = "a1";
    vv[0][1] = "a2";
    vv[0][2] = "a3";
    vv[1][0] = "b1";
    vv[1][1] = "b2";
    vv[1][2] = "b3";
    vv[2][0] = "c1";
    vv[2][1] = "c2";
    vv[2][2] = "c3";
    vv[2][3] = "c4";
    for (int i = 0; i < vv.size(); i++)
    {
        for (int j = 0; j < vv[i].size(); j++)
        {
            cout << "vv[" << i << "][" << j << "]=" << vv[i][j] << endl;
        }
        cout << endl;
    }
}
int main()
{
    test();
    return 0;
}