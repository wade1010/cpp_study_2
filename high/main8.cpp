#include <iostream>
#include <list>
using namespace std;

void test()
{
    list<int> l;
    cout << l.size() << endl;

    list<int> l2({1, 2, 3, 4, 5, 6});
    // list<int> l2 = {1, 2, 3, 4, 5, 6};
    // list<int> l2{1, 2, 3, 4, 5, 6};
    for (int val : l2)
    {
        cout << val << " ";
    }
    cout << endl;

    //创建数组  数组的指针是天然的随机访问迭代器
    int a1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> l3(a1 + 2, a1 + 5);
    for (auto val : l3)
    {
        cout << val << " ";
    }
    cout << endl;
    //上面这个例子可以看出,迭代器是个好东西,没有迭代器,不同容器之间转换,还比较麻烦

    char str[] = "hello world";  //定义C风格字符串
    string s1(str + 1, str + 7); //用C风格字符串创建string容器
    for (auto val : s1)
    {
        cout << val << " ";
    }
    cout << endl;
    cout << s1 << endl;
}
int main()
{
    test();
    return 0;
}