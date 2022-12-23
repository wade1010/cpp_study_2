#include <iostream>
#include <functional>
using namespace std;
//ȡ���麯��
struct Hero
{
    // virtual void show() { cout << "Ӣ���ͷ��˼���" << endl; }
    function<void()> m_callback;

    template <typename Fn, typename... Args>
    void callback(Fn &&fn, Args &&...args)
    {
        m_callback = bind(forward<Fn>(fn), forward<Args>(args)...);
    }
    //��д��show����ȡ��������,��������ĳ�Ա����
    void show()
    {
        m_callback();
    }
    virtual ~Hero() { cout << "~Here()" << endl; }
};

struct XS : public Hero
{
    ~XS() { cout << "~XS()" << endl; }
    void show() { cout << "��ʩ�ͷ��˼���" << endl; }
};

struct HX : public Hero
{
    ~HX() { cout << "~HX()" << endl; }
    void show() { cout << "�����ͷ��˼���" << endl; }
};

void test()
{
    int id = 0;
    cout << "������Ӣ��:1:��ʩ,2:����" << endl;
    cin >> id;
    Hero *ptr = nullptr;
    if (id == 1)
    {
        ptr = new XS;
        // ptr->callback(&XS::show, (XS *)ptr);//ptr�ǻ���ָ��,Ҫת��Ϊ������ָ��,C����ת�����
        ptr->callback(&XS::show, static_cast<XS *>(ptr)); // C++���
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