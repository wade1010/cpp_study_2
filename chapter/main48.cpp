#include <iostream>

using namespace std;

class Person {
    const static int m_age = 10;
public:
    string m_name;

    Person(const string &name) {
        m_name = name;
    }

    void showAge() {
        cout << " 222" << endl;
    }

    void showName() {
        cout << m_name << endl;
    }

    void showName2() {
        if (this == nullptr) {
            return;
        }
        cout << m_name << endl;
    }

};


void test() {
    Person *ptr = nullptr;
    ptr->showAge();
//    ptr->showName();//报错
    ptr->showName2();//报错 为了保证程序健壮性，可以在成员函数中增加判断this指针是否为空的代码
}

int main() {
    test();
    return 0;
}