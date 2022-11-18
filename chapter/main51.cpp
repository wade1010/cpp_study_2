#include <iostream>

using namespace std;

//非成员函数重载+ -
class Person {
public:
    Person() {
        m_score = 0;
        m_name.clear();
    }

    void show() {
        cout << m_name << " " << m_score << endl;
    }

    int m_score;
    string m_name;
};

//全局重载+号
void operator+(Person &p, int score) {
    p.m_score += score;
}

//全局重载-号
Person &operator-(Person &p, int score) {
    p.m_score -= score;
    return p;
}

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