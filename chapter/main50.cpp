#include <iostream>

using namespace std;

//步骤1 Person类前置
class Person;

//步骤2 把Student类放在Person前
class Student {
public:
//    void callPersonFunc1(const Person &p) {
//        cout << "callPersonFunc1" << p.m_age << endl;
//    }
//
//    void callPersonFunc2(const Person &p) {
//        cout << "callPersonFunc2" << p.m_age << endl;
//    }
//改成声明，类外实现
    void callPersonFunc1(const Person &p);

    void callPersonFunc2(const Person &p);
};

//步骤3 把Student类的成员函数的函数体从Student类中拿出来 ,放在定义Person类的代码后面
//往下看 因为如果不放在定义Person类代码后面，就会报错，member access into incomplete type 'const Person'

//步骤4 把Student类的成员函数声明为Person类的友元函数

class Person {
    friend void Student::callPersonFunc1(const Person &p);

    friend void Student::callPersonFunc2(const Person &p);

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

void Student::callPersonFunc1(const Person &p) {
    cout << "callPersonFunc1   " << p.m_age << endl;
}

void Student::callPersonFunc2(const Person &p) {
    cout << "callPersonFunc2   " << p.m_age << endl;
}


void test() {
    Person p;
    Student stu;
    stu.callPersonFunc1(p);
    stu.callPersonFunc2(p);
}

int main() {
    test();
    return 0;
}