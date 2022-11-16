#include "iostream"

using namespace std;

class Person {
public:
    ~Person() {
        cout << "调用了析构函数" << endl;
    }
};

void test() {
    Person p;
    p.~Person();//手动调用析构函数
}

int main() {
    test();
    return 0;
}
//调用了析构函数
//调用了析构函数