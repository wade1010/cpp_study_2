#include "iostream"

using namespace std;

int &func(int &a) {
    a++;
    return a;
}

const int &func2(int &a) {
    a++;
    return a;
}

void test() {
    int a = 3;
    func(a) = 10;
    cout << a << endl;
}

void test2() {
    int a = 3;
//    func2(a) = 10;//返回的是const,不能修改
    cout << a << endl;
}

int main() {
    test();
    test2();
    return 0;
}