#include <iostream>
#include <cassert>
using namespace std;

void copy_data(void *ptr1, void *ptr2)
{
    assert(ptr1 && ptr2); //断言ptr1和ptr2都不会为空
    cout << "继续执行复制的代码....." << endl;
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