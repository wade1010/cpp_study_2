#include <iostream>
using namespace std;
struct AA
{
    void operator()(int a, const string &b)
    {
        cout << a << " " << b << endl;
    }
};

void test()
{
    AA aa;
    aa(1, "1"); //用对象调用仿函数

    AA()
    (2, "2"); //用匿名对象调用仿函数,这里换行是VSCODE格式化就这样,不报错

    AA &raa = aa; //引用函数
    raa(3, "3");  //用对象的引用调用仿函数
}
int main()
{
    test();
    return 0;
}