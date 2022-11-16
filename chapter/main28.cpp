#include "iostream"

using namespace std;

//简单单例，线程不安全
class Person {
public:
    static Person *getInstance() {
        if (m_instance == nullptr) {
            m_instance = new Person();
        }
        return m_instance;
    }

private:
    Person() {
        cout << "111" << endl;
    }

    ~Person() {
        cout << "2222" << endl;
    }

    Person(const Person &p);//禁用拷贝构造函数
    Person &operator=(const Person &p);//禁用赋值拷贝
    static Person *m_instance;

};

Person *Person::m_instance = nullptr;

void test() {
    Person::getInstance();
}

int main() {
    test();
    return 0;
}