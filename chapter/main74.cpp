#include "iostream"
#include <cstring>
using namespace std;
// #define MAXLEN 10
//模板类的实例-数组 简单实现  定长数组
// template <class T>
// template <class T, int len=10> //也可以用缺省值
template <class T, int len>
class Array
{
private:
    // T items[MAXLEN];
    T items[len];

public:
    Array()
    {
        memset(items, 0, sizeof(items));
    }
    ~Array() {}
    //重载操作符[],可以修改数组中的元素
    T &operator[](int index)
    {
        return items[index];
    }
    //重载操作符[],不可以修改数组中的元素
    const T &operator[](int index) const
    {
        return items[index];
    }
};
void test()
{
    /*     Array<int> a;
        a[0] = 1;
        a[1] = 2;
        a[2] = 3;
        a[3] = 4;
        a[4] = 5;
        for (int i = 0; i < 5; i++)
        {
            cout << a[i] << endl;
        } */

    /*  Array<string> a;
     a[0] = "啊";
     a[1] = "安大叔大婶抚";
     a[2] = "把";
     a[3] = "报错";
     a[4] = "二";
     for (int i = 0; i < 5; i++)
     {
         cout <<a[i] << endl;
     } */

    //不用宏,使用非通用类型的参数
    //如果用缺省值 template <class T, int len=10>
    // Array<string> a;
    Array<string, 3> a;
    a[0] = "啊";
    a[1] = "安大叔大婶抚";
    a[2] = "把";
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << endl;
    }
}
int main()
{
    test();
    return 0;
}