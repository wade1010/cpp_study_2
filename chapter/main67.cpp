#include "iostream"
using namespace std;
class AA
{
};
void test()
{
    // typeid����������������
    int num = 3;
    int *pi = &num;
    int &ri = num;
    cout << "typeid(int)=" << typeid(int).name() << endl;
    cout << "typeid(num)=" << typeid(num).name() << endl;
    cout << "typeid(int *)=" << typeid(int *).name() << endl;
    cout << "typeid(pi)=" << typeid(pi).name() << endl;
    cout << "typeid(int &)=" << typeid(int &).name() << endl;
    cout << "typeid(ri)=" << typeid(ri).name() << endl;

    // typeid�����Զ�����������
    AA aa;
    AA *paa = &aa;
    AA &raa = aa;
    cout << "typeid(AA)=" << typeid(AA).name() << endl;
    cout << "typeid(aa)=" << typeid(aa).name() << endl;
    cout << "typeid(AA *)=" << typeid(AA *).name() << endl;
    cout << "typeid(paa)=" << typeid(paa).name() << endl;
    cout << "typeid(AA &)=" << typeid(AA &).name() << endl;
    cout << "typeid(raa)=" << typeid(raa).name() << endl;

    // type_info ������==��!=����������ڶ����ͽ��бȽ�
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