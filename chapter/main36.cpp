#include <iostream>

using namespace std;

class Person {
public:
    Person() {
        m_Name.clear();
        m_Age = 0;
        m_ptr = nullptr;
        memset(m_Hobby, 0, sizeof(m_Hobby));
        cout << "调用构造函数Person()" << endl;
    }

    Person(string name, int age) {
        m_Name = name;
        m_Age = age;
        m_ptr = nullptr;
        memset(m_Hobby, 0, sizeof(m_Hobby));
        cout << "调用构造函数Person(string name, int age)" << endl;
    }

    void show() {
        cout << "姓名：" << m_Name << "，年龄：" << m_Age << " 兴趣：" << m_Hobby << endl;
    }

    ~Person() {
        cout << "调用了析构函数" << endl;
    }

private:
    string m_Name;
    int m_Age;
    char m_Hobby[30];
    int *m_ptr;
};

void test() {

    Person p = {"hello", 19};
    Person p2{"hello", 19};
    Person *ptr = new Person{"hello", 19};
}

int main() {
    test();
    return 0;
}
/*

 */