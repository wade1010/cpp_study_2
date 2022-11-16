#include <iostream>

using namespace std;

class Person {
public:
    Person() {
        m_Name.clear();
        m_Age = 0;
        memset(m_Hobby, 0, sizeof(m_Hobby));
//        cout << "调用了构造函数Person() " << endl;

    }

    Person(string name) {
        Person();
        m_Name = name;
//        m_Age = 0;
//        memset(m_Hobby, 0, sizeof(m_Hobby));
//        cout << "调用了构造函数Person(string name)" << endl;
    }

    Person(string name, int age) {
        Person();
        m_Name = name;
        m_Age = age;
//        memset(m_Hobby, 0, sizeof(m_Hobby));
//        cout << "调用了构造函数Person(string name, int age)" << endl;
    }

    void show() {
        cout << "姓名：" << m_Name << "，年龄：" << m_Age << " 兴趣：" << m_Hobby << endl;
    }

    ~Person() {
//        cout << "调用了析构函数" << endl;
    }

private:
    string m_Name;
    int m_Age;
    char m_Hobby[30];
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
 *调用输出内容为：
姓名：kobe，年龄：22 兴趣：�

如果粗心的人，这事就这么过了，留下巨大的bug，因为没有调用构造函数
 16行 24行的 Person(); 的真正含义不是调用构造函数，而是创建一个匿名对象，也叫临时对象
 临时对象的特点，没有名字，创建之后立马就销毁（;后面就开始销毁）
 */