#include <iostream>

using namespace std;

class Person {
public:
    Person() {
        m_Name.clear();
        m_Age = 0;
        m_ptr = nullptr;
        memset(m_Hobby, 0, sizeof(m_Hobby));
        cout << "调用了构造函数Person() 1" << endl;
    }

    Person(string name) {
        Person();
        m_Name = name;
//        m_Age = 0;
//        memset(m_Hobby, 0, sizeof(m_Hobby));
//        cout << "调用了构造函数Person(string name)" << endl;
    }

    Person(string name, int age) {
        cout << "start" << endl;
        Person();
        cout << "end" << endl;
        m_Name = name;
        m_Age = age;
//        memset(m_Hobby, 0, sizeof(m_Hobby));
//        cout << "调用了构造函数Person(string name, int age)" << endl;
    }

    void show() {
        cout << "姓名：" << m_Name << "，年龄：" << m_Age << " 兴趣：" << m_Hobby << endl;
    }

    ~Person() {
//        delete m_ptr;//直接写也行，因为对空指针delete是安全的
        cout << m_ptr << endl;
        if (m_ptr != nullptr) {//这样写也行
            delete m_ptr;
            m_ptr = nullptr;
        }
        cout << "调用了析构函数" << endl;
    }

private:
    string m_Name;
    int m_Age;
    char m_Hobby[30];
    int *m_ptr;
};

void test() {
    Person p("kobe", 22);
    p.show();
}

int main() {
    test();
    return 0;
}
/*
start
调用了构造函数Person() 1
0x0
调用了析构函数
end
姓名：kobe，年龄：22 兴趣：
0x0
调用了析构函数
 */