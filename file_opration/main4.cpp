#include <iostream>
#include <fstream>
using namespace std;

void test()
{
    ifstream ifs("test.dat", ios::in | ios::binary);
    if (!ifs.is_open())
    {
        cout << "open failed" << endl;
        return;
    }

    struct people
    {
        char name[30];
        int age;
    } p;

    while (ifs.read((char *)&p, sizeof(people)))
    {
        cout << p.name << " " << p.age << endl;
    }
    ifs.close();

    cout << "ok" << endl;
}
int main()
{
    test();
    return 0;
}