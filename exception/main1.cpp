#include <iostream>
using namespace std;
//异常
void test()
{
    try
    {
        int ii = 0;
        cout << "请输入选择,1:cosnt char*抛出异常,2:int异常,3:stirng异常,4:正常" << endl;
        cin >> ii;
        if (ii == 1)
        {
            throw "该抛就抛";
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
        cout << "异常的类型是int=" << ei << endl;
    }
    catch (const char *ec)
    {
        cout << "异常的类型是const char *=" << ec << endl;
    }
    catch (string es)
    {
        cout << "异常的类型是string=" << es << endl;
    }
    // catch (...)
    // {
    //     cout << "捕获到异常,没管具体什么异常" << endl;
    // }
    cout << "程序结束" << endl;
}
int main()
{
    test();
    return 0;
}