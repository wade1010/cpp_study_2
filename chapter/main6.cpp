#include "iostream"
using namespace std;

void test()
{
    int a[5] = {1, 2, 3, 4, 5};
    for (int i = -2; i < 5; i++)
    {
        cout << "a[" << i << "] address is:" << &a[i] << " " << (long long)&a[i] << endl;
    }
    cout << endl;
}
int main()
{
    test();
    return 0;
}
// a[-2] address is:0x61fdc8 6421960
// a[-1] address is:0x61fdcc 6421964
// a[0] address is:0x61fdd0 6421968
// a[1] address is:0x61fdd4 6421972
// a[2] address is:0x61fdd8 6421976
// a[3] address is:0x61fddc 6421980
// a[4] address is:0x61fde0 6421984