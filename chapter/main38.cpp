#include <iostream>

using namespace std;


class Person {
public:
    string m_name;
    int m_age;

    Person() : m_name("hello"), m_age(19) {
        cout << "调用构造函数Person()" << endl;
    }

    Person(string name, int age) : m_name("hello" + name), m_age(age - 1) {
        cout << "调用构造函数Person(string name, int age)" << endl;
    }

    void show() {
        cout << m_name << " " << m_age << endl;
    }
};

void test() {
    Person p;
    p.show();
    Person p2("world", 20);
    p2.show();
}

int main() {
    test();
    return 0;
}