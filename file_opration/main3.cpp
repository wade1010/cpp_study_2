#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void test()
{
    ofstream ofs("test.dat", ios::app | ios::binary);
    if (!ofs.is_open())
    {
        cout << "open failed" << endl;
        return;
    }

    struct people
    {
        char name[30];
        int age;
    } p;
    memcpy(p.name, "hello", 30);
    p.age = 10;
    ofs.write((const char *)&p, sizeof(people));
    ofs.close();
    cout << "ok" << endl;
}
int main()
{
    test();
    return 0;
}