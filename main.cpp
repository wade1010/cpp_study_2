#include <iostream>

using namespace std;

class Person {
    friend int main();//友元全局函数

    friend void test();//友元全局函数

    friend class Student;//友元类

public:
    string m_name;

    Person() {
        m_name = "hello";
        m_age = 100;
    }

private:
    int m_age;

    void showAge() {
        cout << m_age << endl;
    }
};

class Student {
public:
    void callPersonFunc(const Person &p) {
        cout << p.m_age << endl;
    }
};

void test() {
    Person p;
    p.showAge();
}

int main() {
    Person p;
    p.showAge();
    test();

    Student s;
    s.callPersonFunc(p);

    return 0;
}