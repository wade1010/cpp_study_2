#include <iostream>
using namespace std;
class AA final
{
};

class BB
{
public:
    virtual void func() final
    {
        cout << "func" << endl;
    }
};

void test()
{
    int i = 2;
    string istr = to_string(i);
    cout << istr << endl;
    int b = stoi(istr);
    cout << b << endl;
}
int main()
{
    test();
    return 0;
}