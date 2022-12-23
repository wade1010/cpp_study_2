#include <iostream>
#include <fstream>
using namespace std;

void test()
{
    string filename = R"(text.txt)";

    ofstream fout(filename);
    fout << "1,2,3,4\n";
    fout << "11,22,33,44\n";
    fout.close();

    ifstream fin(filename);
    string buffer;
    // while (fin >> buffer)
    // {
    //     cout << buffer << endl;
    // }

    while (true)
    {
        fin >> buffer;
        cout << "eof()=" << fin.eof() << ",good()=" << fin.good() << ",bad()=" << fin.bad() << ",fail()=" << fin.fail() << endl;
        if (fin.eof())
        {
            break;
        }
        cout << buffer << endl;
    }
}
int main()
{
    test();
    return 0;
}