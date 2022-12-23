#include <iostream>
using namespace std;
//����ת��
void func1(int &i)
{
    cout << "��������ֵ=" << i << endl;
}
void func1(int &&i)
{
    cout << "��������ֵ=" << i << endl;
}
void func2(int i)
{
    func1(i);
}
void func3(int &&i)
{
    func1(i);
}
void func3(int &i)
{
    func1(i);
}

void func4(int &&i)
{
    func1(move(i));
}
void func4(int &i)
{
    func1(i);
}

template <typename T>
void func5(T &&i)
{
    func1(move(i));
}
template <typename T>
void func5(T &i)
{
    func1(i);
}

template <typename T>
void func6(T &&i)
{
    func1(forward<T>(i));
}

void func7(int &&i)
{
    func1(forward<int>(i));
}

void test()
{
    int i = 3;
    func1(i);
    func1(33);
    /* ��������ֵ=3
    ��������ֵ=33  */
    //����������,�����������,������������ֽڵ���,�м�������������ר,����ר�ĺ�������ôд��?

    func2(i);
    func2(33);
    /* ��������ֵ=3
��������ֵ=33 */
    //����������������Կ���,����������Ҫ��,������Ҫ����:func2()�Ѳ�������func1()��ʱ��,ҲҪ����ֵ����ֵ֮��
    //��������ڴ��ݵĹ����в��ܱ�����/��ֵ������,�ǾͲ���ʵ���ƶ�������.
    func3(i);
    func3(33);
    /*��������ֵ=3
��������ֵ=33  */
    //�������Ҳ����������Ҫ��

    func4(i);
    func4(33);
    /*��������ֵ=3
��������ֵ=33 */
    //���������������Ҫ��,���Ǹ÷���������õ�,���ƵĻ�������ģ��ĳ�����ģ��

    func5(i);
    func5(33);
    /*��������ֵ=3
��������ֵ=33 */
    cout << "------------------" << endl;
    //ʹ�����,C++11�ṩ��������
    func6(i);
    func6(33);
}
int main()
{
    test();
    return 0;
}
/* ��������ֵ=3
��������ֵ=33
��������ֵ=3
��������ֵ=33
��������ֵ=3
��������ֵ=33
��������ֵ=3
��������ֵ=33
��������ֵ=3
��������ֵ=33
------------------
��������ֵ=3
��������ֵ=33 */