#include "iostream"
using namespace std;
class Hero
{
public:
    int viability;
    int attack;
    virtual void skill1() { cout << "�ͷ���1����" << endl; }
    virtual void skill2() { cout << "�ͷ���2����" << endl; }
    virtual void skill3() { cout << "�ͷ���3����" << endl; }
};
class XS : public Hero
{
public:
    void skill1() { cout << "��ʩ�ͷ���1����" << endl; }
    void skill2() { cout << "��ʩ�ͷ���2����" << endl; }
    void skill3() { cout << "��ʩ�ͷ���3����" << endl; }
    void show() { cout << "�ұȱ��˶�һ������" << endl; }
};
class HX : public Hero
{
public:
    void skill1() { cout << "�����ͷ���1����" << endl; }
    void skill2() { cout << "�����ͷ���2����" << endl; }
    void skill3() { cout << "�����ͷ���3����" << endl; }
};
void test()
{
    int id = 0;
    cout << "������Ӣ��(1-��ʩ,2-����)" << endl;
    cin >> id;
    Hero *p = nullptr;
    if (id == 1)
    {
        p = new XS;
    }
    else if (id == 2)
    {
        p = new HX;
    }
    if (p != nullptr)
    {
        p->skill1();
        p->skill2();
        p->skill3();

        //�������ָ��ָ��Ķ���ʱ��ʩ,��ô�õ�����ʩ��show()����
        // ����1 ��İ취
        if (id == 1)
        {
            XS *xs = (XS *)p; // C���ǿת���ķ���,�����Լ����뱣֤Ŀ��������ȷ
            xs->show();
        }
        // ����2 dynamic_cast
        XS *xs2 = dynamic_cast<XS *>(p);
        if (xs2 != nullptr)
        {
            xs2->show();
        }
        // ����3 typeid
        if (typeid(XS) == typeid(*p))
        {
            XS *xs3 = (XS *)p;
            xs3->show();
        }

        delete p;
    }

    //���´�����ʾ�ѻ�������ת��Ϊ����������ʱ�����쳣�����
    HX hx;
    Hero &rh = hx;
    try
    {
        XS &rxs = dynamic_cast<XS &>(rh);
    }
    catch (bad_cast)
    {
        cout << "������bad_cast�쳣" << endl;
    }
}
int main()
{
    test();
    return 0;
}