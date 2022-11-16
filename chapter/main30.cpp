#include <iostream>
#include <cstring>

using namespace std;

//创建对象的时候不要再对象名后面加空的圆括号，编译器误认为是声明函数。
// （如果没有构造函数、构造函数没有参数、构造函数的参数都有默认参数）
class Person {
public:
    Person() {
        m_Name.clear();
        m_Age = 0;
        memset(m_Hobby, 0, sizeof(m_Hobby));
    }

    Person(string name) {
        m_Name = name;
        m_Age = 0;
        memset(m_Hobby, 0, sizeof(m_Hobby));
        cout << "调用了构造函数" << endl;
    }

    Person(string name, int age) {
        m_Name = name;
        m_Age = age;
        memset(m_Hobby, 0, sizeof(m_Hobby));
        cout << "调用了构造函数" << endl;
    }

    void show() {
        cout << "show" << endl;
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
    Person p();//编译不会报错
//    编译报错如下 empty parentheses interpreted as a function declaration
//意思就是 空括号被解释为函数声明
//    p.show();//调用不了
//其实Person p();的意思是声明一个函数返回值为Person的函数，函数名叫p
}

int main() {
    test();
    return 0;
}