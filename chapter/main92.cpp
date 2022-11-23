#include <iostream>
using namespace std;

#define BH 3
#define MESSAGE "hello world"

void test()
{
    cout << BH << MESSAGE << endl;
    cout << __FILE__ << endl;
    cout << __FUNCTION__ << endl;
    cout << __LINE__ << endl;
    cout << __DATE__ << endl;
    cout << __TIME__ << endl;
    cout << __TIMESTAMP__ << endl;
    cout << __cplusplus << endl;
}
int main()
{
    test();
    return 0;
}