#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "123"; // �����׳��쳣��
    // string str = "";     // ���׳�Invalid_argument�쳣��
    // string str = "253647586946334221002101";  // ���׳�out_of_range�쳣��

    try
    {
        int x = stoi(str); // ��string�ַ���ת��Ϊ������
        cout << "x=" << x << endl;
    }
    catch (invalid_argument &)
    {
        cout << " invalid_argument. \n";
    }
    catch (out_of_range &)
    {
        cout << " out of range. \n";
    }
    catch (...)
    {
        cout << " something else��" << endl;
    }
}