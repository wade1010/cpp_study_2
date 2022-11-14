#include "iostream"

using namespace std;

void func(int (*p)[3][4], int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 4; k++) {
                cout << p[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

//多维数组
void test() {
    int arr[2][3][4];
//初始化
    int ii = 0;
    memset(arr, 0, sizeof(arr));//c++11中需要引入<string>  c97不需要
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                arr[i][j][k] = ii++;
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) {
                cout << arr[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << "多维数组传递给函数" << endl;
    func(arr, 2);

    //对三维数组名取地址得到的是数组的地址，是行地址
    int (*aa)[2][3][4] = &arr;
    cout << ((long long) (aa + 1)) - (long long) aa << endl;//相差96字节
}

int main() {
    test();
    return 0;
}
//0 1 2
//3 4 5
//
//6 7 8
//9 10 11
//
//12 13 14
//15 16 17
//
//18 19 20
//21 22 23
//
//多维数组传递给函数
//0 1 2 0
//3 4 5 0
//0 0 0 0
//
//6 7 8 0
//9 10 11 0
//0 0 0 0
//
//96