#include <iostream>
#include <fstream>
using namespace std;

void test()
{
    ifstream ifs("test.txt");
    if (!ifs.is_open())
    {
        cout << "��ʧ��" << endl;
        return;
    }
    //��һ�ַ�ʽ
    // string buffer;
    // while (getline(ifs, buffer))
    // {
    //     cout << buffer << endl;
    // }
    // ifs.close();

    //�ڶ��ַ�ʽ
    //ע��һ��Ҫ��֤�������㹻��,���򳬹���������һ���Լ�����������ж������ȡ����
    //��̫���˷ѿռ�,���Բ�����ʹ��
    // char buffer[16];
    // while (ifs.getline(buffer, 15))
    // {
    //     cout << buffer << endl;
    // }
    // ifs.close();

    //�����ַ�ʽ
    string buffer;
    while (ifs >> buffer)
    {
        cout << buffer << endl;
    }
    ifs.close();

    //��ȡ�ļ����б�ķ�ʽ,���ǲ���ô�Ƽ�
}
int main()
{
    test();
    return 0;
}