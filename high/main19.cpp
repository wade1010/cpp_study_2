#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

template <typename T>
bool show(const T &no, const T &t_no)
{
    if (no != t_no)
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
    bool operator()(const T &no, const T &t_no)
    {
        if (no != t_no)
        {
            return false;
        }
        cout << "call operator:" << no << endl;
        return true;
    }
};
template <typename T1, typename T2, typename T3>
T1 _find_if(const T1 first, const T1 end, T2 pfun, T3 target)
{
    for (auto it = first; it != end; it++)
    {
        if (pfun(*it, target))
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
    _find_if(bh.begin(), bh.end(), CTmp<int>(), 3);
    _find_if(bh.begin(), bh.end(), show<int>, 3);
}
int main()
{
    test();
    return 0;
}
