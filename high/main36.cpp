#include <iostream>
using namespace std;
typedef char *pstring;
void test()
{
    char c = 'C';
    const pstring cstr = &c;
    char b = 'B';

    //����1 �޸�ָ���ֵ
    *cstr = 'B';

    //����2 �޸�ָ��
    // cstr = &b; //��������
    /* main.cpp:9:13: error: assignment of read-only variable 'cstr'
     cstr = &b; */

    //  ͨ�����Կ��Եó�,const pstring�ǳ���ָ��
}
int main()
{
    test();
    return 0;
}