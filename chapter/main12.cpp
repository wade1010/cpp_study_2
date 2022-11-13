#include "iostream"
using namespace std;

void test()
{
    string str = "abc";
    cout << "str[0]" << (int)str[0] << endl;
    cout << "str[1]" << (int)str[1] << endl;
    cout << "str[2]" << (int)str[2] << endl;
    cout << "str[3]" << (int)str[3] << endl;
}
int main()
{
    test();
    return 0;
}
// str[0]97
// str[1]98
// str[2]99
// str[3]0