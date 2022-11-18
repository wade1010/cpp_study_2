#include <iostream>

using namespace std;

void show(string str) {
    cout << "普通函数：" << str << endl;
}

class Person {
public:
    void operator()(string str) {
        cout << "重载函数：" << str << endl;
    }

};

void test() {
    /* show("hello");
     Person show;
     show("hello");*/
    /*上面输出
    普通函数：hello
    重载函数：hello*/

    Person show;
    ::show("hello");//这一行想要调用全局函数，在方法面前加上::
    show("hello");
    /*上面输出
    普通函数：hello
    重载函数：hello*/
}

int main() {
    test();
    return 0;
}