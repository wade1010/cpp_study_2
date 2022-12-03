#include <iostream>
#include <atomic>
using namespace std;

void test()
{
    atomic<int> ii(3); // ԭ�ӱ���
    int expect = 3;    // �ڴ�ֵ
    // int expect = 4;    // �ڴ�ֵ
    int val = 5; // �������ԭ�ӱ�����ֵ
    // �Ƚ�ԭ�ӱ�����ֵ��Ԥ��ֵexpect��
    // ���������ֵ��ȣ���val�洢��ԭ�ӱ����У�
    // ���������ֵ����ȣ���ԭ�ӱ�����ֵ����Ԥ��ֵ��
    // ִ�д洢����ʱ����true�����򷵻�false��
    bool bret = ii.compare_exchange_strong(expect, val);
    cout << "bret=" << bret << endl;
    cout << "ii=" << ii << endl;
    cout << "expect=" << expect << endl;
}
int main()
{
    test();
    return 0;
}
//  int expect = 3;
/* bret=0
ii=3
expect=3 */

//  int expect = 4;
/* bret=1
ii=5
expect=3 */