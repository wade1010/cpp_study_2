#include "iostream"
#include <cstring>
using namespace std;

void test()
{
    char name[11] = {"hello\0f"};
    cout << strlen(name) << endl;
    char name1[11] = {"hello"};
    name1[1] = 0;
    cout << strlen(name1) << endl;
}
int main()
{
    test();
    return 0;
}