#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void show(const T &str)
{
    cout << str << endl;
}

template <class T>
class CTmp
{
public:
    void operator()(const T &no)
    {
        cout << "call operator:" << no << " ";
    }
};

template <typename T1, typename T2>
void _foreach(const T1 first, const T1 last, T2 func)
{
    for (auto it = first; it != last; it++)
        func(*it);
    cout << endl;
}
void test()
{
    // vector<int> bh{2, 3, 4, 5, 6};
    vector<string> bh{"A2", "A3", "A4", "A5", "A6"};
    _foreach(bh.begin(), bh.end(), CTmp<string>());
    _foreach(bh.begin(), bh.end(), show<string>);
}
int main()
{
    test();
    return 0;
}
/*
call operator:A2 call operator:A3 call operator:A4 call operator:A5 call operator:A6
A2
A3
A4
A5
A6*/