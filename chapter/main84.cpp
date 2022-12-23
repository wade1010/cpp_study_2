
#include "iostream"
using namespace std;
void show()
{
    cout << "调用了show()函数" << endl;
}
class BB
{
public:
    void operator()()
    {
        cout << "调用了BB类的仿函数" << endl;
    }
};

//函数模板,参数和返回值是任意类型
template <typename T>
void func(T tt)
{
    tt();
}
void test()
{
    BB bb;
    func(bb);

    func(show); //传入show,函数名,也就是函数指针
}
int main()
{
    test();
    return 0;
}