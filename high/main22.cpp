#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
template <class T>
struct girl
{
    T m_yz;
    int m_count;
    girl(const T &yz) : m_yz(yz), m_count(0) {}

    void operator()(const T &yz)
    {
        if (yz == m_yz)
        {
            m_count++;
        }
    }
};

void test()
{
    vector<int> v = {1, 2, 3, 1, 2, 1, 3, 2, 3, 4, 1};
    girl<int> g(2);
    // for (auto val : v)
    // {
    //     g(val);
    // }
    // cout << g.m_count << endl;

    // g = for_each(v.begin(), v.end(), g);
    // cout << g.m_count << endl;

    g = for_each(v.begin(), v.end(), girl<int>(1));
    cout << g.m_count << endl;

    // for_each(v.begin(), v.end(), girl<int>(1));
    // cout << g.m_count << endl; //不用变量接收返回的对象,m_count就是0
}
int main()
{
    test();
    return 0;
}