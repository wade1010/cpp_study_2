#include <iostream>

using namespace std;

//重载函数参数列表中顺序决定了操作数的位置
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

Person &operator+(Person &p, int score) {
    p.m_score += score;
    return p;
}

Person &operator+(int score, Person &p) {
    p.m_score += score;
    return p;
}

Person &operator+(Person &p1, Person &p2) {
    p1.m_score += p2.m_score;
    return p1;
}


void test() {
    Person p;
    p.m_score = 1;
    p + 10;
    p.show();
    //如上，重载的时候 Person &p, int score 顺序是这样，那么下面代码将报错
    p + 10 + p;//Invalid operands to binary expression ('void' and 'Person'
    //所以需要再写两个重载，顺序是int score,Person &p和Person &p1, Person &p2
    p.show();
}

int main() {
    test();
    return 0;
}