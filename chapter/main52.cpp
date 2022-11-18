#include <iostream>

using namespace std;

//成员函数重载+ -
class Person {
public:
    Person() {
        m_score = 0;
        m_name.clear();
    }

    void show() {
        cout << m_name << " " << m_score << endl;
    }

    void operator+(int score) {
        this->m_score += score;
    }

    Person &operator-(int score) {
        this->m_score -= score;
        return *this;
    }

    int m_score;
    string m_name;
};


void test() {
    Person p;
    p.m_score = 1;
    p + 10;
    p.show();
    p = p - 1 - 2;//同下
//    p = operator-(operator-(p, 1), 2);
    p.show();
}

int main() {
    test();
    return 0;
}