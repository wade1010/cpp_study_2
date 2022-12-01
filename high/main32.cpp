#include <iostream>
#include <cstring>
using namespace std;
// �ƶ�����
class AA
{
public:
    int *m_data = nullptr;
    AA() = default;
    void alloc()
    {
        m_data = new int;
        memset(m_data, 0, sizeof(int));
    }

    AA(const AA &a)
    {
        cout << "�����˿������캯��" << endl;
        if (this == &a)
        {
            return;
        }
        if (m_data == nullptr)
        {
            alloc();
        }
        memcpy(m_data, a.m_data, sizeof(int)); //�����ݴ�Դ�����п�������
    }
    //�ƶ����캯��
    AA(AA &&a) //��Ϊ��Ҫ������ת�ƶ����е�ָ��,���Բ�����const
    {
        cout << "�������ƶ����캯��" << endl;
        if (m_data != nullptr)
        {
            delete m_data; //����Ѿ������ڴ�,���ͷŵ�
        }
        m_data = a.m_data;  //����Դ��Դ������ת�ƹ���
        a.m_data = nullptr; //��Դ�����е�ָ���ÿ�
    }
    AA &operator=(const AA &a)
    {
        cout << "�����˸�ֵ����" << endl;
        if (this == &a)
        {
            return *this;
        }
        if (m_data == nullptr)
        {
            alloc();
        }
        memcpy(m_data, a.m_data, sizeof(int));
        return *this;
    }

    //�ƶ���ֵ����
    AA &operator=(AA &&a)
    {
        cout << "�������ƶ���ֵ����" << endl;
        if (this == &a)
        {
            return *this;
        }
        if (m_data != nullptr)
        {
            delete m_data;
        }
        m_data = a.m_data;
        a.m_data = nullptr;
        return *this;
    }
    ~AA()
    {
        cout << "��������������" << endl;
        if (m_data != nullptr)
        {
            delete m_data;
            m_data = nullptr;
        }
    }
};
AA func()
{
    AA a;
    a.alloc();
    *a.m_data = 19;
    return a;
}
void test()
{
    AA a1;
    a1.alloc();
    *a1.m_data = 3;
    cout << "a1.m_data=" << *a1.m_data << endl;

    AA a2 = a1;
    cout << "a2.m_data=" << *a2.m_data << endl;

    AA a3;
    a3 = move(a1); //�������ƶ���ֵ���� ����ע�ⲻ��move���,��move��,����ʹ�þ�Ҫע���ָ����
    // a3 = a1;       //�����˸�ֵ����
    cout << "a3.m_data=" << *a3.m_data << endl;
}
int main()
{
    test();
    return 0;
}
/* a1.m_data=3
�����˿������캯��
a2.m_data=3
�������ƶ���ֵ����
a3.m_data=3
��������������
��������������
�������������� */