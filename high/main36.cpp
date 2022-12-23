#include <iostream>
using namespace std;
typedef char *pstring;
void test()
{
    char c = 'C';
    const pstring cstr = &c;
    char b = 'B';

    //测试1 修改指向的值
    *cstr = 'B';

    //测试2 修改指向
    // cstr = &b; //报错如下
    /* main.cpp:9:13: error: assignment of read-only variable 'cstr'
     cstr = &b; */

    //  通过测试可以得出,const pstring是常量指针
}
int main()
{
    test();
    return 0;
}