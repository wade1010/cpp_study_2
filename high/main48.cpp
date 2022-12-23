#include <iostream>
#include <functional>
using namespace std;
//取代虚函数
struct Hero
{
    // virtual void show() { cout << "英雄释放了技能" << endl; }
    function<void()> m_callback;

    template <typename Fn, typename... Args>
    void callback(Fn &&fn, Args &&...args)
    {
        m_callback = bind(forward<Fn>(fn), forward<Args>(args)...);
    }
    //再写个show函数取代曲函数,调用子类的成员函数
    void show()
    {
        m_callback();
    }
    virtual ~Hero() { cout << "~Here()" << endl; }
};

struct XS : public Hero
{
    ~XS() { cout << "~XS()" << endl; }
    void show() { cout << "西施释放了技能" << endl; }
};

struct HX : public Hero
{
    ~HX() { cout << "~HX()" << endl; }
    void show() { cout << "韩信释放了技能" << endl; }
};

void test()
{
    int id = 0;
    cout << "请输入英雄:1:西施,2:韩信" << endl;
    cin >> id;
    Hero *ptr = nullptr;
    if (id == 1)
    {
        ptr = new XS;
        // ptr->callback(&XS::show, (XS *)ptr);//ptr是基类指针,要转换为派生类指针,C语言转换风格
        ptr->callback(&XS::show, static_cast<XS *>(ptr)); // C++风格
    }
    else if (id == 2)
    {
        ptr = new HX;
        ptr->callback(&HX::show, (HX *)ptr);
    }
    if (ptr != nullptr)
    {
        ptr->show();
        delete ptr;
    }
}
int main()
{
    test();
    return 0;
}