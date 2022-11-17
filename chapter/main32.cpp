#include <iostream>

using namespace std;

class Person {
public:
    Person() {
        m_Name.clear();
        m_Age = 0;
        memset(m_Hobby, 0, sizeof(m_Hobby));
        cout << "调用了构造函数Person() " << endl;

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
        cout << "调用了析构函数" << endl;
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
start
调用了构造函数Person()
调用了析构函数
end
姓名：kobe，年龄：22 兴趣：�
调用了析构函数

 可以从上面输出结果看出
start
调用了构造函数Person()
调用了析构函数
end
 上面输出是25行 Person();  临时对象 创建和销毁时调用的

 */