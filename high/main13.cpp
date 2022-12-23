#include <iostream>
#include <unordered_map>
#include <ctime>
using namespace std;

void test()
{
    unordered_map<int, string> m(10000000);
    int start = time(0);
    cout << "开始创建" << start << endl;
    for (int i = 0; i < 10000000; i++)
    {
        m.insert({i, "美女"});
        // m.emplace(i, "美女"); //更快
    }
    cout << "创建完成:" << (time(0) - start) << "秒" << endl;
}
int main()
{
    test();
    return 0;
}
