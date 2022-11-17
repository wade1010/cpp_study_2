#include <iostream>

using namespace std;

class Student {
public:
    string m_name;

    Student() {
        m_name.clear();
        cout << "调用Student()构造函数" << endl;
    }

    Student(string name) {
        m_name = name;
        cout << "调用Student(string name)构造函数" << endl;
    }

    Student(const Student &stu) {
        m_name = stu.m_name;
        cout << "调用Student(const Student &stu)拷贝构造函数" << endl;
    }
};

class Person {
public:
    string m_name;
    int m_age;
    Student m_stu;

    Person() {
        cout << "调用Person()构造函数" << endl;
    }

    Person(string name, int age, Student &stu) : m_name(name), m_age(age), m_stu(stu) {
        cout << "调用Person(string name, int age, Student stu)构造函数" << endl;
    }

    void show() {
        cout << m_name << " " << m_age << " " << m_stu.m_name << endl;
    }
};

void test() {
    Student stu("kobe");
    Person p2("world", 20, stu);
    p2.show();
}

int main() {
    test();
    return 0;
}
/*
调用Student(string name)构造函数
调用Student(const Student &stu)拷贝构造函数
调用Person(string name, int age, Student stu)构造函数
world 20 kobe*/