#include <iostream>
#include <vector>
#include <forward_list>
using namespace std;
template <typename T>
void _foreach(const T first, const T last)
{
    for (auto it = first; it != last; it++)
        cout << *it << " ";
    cout << endl;
}

void zsshow(const string &no)
{
    cout << no << " ";
}

//�û��Զ��庯��ָ��
template <typename T>
void _foreach2(const T first, const T last, void (*pfunc)(const string &))
{
    for (auto it = first; it != last; it++)
        pfunc(*it);
    cout << endl;
}

//������ĳ�Ա����
class CTmp
{
public:
    void show(const string &no)
    {
        cout << "call show:" << no << " ";
    }
    void operator()(const string &no)
    {
        cout << "call operator:" << no << " ";
    }
};
template <typename T>
void _foreach3(const T first, const T last, CTmp ct)
{
    for (auto it = first; it != last; it++)
        ct.show(*it);
    cout << endl;
}

template <typename T>
void _foreach4(const T first, const T last, CTmp ct)
{
    for (auto it = first; it != last; it++)
        ct(*it);
    cout << endl;
}

//ģ��

template <typename T1, typename T2>
void _foreach5(const T1 first, const T1 last, T2 func)
{
    for (auto it = first; it != last; it++)
        func(*it);
    cout << endl;
}
void test()
{
    // vector<int> bh{2, 3, 4, 5, 6};
    vector<string> bh{"2", "3", "4", "5", "6"};
    _foreach(bh.begin(), bh.end());
    //�û��Զ��庯��ָ��
    _foreach2(bh.begin(), bh.end(), zsshow);
    //������ĳ�Ա����
    _foreach3(bh.begin(), bh.end(), CTmp());
    //�º���
    _foreach4(bh.begin(), bh.end(), CTmp());
    //�����β���ʲô��������,ֻҪ��������Ĵ�����ͬ,�Ϳ�������ģ��

    cout << endl;
    //�����������ȿ����Ǻ���,Ҳ��������,������С���ŵ���,Ҳ�зº���
    _foreach5(bh.begin(), bh.end(), CTmp());
    _foreach5(bh.begin(), bh.end(), zsshow);
}
int main()
{
    test();
    return 0;
}
/* 2 3 4 5 6
2 3 4 5 6
call show:2 call show:3 call show:4 call show:5 call show:6
call operator:2 call operator:3 call operator:4 call operator:5 call operator:6

call operator:2 call operator:3 call operator:4 call operator:5 call operator:6
2 3 4 5 6 */