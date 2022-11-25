#include <iostream>
using namespace std;
// shrink_to_fit
void test()
{
    string a;
    cout << a.capacity() << " " << a.length() << " " << a.size() << endl;
    a = "xxxxxxxxxxxxxxxxxxxxx";
    cout << a.capacity() << " " << a.length() << " " << a.size() << endl;
    a.shrink_to_fit();
    cout << a.capacity() << " " << a.length() << " " << a.size() << endl;
}
int main()
{
    test();
    return 0;
}