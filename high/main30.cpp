#include <iostream>
using namespace std;
//��ֵ ��ֵ
class AA
{
public:
    string m_a;
};
AA getTemp()
{
    return AA();
}

void test()
{
    int &&a = 3;
    int b = 78;
    int &&c = b + 1;
    // int &&d = c; //����,��Ϊ��ֵ��������֮��ͳ�����ֵ,�����ٶ���ֵ������ֵ����,����
    int &d = c; //��ȷ

    AA &&aa = getTemp();
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << aa.m_a << endl;

    //������ֵ����
    int aaa = 1;
    int &bbb1 = aaa;
    const int &bbb2 = aaa;

    const int &bbb3 = 1;
    int &&ccc = 1;
}
int main()
{
    test();
    return 0;
}