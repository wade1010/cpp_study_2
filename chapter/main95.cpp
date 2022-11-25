#include <iostream>
using namespace std;
void func(void *ptr)
{
    double *pp = static_cast<double *>(ptr);
    //其它代码
}
//内置数据类型转换
void test()
{
    int ii = 3;
    long ll = ii; //绝对安全,可以隐式转换,不会出现警告

    double dd = 1.234;
    long ll1 = dd;                    //可以隐式转换,但是,会出现可能丢失数据的警告
    long ll2 = (long)dd;              // long(dd)  C风格:显示转换,不会出现警告
    long ll3 = static_cast<long>(dd); // C++风格:显示转换,不会出现警告
}
//指针转换
void test2()
{
    int ii = 10;

    // double *pd1 = &ii;//错误,不能隐私转换
    double *pd2 = (double *)&ii; // C风格,强制转换
    // double *pd3 = static_cast<double *>(&ii); //错误,static_cast不支持不同烈性指针的转换

    void *pv = &ii;                          //任何类型的指针都可以隐私转换成void*
    double *pd4 = static_cast<double *>(pv); // static_cast可以把void*转换成其它类型的指针
}
void func2(void *ptr)
{
    // int i = reinterpret_cast<int>(ptr);
    // cout << i << endl;
}
// reinterpret_cast
// VS里面可以,但是有警告 警告的原因是int和void*占用的内存空间不一样
void test3()
{
    int ii = 10;
    double *pd3 = reinterpret_cast<double *>(&ii);

    func2(reinterpret_cast<void *>(ii));
}

// long long 和void* 都占8字节
void func3(void *ptr)
{
    long long i = reinterpret_cast<long long>(ptr);
    cout << i << endl;
}

void test4()
{
    long long ii = 10;
    func3(reinterpret_cast<void *>(ii));
}
// const_cast
void func4(int *i) {}
void test5()
{
    const int *a = nullptr;
    int *b = (int *)a;             // C风格,强制转换,丢掉const限定符
    int *c = const_cast<int *>(a); // C++风格,强制转换,丢掉const限定符

    func4(const_cast<int *>(a));
}
int main()
{
    test();
    test2();
    // test3();
    test4();
    test5();
    return 0;
}