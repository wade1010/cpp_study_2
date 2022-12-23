#include <iostream>
using namespace std;
//�ɱ����ģ��

template <typename T>
void show(T str)
{
    cout << "show=" << str << endl;
}

//�ݹ���ֹʱ���õķ�ģ�庯��,������Ҫ��չ���������ĵݹ麯��ģ����ͬ.
void print()
{
    cout << "�ݹ���ֹ" << endl;
}
//չ���������ĵݹ麯��ģ��
template <typename T, typename... Args>
void print(T arg, Args... args)
{
    cout << "����:" << arg << endl;
    show(arg);

    cout << "����" << sizeof...(args) << "������δչ��." << endl;

    print(args...);
}

template <typename... Args>
void func(const string &str, Args... args)
{
    cout << "�ں�:" << str << endl;
    print(args...);
    cout << "ok" << endl;
}

void test()
{
    print(1, "hello", 3.3, 'c');
    cout << endl;
    print(2, 3, "world");
    cout << endl;
    func("hello", "a1", "a2", "a2");
}
int main()
{
    test();
    return 0;
}
/* ����:1
show=1
����3������δչ��.
����:hello
show=hello
����2������δչ��.
����:3.3
show=3.3
����1������δչ��.
����:c
show=c
����0������δչ��.
�ݹ���ֹ

����:2
show=2
����2������δչ��.
����:3
show=3
����1������δչ��.
����:world
show=world
����0������δչ��.
�ݹ���ֹ

�ں�:hello
����:a1
show=a1
����2������δչ��.
����:a2
show=a2
����1������δչ��.
����:a2
show=a2
����0������δչ��.
�ݹ���ֹ
ok */