#include <iostream>

using namespace std;

//操作内存修改私有属性
class Person {
    int m_age;
    int m_score;
public:
    string m_name;

    Person(string name, int age) : m_name(name), m_age(age), m_score(0) {
    }

    void show() const {
        cout << m_name << " " << m_age << " " << m_score << endl;
    }
};

void test() {
    Person p("hello", 22);
    p.show();
    //直接操作内存来修改private属性 m_age
    *((int *) &p) = 108;
    p.show();
    //直接操作内存来修改private属性 m_score
    *((int *) &p + 1) = 100;
    p.show();
}

int main() {
    test();
    return 0;
}