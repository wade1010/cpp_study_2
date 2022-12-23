#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
bool show(const T &no)
{
    if (no != 3)
    {
        return false;
    }

    cout << no << endl;
    return true;
}

template <class T>
class CTmp
{
public:
    T m_no;
    CTmp(const T &no) : m_no(no) {}
    bool operator()(const T &no)
    {
        if (no != m_no)
        {
            return false;
        }
        cout << "call operator:" << no << endl;
        return true;
    }
};
template <typename T1, typename T2>
T1 _find_if(const T1 first, const T1 end, T2 pfun)
{
    for (auto it = first; it != end; it++)
    {
        if (pfun(*it))
        {
            return it;
        }
    }
    return end;
}

void test()
{
    vector<int> bh{2, 3, 4, 5, 6};
    // vector<string> bh{"A2", "A3", "A4", "A5", "A6"};
    auto it = _find_if(bh.begin(), bh.end(), CTmp<int>(3));
    if (it == bh.end())
    {
        cout << "查找失败" << endl;
    }
    else
    {
        cout << "查找成功" << endl;
    }

    it = _find_if(bh.begin(), bh.end(), show<int>);
    if (it == bh.end())
    {
        cout << "查找失败" << endl;
    }
    else
    {
        cout << "查找成功" << endl;
    }
}
int main()
{
    test();
    return 0;
}
