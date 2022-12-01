#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str = "123"; // 不会抛出异常。
    // string str = "";     // 将抛出Invalid_argument异常。
    // string str = "253647586946334221002101";  // 将抛出out_of_range异常。

    try
    {
        int x = stoi(str); // 把string字符串转换为整数。
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
        cout << " something else…" << endl;
    }
}