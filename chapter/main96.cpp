#include <iostream>
#include <cstring>
using namespace std;

void test()
{
    char cc[8]; //在栈上分配8字节的内存空间
    //把cc的内存空间用于字符串

    //把cc的内存空间用于int型整数
    int *a, *b;
    a = (int *)cc;
    b = (int *)cc + 1;
    cout << (long long)a << endl;
    cout << (long long)b << endl;
    *a = 1999;
    *b = 2222;
    cout << "*a=" << *a << endl;
    cout << "*b=" << *b << endl;

    //把cc的内存空间用于double
    double *d = (double *)cc;
    *d = 333.222;
    cout << "*d=" << *d << endl;

    //把cc的内存空间用于结构体
    struct stt
    {
        int a;
        char b[4];
    } * st;

    st = (struct stt *)&cc;
    st->a = 111;
    /*     strcpy(st->b, "abcd"); //如果是这样,不会报错,但是输出为:
    st->a=6821633   这个值每次都变,不知道指向了哪里
    st->b=  打印出来为空*/
    strcpy(st->b, "abc");
    cout << "st->a=" << st->a << endl;
    cout << "st->b=" << st->b << endl;

    // void * malloc(size_t size)
    // char *cc1 = (char *)malloc(8);
    // int *cc1 = (int *)malloc(8);
}
int main()
{
    test();
    return 0;
}