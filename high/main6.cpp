#include <iostream>
#include <vector>
using namespace std;

void test()
{
    vector<int> v = {1, 2, 3, 4, 5};
    auto it1 = v.begin();
    *it1 = 10;
    it1++;
    *it1 = 20;
    for (vector<int>::const_iterator it2 = v.cbegin(); it2 != v.end(); it2++)
        cout << *it2 << endl;

    vector<int> vv = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto it = vv.begin(); it != vv.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    //�û��ڷ�Χ��forѭ����������vv
    for (auto val : vv)
    {
        cout << val << " ";
    }
    cout << endl;

    int vv2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //�����õ�������,���ǻ��ڷ�Χ��forѭ����������
    for (auto val : vv2)
    {
        cout << val << " ";
    }
    cout << endl;
    //�ڶ�����Ҳ����ֱ����ͳһ��ʼ���б�
    for (auto val : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10})
    {
        cout << val << " ";
    }
    cout << endl;
}
int main()
{
    test();
    return 0;
}