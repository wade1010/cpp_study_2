#include "iostream"
using namespace std;
//模板类的实例-数组 简单实现  变长数组
template <class T>
class Vector
{
private:
    int len;
    T *items;

public:
    Vector(int size = 10) : len(size)
    {
        items = new T[len];
    }
    ~Vector()
    {
        delete[] items;
    }
    void resize(int size)
    {
        if (size <= len)
        {
            return; //这里就规定只能往大的扩
        }
        T *tmp = new T[size];         //分配更大的内存空间
        for (int i = 0; i < len; i++) //把原来数组中的元素复制到新数组
        {
            tmp[i] = items[i];
        }
        delete[] items; //释放原来的数组
        items = tmp;    //让数组指针指向新数组
        len = size;
    }
    int size()
    {
        return len;
    }
    T &operator[](int index)
    {
        if (index >= len)
        {
            resize(index + 1); //这里会频繁扩展,暂不管,可以每次扩的多点.改成10或者20
        }

        return items[index];
    }
    const T &operator[](int index) const
    {
        return items[index];
    }
};
void test()
{
    Vector<string> v(1);
    v[0] = "啊";
    v[1] = "飞啊";
    v[2] = "啊改变";
    for (int i = 0; i < 3; i++)
    {
        cout << v[i] << endl;
    }

    Vector<int> v2(1);
    v2[0] = 1;
    v2[1] = 2;
    v2[2] = 3;
    for (int i = 0; i < 3; i++)
    {
        cout << v2[i] << endl;
    }
}
int main()
{
    test();
    return 0;
}