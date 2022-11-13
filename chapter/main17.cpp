#include "iostream"
using namespace std;

void test()
{
    int bh[2][3];
    bh[0][0] = 11;
    bh[0][1] = 12;
    bh[0][2] = 13;
    bh[1][0] = 20;
    bh[1][1] = 21;
    bh[1][2] = 22;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "&bh[" << i << "][" << j << "]=" << (long long)&bh[i][j] << endl;
        }
    }
    //骚操作
    int *p = (int *)bh;
    for (int i = 0; i < 6; i++)
    {
        cout << "p[" << i << "]=" << (long long)&p[i] << " " << p[i] << endl;
    }
}
int main()
{
    test();
    return 0;
}