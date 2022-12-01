#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void zsshow(const int &no)
{
    cout << no << endl;
}
class AA
{
public:
    void operator()(const int &no)
    {
        cout << no << endl;
    }
};
void test()
{
    vector<int> vv{1, 2, 3, 4};
    //��ͨ����
    for_each(vv.begin(), vv.end(), zsshow);
    //�º���
    for_each(vv.begin(), vv.end(), AA());

    // lambda
    auto func = [](const int &no) -> void
    {
        cout << no << endl;
    };

    for_each(vv.begin(), vv.end(), func);

    func(3);

    auto func2 = []
    {
        cout << "û�в����б�,ʡ������" << endl;
    };
    func2();
}
int main()
{
    test();
    return 0;
}