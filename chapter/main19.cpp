#include "iostream"

using namespace std;

//void func(int p[][3], int len);
//void func(int (*p)[3], int len);
void func(int (*p)[3], int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "p[" << i << "][" << j << "]=" << p[i][j] << " ";
        }
        cout << endl;
    }
}


void test() {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};//可以理解为10行，1列的数组
    cout << "数组a第0个元素的地址:" << (long long) a << endl;
    cout << "数组a的地址:" << (long long) &a << endl;//和第一行相等

    cout << "数组a的第0个元素的地址+1:" << (long long) (a + 1) << " 相差：" << ((long long) (a + 1)) - ((long long) a)
         << endl;//和第一行相等相差1个int的大小，4字节
    cout << "数组a的地址+1:" << (long long) (&a + 1) << " 相差：" << ((long long) (&a + 1)) - ((long long) a)
         << endl;//和第一行相等40个字节，也就是一个a的大小

    int *p1 = a;
    cout << "对一维数组名取地址得到的是数组的地址，是行地址" << endl;
    int(*p2)[10] = &a;


    cout << endl;
    int arr[2][3] = {
            {1, 2, 3},
            {4, 5, 6}
    };//2行3列
    cout << "数组arr第0个元素的地址:" << (long long) arr << endl;
    cout << "数组arr的地址:" << (long long) &arr << endl;//和第一行相等

    cout << "数组arr的第0个元素的地址+1:" << (long long) (arr + 1) << " 相差：" << ((long long) (arr + 1)) - ((long long) arr)
         << endl;//和第一行相等相差3个int的大小，12字节
    cout << "数组arr的地址+1:" << (long long) (&arr + 1) << " 相差：" << ((long long) (&arr + 1)) - ((long long) arr)
         << endl;//和第一行相等24个字节，也就是一个arr的大小

    int(*p3)[3] = arr;

    cout << endl;
    cout << "对二维数组名取地址得到的是数组的地址，是行地址" << endl;
    int(*p4)[2][3] = &arr;

    cout << "把二维数组传递给函数" << endl;
    func(arr, 2);
}

int main() {
    test();
    return 0;
}
//数组a第0个元素的地址:140732881631088
//数组a的地址:140732881631088
//数组a的第0个元素的地址+1:140732881631092 相差：4
//数组a的地址+1:140732881631128 相差：40
//对一维数组名取地址得到的是数组的地址，是行地址
//
//        数组arr第0个元素的地址:140732881631056
//数组arr的地址:140732881631056
//数组arr的第0个元素的地址+1:140732881631068 相差：12
//数组arr的地址+1:140732881631080 相差：24
//
//对二维数组名取地址得到的是数组的地址，是行地址
//        把二维数组传递给函数
//p[0][0]=1 p[0][1]=2 p[0][2]=3
//p[1][0]=4 p[1][1]=5 p[1][2]=6