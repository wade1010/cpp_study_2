#include <iostream>
using namespace std;
//�쳣
void test()
{
    try
    {
        int ii = 0;
        cout << "������ѡ��,1:cosnt char*�׳��쳣,2:int�쳣,3:stirng�쳣,4:����" << endl;
        cin >> ii;
        if (ii == 1)
        {
            throw "���׾���";
        }
        else if (ii == 2)
        {
            throw ii;
        }
        else if (ii == 3)
        {
            throw string("string");
        }

        cout << "ok" << endl;
    }
    catch (int ei)
    {
        cout << "�쳣��������int=" << ei << endl;
    }
    catch (const char *ec)
    {
        cout << "�쳣��������const char *=" << ec << endl;
    }
    catch (string es)
    {
        cout << "�쳣��������string=" << es << endl;
    }
    // catch (...)
    // {
    //     cout << "�����쳣,û�ܾ���ʲô�쳣" << endl;
    // }
    cout << "�������" << endl;
}
int main()
{
    test();
    return 0;
}