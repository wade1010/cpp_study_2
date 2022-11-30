#include <iostream>
#include <fstream>
using namespace std;

void test()
{
    string filename = R"(W:\workspace\cpp\practice\cpp_basics_2\test.txt)";
    fstream ofs;
    ofs.open(filename);
    //如果目录不存在,则会打开失败,如果目录存在,但是文件不存在,会自动创建文件
    if (!ofs.is_open())
    {
        cout << "打开失败" << endl;
        return;
    }
    cout << "位置:" << ofs.tellp() << " " << ofs.tellg() << endl;
    ofs << "1,2,3\n";
    cout << "位置:" << ofs.tellp() << " " << ofs.tellg() << endl;
    ofs << "4,5,6\n";
    cout << "位置:" << ofs.tellp() << " " << ofs.tellg() << endl;

    ofs.close();
    cout << "写入 ok" << endl;

    fstream ifs(filename);
    string buffer;
    cout << "位置:" << ifs.tellp() << " " << ifs.tellg() << endl;
    while (getline(ifs, buffer))
    {
        cout << buffer << endl;
        cout << "位置:" << ifs.tellp() << " " << ifs.tellg() << endl;
    }
    ifs.close();
    cout << "读取 ok" << endl;

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