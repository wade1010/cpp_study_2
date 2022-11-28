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

    //��������  �����ָ������Ȼ��������ʵ�����
    int a1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> l3(a1 + 2, a1 + 5);
    for (auto val : l3)
    {
        cout << val << " ";
    }
    cout << endl;
    //����������ӿ��Կ���,�������Ǹ��ö���,û�е�����,��ͬ����֮��ת��,���Ƚ��鷳

    char str[] = "hello world";  //����C����ַ���
    string s1(str + 1, str + 7); //��C����ַ�������string����
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