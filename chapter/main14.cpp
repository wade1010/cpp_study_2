#include "iostream"
#include <cstring>
using namespace std;

void test()
{
    char name[11] = {"hello"};

    cout << endl;
    strcpy(name, "world");
    for (int i = 0; i < 11; i++)
    {
        cout << (int)name[i] << " ";
    }
    cout << endl;
    strcpy(name, "worldworldworld");
    for (int i = 0; i < 11; i++)
    {
        cout << (int)name[i] << " ";
    }
    cout << endl;
}
int main()
{
    test();
    return 0;
}