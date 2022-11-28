#include <iostream>
#include <queue>
#include <deque>
#include <list>
using namespace std;
class girl
{
public:
    int m_bh;
    string m_name;
    girl(const int &bh, const string &name) : m_bh(bh), m_name(name) {}
};
void test()
{
    // template<class T,class _Container=deque<T>>
    // class queue{
    //  ......
    // }
    //��һ��ģ�����T:Ԫ�ص���������.
    // �ڶ���ģ�����_Container:�ײ�����������,���� ��std:deque,������std::list���������Զ������ģ��.

    queue<girl, list<girl>> q;    //����ṹΪ����
    queue<girl, deque<girl>> q2;  //����ṹΪ����.
    queue<girl> q3;               //����ṹΪ����
    queue<girl, vector<girl>> q4; //����ṹΪ����,!!!!!!��!!!��!��!��!!!��!��!!�������
                                  /*    q4.push(girl(1, "a"));
                                    q4.push(girl(2, "b"));
                                    q4.push(girl(3, "c"));
                                    while (!q4.empty())
                                    {
                                        cout << q4.front().m_bh << "  " << q4.front().m_name << endl;
                                        q4.pop();
                                    }
                                    error: 'class std::vector<girl>' has no member named 'pop_front'; did you mean 'front'?
                                   c.pop_front();
                                   ~~^~~~~~~~~
                                   front */

    q3.push(girl(1, "a"));
    q3.push(girl(2, "b"));
    q3.push(girl(3, "c"));
    while (!q3.empty())
    {
        cout << q3.front().m_bh << "  " << q3.front().m_name << endl;
        q3.pop();
    }
}
int main()
{
    test();
    return 0;
}
