#include <iostream>

using namespace std;

class Person {
public:
    string m_name;
    int m_age;

    Person() {
    }

    Person(string name, int age) {
        m_name = name;
        m_age = age;
    }

    const Person &pk(const Person &p) const {
        return this->m_age > p.m_age ? *this : p;
    }

};

void test() {
    Person p1("a", 1), p2("b", 2), p3("c", 3), p4("d", 4);
    p1.pk(p2).pk(p3);
}

int main() {
    test();
    return 0;
}