#include <iostream>
using namespace std;
//��ֵ ��ֵ
class AA
{
};
AA getTemp()
{
    return AA();
}

AA &getTemp2(AA &a)
{
    return a;
}
void test()
{
    int i = 3;          // i����ֵ,3����ֵ
    int j = i + 3;      // j����ֵ,i+8����ֵ
    AA a = getTemp();   // a����ֵ,getTemp()�ķ���ֵ����ֵ(��ʱ����)
    AA b = getTemp2(a); // b����ֵ,getTemp2(a)�ķ���ֵ������,����ֵ.
    AA c;
    getTemp2(a) = c;
}
int main()
{
    test();
    return 0;
}