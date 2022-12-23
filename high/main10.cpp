#include <iostream>
#include <map>
using namespace std;

void test()
{
    map<int, string> m1;
    map<int, string> m2({{1, "a"}, {2, "b"}});
    // map<int, string> m2 = {{1, "a"}, {2, "b"}};
    // map<int, string> m2{{1, "a"}, {2, "b"}};
    for (auto p : m2)
    {
        cout << p.first << " " << p.second << ",";
    }
    cout << endl;

    map<int, string> m3 = m2;
    for (auto &val : m3)
    {
        cout << val.first << " " << val.second << ",";
    }
    cout << endl;

    auto first = m3.begin();
    first++;

    map<int, string>::iterator last = m3.end();
    last++;

    map<int, string> m4(first, last);
    for (auto &val : m4)
    {
        cout << val.first << " " << val.second << ",";
    }
    cout << endl;

    cout << m3.size() << endl;
    cout << m3[3] << endl;

    for (auto &val : m3)
    {
        cout << val.first << " " << val.second << ",";
    }
    cout << endl;
    map<int, string> m5 = m2;
    cout << (m5 == m2) << endl;
}
int main()
{
    test();
    return 0;
}