#include <iostream>
#include <iomanip>
#include <cstring>
#include <chrono>
#include <sys/time.h>
using namespace std;
//��ȡʱ���
void test()
{
    // chrono::time_point<chrono::system_clock, chrono::seconds> tpMicro = chrono::time_point_cast<chrono::milliseconds>(chrono::system_clock::now());
    // use auto
    //�뼶��
    auto tpSec = chrono::time_point_cast<chrono::seconds>(chrono::system_clock::now());
    time_t timestamp1 = tpSec.time_since_epoch().count();
    cout << timestamp1 << endl;
    //���뼶��
    auto tpMicro = chrono::time_point_cast<chrono::milliseconds>(chrono::system_clock::now());
    time_t timestamp2 = tpMicro.time_since_epoch().count();
    cout << timestamp2 << endl;
}
int main()
{
    test();
    return 0;
}
