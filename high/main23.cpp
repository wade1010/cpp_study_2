#include <iostream>
#include <cassert>
using namespace std;

void copy_data(void *ptr1, void *ptr2)
{
    assert(ptr1 && ptr2); //����ptr1��ptr2������Ϊ��
    cout << "����ִ�и��ƵĴ���....." << endl;
}
void test()
{
    int i = 0, j = 0;
    // copy_data(&j, &i);
    copy_data(nullptr, &i);
}
int main()
{
    test();
    return 0;
}