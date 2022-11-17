#include <iostream>

using namespace std;

//函数以值的方式返回对象时，可能会调用拷贝构造函数（VS会调用，Linux不会，g++编译器做了优化）
class Person {
public:
    Person() {
        m_Name.clear();
        m_Age = 0;
        cout << "调用构造函数Person()" << endl;
    }

    Person(const Person &p) {
        m_Name = p.m_Name;
        m_Age = p.m_Age;
        cout << "调用了拷贝构造函数" << endl;
    }

    void show() {
        cout << "姓名：" << m_Name << "，年龄：" << m_Age << endl;
    }

    ~Person() {
        cout << "调用了析构函数" << endl;
    }

    string m_Name;
    int m_Age;
};

Person func() {
    Person p;
    p.m_Name = "hello";
    p.m_Age = 19;
    cout << &p << endl;
    return p;
}

void test() {
    Person p = func();
    p.show();
    cout << &p << endl;
}

int main() {
    test();
    return 0;
}
/*
调用构造函数Person()
0x7ffee9534780
姓名：hello，年龄：19
0x7ffee9534780
调用了析构函数
 */