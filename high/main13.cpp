#include <iostream>
#include <unordered_map>
#include <ctime>
using namespace std;

void test()
{
    unordered_map<int, string> m(10000000);
    int start = time(0);
    cout << "��ʼ����" << start << endl;
    for (int i = 0; i < 10000000; i++)
    {
        m.insert({i, "��Ů"});
        // m.emplace(i, "��Ů"); //����
    }
    cout << "�������:" << (time(0) - start) << "��" << endl;
}
int main()
{
    test();
    return 0;
}
