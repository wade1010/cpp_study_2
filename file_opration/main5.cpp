#include <iostream>
#include <fstream>
using namespace std;

void test()
{
    string filename = R"(W:\workspace\cpp\practice\cpp_basics_2\test.txt)";
    fstream ofs;
    ofs.open(filename);
    //���Ŀ¼������,����ʧ��,���Ŀ¼����,�����ļ�������,���Զ������ļ�
    if (!ofs.is_open())
    {
        cout << "��ʧ��" << endl;
        return;
    }
    cout << "λ��:" << ofs.tellp() << " " << ofs.tellg() << endl;
    ofs << "1,2,3\n";
    cout << "λ��:" << ofs.tellp() << " " << ofs.tellg() << endl;
    ofs << "4,5,6\n";
    cout << "λ��:" << ofs.tellp() << " " << ofs.tellg() << endl;

    ofs.close();
    cout << "д�� ok" << endl;

    fstream ifs(filename);
    string buffer;
    cout << "λ��:" << ifs.tellp() << " " << ifs.tellg() << endl;
    while (getline(ifs, buffer))
    {
        cout << buffer << endl;
        cout << "λ��:" << ifs.tellp() << " " << ifs.tellg() << endl;
    }
    ifs.close();
    cout << "��ȡ ok" << endl;

    fstream fs(filename);
    // fs.seekp(4);
    fs.seekg(-3, ios::end);
    string buffer2;
    while (fs >> buffer2)
    {
        cout << buffer2 << endl;
    }
    fs.close();
    cout << "ok" << endl;
}
int main()
{
    test();
    return 0;
}