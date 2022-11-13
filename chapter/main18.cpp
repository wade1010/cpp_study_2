#include "iostream"
using namespace std;

void test()
{
    int a = 1;
    int b[a];
    int c[sizeof(a) / 2];
    cout << "ok" << endl;
}
int main()
{
    test();
    return 0;
}