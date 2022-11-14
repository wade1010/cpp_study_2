#include "iostream"
#include "cstring"
//结构体数组
using namespace std;
struct people {
    char name[21];
    int age;
    double weight;
    char sex;
    bool isVIP;
};

void test() {
    people ps[3];
    memset(ps, 0, sizeof(ps));//清空整个数组
    cout << "数组表示法" << endl;
    //数组表示法
    strcpy(ps[0].name, "hello");
    ps[0].age = 22;
    ps[0].weight = 11.2;
    ps[0].sex = 'X';
    ps[0].isVIP = true;

    ps[1] = {"hulu", 3, 44.3, 'Y', true};//C++11标准的语法
    ps[2] = {"haha", 4, 21.3, 'X', false};//C++11标准的语法
    for (int i = 0; i < 3; i++) {
        cout << "姓名：" << ps[i].name << endl;
    }
    cout << "指针表示法：不常用" << endl;
    //指针表示法：不常用
    strcpy((ps + 0)->name, "ptr_huhu");
    *(ps + 1) = {"ptr_gaga", 13, 424.3, 'Y', true};//C++11标准的语法
    *(ps + 2) = {"ptr_haha", 41, 31.3, 'X', false};//C++11标准的语法
    for (int i = 0; i < 3; i++) {
        cout << "姓名：" << (*(ps + i)).name << endl;
    }
}

int main() {
    test();
    return 0;
}
/*
 数组表示法
姓名：hello
姓名：hulu
姓名：haha
指针表示法：不常用
姓名：ptr_huhu
姓名：ptr_gaga
姓名：ptr_haha
*/