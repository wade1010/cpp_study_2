#include <iostream>
#include <algorithm>
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

void test()
{
    // vector<int> bh{2, 3, 4, 5, 6};
    vector<string> bh{"A2", "A3", "A4", "A5", "A6"};
    for_each(bh.begin(), bh.end(), CTmp<string>());
    for_each(bh.begin(), bh.end(), show<string>);
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