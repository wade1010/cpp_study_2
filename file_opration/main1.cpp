#include <iostream>
#include <fstream>
using namespace std;

void test()
{
    // �ļ���һ����ȫ·������д�ķ������£�
    //  1��"D:\data\txt\test.txt"       // ����
    //  2��R"(D:\data\txt\test.txt)"   // ԭʼ��������C++11��׼��
    //  3��"D:\\data\\txt\\test.txt"   // ת���ַ���
    //  4��"D:/tata/txt/test.txt"        // ��б�߷���д��
    //  5��"/data/txt/test.txt"          //  Linuxϵͳ���õķ�����
    string filename = R"(W:\workspace\cpp\practice\cpp_basics_2\test.txt)";
    ofstream ofs(filename);
    //���Ŀ¼������,����ʧ��,���Ŀ¼����,�����ļ�������,���Զ������ļ�
    if (!ofs.is_open())
    {
        cout << "��ʧ��" << endl;
        return;
    }

    ofs << "1,2,3\n";
    ofs << "4,5,6\n";

    ofs.close();
    cout << "ok" << endl;
}
int main()
{
    test();
    return 0;
}