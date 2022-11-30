#include <iostream>
#include <memory>
using namespace std;
class AA
{
public:
    string m_name;
    AA() { cout << "���ù��캯��AA()," << m_name << endl; }
    AA(const string &name) : m_name(name) { cout << "�����˹��캯��AA(const string &name)," << m_name << endl; }
    ~AA() { cout << "��������������~AA()," << m_name << endl; }
};
void deletefunc(AA *a)
{
    cout << "�Զ���ɾ����(ȫ�ֺ���)" << endl;
    delete a;
}

//ɾ���� �º���
struct deleteclass
{
    void operator()(AA *a)
    {
        cout << "�Զ���ɾ����(�º���ɾ��)" << endl;
        delete a;
    }
};
//ɾ���� lambda���ʽ
auto deletelambda = [](AA *a)
{
    cout << "�Զ���ɾ����(Lambda)" << endl;
    delete a;
};
void test()
{
    // shared_ptr<AA> sp(new AA("a1"));//ȱʡ��ɾ����

    // shared_ptr<AA> sp1(new AA("a1"), deletefunc);//ɾ����,��ͨ����

    // shared_ptr<AA> sp2(new AA("a1"), deleteclass());//ɾ���� lambda���ʽ

    // shared_ptr<AA> sp3(new AA("a1"), deletelambda);

    unique_ptr<AA, decltype(deletefunc) *> up(new AA("a1"), deletefunc);
    //ģ�������decltype�ƶϻ᷽��һ���,Ҳ����ֱ���ú���ָ��
    // unique_ptr<AA, void (*)(AA *)> up2(new AA("a1"), deletefunc);
    unique_ptr<AA, deleteclass> up3(new AA("a3"), deleteclass());
    unique_ptr<AA, decltype(deletelambda)> up4(new AA("a4"), deletelambda);
}
int main()
{
    test();
    return 0;
}