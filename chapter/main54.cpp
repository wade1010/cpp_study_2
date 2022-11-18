#include <iostream>

using namespace std;

//左移运算符 cout
class People {
    friend ostream &operator<<(ostream &cout, const People &p);

    int m_age;
    int m_score;
public:
    People() {
        m_age = 18;
        m_score = 0;
    }

    ostream &operator<<(ostream &cout) {
        cout << m_age << " " << m_score << endl;
        return cout;
    }
};

ostream &operator<<(ostream &cout, const People &p) {
    cout << p.m_age << " " << p.m_score << endl;
    return cout;
}

void test() {
    People p;
    cout << p << endl;
    p << cout << endl;//如果是成员函数的重载，位置就不对了。
}

int main() {
    test();
    return 0;
}