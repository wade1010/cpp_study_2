#include "iostream"
using namespace std;
class AA
{
};
void test()
{
    // typeid用于内置数据类型
    int num = 3;
    int *pi = &num;
    int &ri = num;
    cout << "typeid(int)=" << typeid(int).name() << endl;
    cout << "typeid(num)=" << typeid(num).name() << endl;
    cout << "typeid(int *)=" << typeid(int *).name() << endl;
    cout << "typeid(pi)=" << typeid(pi).name() << endl;
    cout << "typeid(int &)=" << typeid(int &).name() << endl;
    cout << "typeid(ri)=" << typeid(ri).name() << endl;

    // typeid用于自定义数据类型
    AA aa;
    AA *paa = &aa;
    AA &raa = aa;
    cout << "typeid(AA)=" << typeid(AA).name() << endl;
    cout << "typeid(aa)=" << typeid(aa).name() << endl;
    cout << "typeid(AA *)=" << typeid(AA *).name() << endl;
    cout << "typeid(paa)=" << typeid(paa).name() << endl;
    cout << "typeid(AA &)=" << typeid(AA &).name() << endl;
    cout << "typeid(raa)=" << typeid(raa).name() << endl;

    // type_info 重载了==和!=运算符，用于对类型进行比较
    if (typeid(AA) == typeid(aa))
    {
        cout << "ok1" << endl;
    }
}
int main()
{
    test();
    return 0;
}