#include <iostream>
using namespace std;
//����ָ��ͺ�������
void print(int a);
void print(int a, int b);
void test()
{
    int x = 1, y = 2;
    // print(x);
    // print(x, y);

    //ʹ�ú���ָ��
    void (*p)(int) = print;
    p(x);

    void (*p2)(int, int) = print;
    p2(x, y);
}
int main()
{
    test();
    return 0;
}

void print(int a)
{
    cout << "a=" << a << endl;
}
void print(int a, int b)
{
    cout << a << endl;
    cout << b << endl;
}
/* a=1
1
2 */