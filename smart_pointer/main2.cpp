#include <iostream>
#include <memory>
using namespace std;
class AA
{
public:
    string m_name;
    AA()
    {
        cout << m_name << "���ù��캯��AA()" << endl;
    }
    AA(const string &name) : m_name(name)
    {
        cout << "���ù��캯��AA(const string &name)," << m_name << endl;
    }
    ~AA() { cout << "������������," << m_name << endl; }
};
unique_ptr<AA> func()
{
    unique_ptr<AA> p(new AA("a3"));
    return p;
}
// unique_ptr<AA> sp(new AA("a4"));
// unique_ptr<AA> func2()
// {
//     return sp;
// }
void test()
{
    unique_ptr<AA> pu1(new AA("a1"));
    unique_ptr<AA> pu2;
    // pu2 = pu1; //����
    pu2 = unique_ptr<AA>(new AA("a2")); //����������ֵ
    cout << "����func()֮ǰ." << endl;
    // unique_ptr��ĸ�ֵ�����Ѿ���ɾ����,������һ�л��ܸ�ֵ,����֮һ
    // pu2�����ܹ�������Դ,����,�����ͷ���a2,�ٽ���a3
    //���������func()�����е�unique_ptr������������,��func2(),����,���벻ͨ��
    pu2 = func();
    cout << "����func()֮��" << endl;
    AA *optr = pu2.release();
    cout << optr << endl;
    cout << "����" << endl;
}
int main()
{
    test();
    return 0;
}
/*���ù��캯��AA(const string &name),a1
���ù��캯��AA(const string &name),a2
����func()֮ǰ.
���ù��캯��AA(const string &name),a3
������������,a2
����func()֮��
0xef1ab0
����
������������,a1*/