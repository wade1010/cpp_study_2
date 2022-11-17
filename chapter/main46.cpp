#include <iostream>

using namespace std;

class Person {
    static int m_age;
public:
    string m_name;

    Person(const string &name, int age) {
        m_name = name;
        m_age = age;
    }

    void showAge() {
        cout << m_name << endl;
    }

    static void showAge2() {
//        cout << m_name << endl;//Invalid use of member 'm_name' in static member function
        cout << m_age << endl;
    }
};

int Person::m_age = 1;

void test() {
    Person p("hello", 22);
    p.showAge();

    //不创建成员也能访问静态函数
    Person::showAge2();
//    Person::m_age;//报错'm_age' is a private member of 'Person'
}

int main() {
    test();
    return 0;
}