#include <iostream>

using namespace std;

class Person {
public:
    Person() {
        m_Name.clear();
        m_Age = 0;
        m_ptr = nullptr;
        memset(m_Hobby, 0, sizeof(m_Hobby));
    }

    Person(string name) {
        m_Name = name;
        m_Age = 0;
        m_ptr = nullptr;
        memset(m_Hobby, 0, sizeof(m_Hobby));
    }

    Person(int age) {
        m_Name.clear();
        m_Age = age;
        m_ptr = nullptr;
        memset(m_Hobby, 0, sizeof(m_Hobby));
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
    Person p = string("hello");
    p.show();
    Person p2 = 11;
    p2.show();
}

int main() {
    test();
    return 0;
}
/*
姓名：hello，年龄：0 兴趣：
姓名：，年龄：11 兴趣：
0x0
调用了析构函数
0x0
调用了析构函数
 */