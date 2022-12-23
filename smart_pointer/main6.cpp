#include <iostream>
#include <memory>
using namespace std;
class AA
{
public:
    string m_name;
    AA() { cout << "调用构造函数AA()," << m_name << endl; }
    AA(const string &name) : m_name(name) { cout << "调用了构造函数AA(const string &name)," << m_name << endl; }
    ~AA() { cout << "调用了析构函数~AA()," << m_name << endl; }
};
void deletefunc(AA *a)
{
    cout << "自定义删除器(全局函数)" << endl;
    delete a;
}

//删除器 仿函数
struct deleteclass
{
    void operator()(AA *a)
    {
        cout << "自定义删除器(仿函数删除)" << endl;
        delete a;
    }
};
//删除器 lambda表达式
auto deletelambda = [](AA *a)
{
    cout << "自定义删除器(Lambda)" << endl;
    delete a;
};
void test()
{
    // shared_ptr<AA> sp(new AA("a1"));//缺省的删除器

    // shared_ptr<AA> sp1(new AA("a1"), deletefunc);//删除器,普通函数

    // shared_ptr<AA> sp2(new AA("a1"), deleteclass());//删除器 lambda表达式

    // shared_ptr<AA> sp3(new AA("a1"), deletelambda);

    unique_ptr<AA, decltype(deletefunc) *> up(new AA("a1"), deletefunc);
    //模板参数用decltype推断会方便一点点,也可以直接用函数指针
    // unique_ptr<AA, void (*)(AA *)> up2(new AA("a1"), deletefunc);
    unique_ptr<AA, deleteclass> up3(new AA("a3"), deleteclass());
    unique_ptr<AA, decltype(deletelambda)> up4(new AA("a4"), deletelambda);
}
int main()
{
    test();
    return 0;
}