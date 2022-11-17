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
/*
调用构造函数Person(string name, int age)
调用了析构函数
*/
//    Person p = Person("hello", 20);//显示创建对象

/*
调用构造函数Person()
调用构造函数Person(string name, int age)
调用了析构函数
调用了析构函数
 */
    Person p;//创建对象
    p = Person("hello", 20);//创建匿名对象，然后给现有的对象赋值
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