#include <iostream>
#include <memory>
using namespace std;
//ʹ��weak_ptr���ѭ������
class BB;
class AA
{
public:
    string m_name;
    AA() { cout << "���ù��캯��AA()" << endl; }
    AA(const string &name) : m_name(name)
    {
        cout << "���ù��캯��AA(const string &name)" << endl;
    }
    ~AA()
    {
        cout << "����AA��������" << endl;
    }
    weak_ptr<BB> sp;
};

class BB
{
public:
    string m_name;
    BB() { cout << "���ù��캯��BB()" << endl; }
    BB(const string &name) : m_name(name)
    {
        cout << "���ù��캯��BB(const string &name)" << endl;
    }
    ~BB()
    {
        cout << "����BB��������" << endl;
    }
    weak_ptr<AA> sp;
};
void test()
{
    //���⿪ʼ  ������δ����̲߳���ȫ
    /* {

        shared_ptr<AA> spa = make_shared<AA>("a1");
        {
            shared_ptr<BB> spb = make_shared<BB>("b1");
            spa->sp = spb;
            spb->sp = spa;

            //�����if else ���ִ��expired==true��ִ��lock ����������ԭ�Ӳ���,
            //��Դ����������������֮���Ѿ��������߳��ͷ�
            if (spa->sp.expired() == true)
            {
                cout << "�����ڲ�:spa->sp�Ѿ�����" << endl;
            }
            else
            {
                cout << "�����ڲ�:spa->sp.lock()->m_name=" << spa->sp.lock()->m_name << endl;
            }
        }
        if (spa->sp.expired() == true)
        {
            cout << "�����ⲿ:spa->sp�ѹ���" << endl;
        }
        else
        {
            cout << "�����ⲿ:spa->sp.lock()->m_name=" << spa->sp.lock()->m_name << endl;
        }
    } */
    //�������

    //��ȷ��ʼ
    {
        shared_ptr<AA> spa = make_shared<AA>("a1");
        {
            shared_ptr<BB> spb = make_shared<BB>("b1");
            spa->sp = spb;
            spb->sp = spa;

            //��weak_ptr����Ϊshared_ptr
            shared_ptr<BB> tmp = spa->sp.lock();
            if (tmp == nullptr)
            {
                cout << "�����ڲ�:spa->sp�Ѿ�����" << endl;
            }
            else
            {
                cout << "�����ڲ�:spa->sp.lock()->m_name=" << tmp->m_name << endl;
            }
        }

        shared_ptr<BB> tmp = spa->sp.lock();
        if (tmp == nullptr)
        {
            cout << "�����ⲿ:spa->sp�ѹ���" << endl;
        }
        else
        {
            cout << "�����ⲿ:spa->sp.lock()->m_name=" << tmp->m_name << endl;
        }
    }
    //��ȷ����
}
int main()
{
    test();
    return 0;
}
/*
���ù��캯��AA(const string &name)
���ù��캯��BB(const string &name)
�����ڲ�:spa->sp.lock()->m_name=b1
����BB��������
�����ⲿ:spa->sp�ѹ���
����AA��������  */