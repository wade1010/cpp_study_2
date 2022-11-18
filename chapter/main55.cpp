#include <iostream>

using namespace std;

//重载赋值运算符
class People {

public:
    int m_age;
    int m_score;
    int *m_ptr;

    People() {
        m_age = 18;
        m_score = 0;
        m_ptr = nullptr;
    }

    ~People() {
        if (m_ptr == nullptr) {
            delete m_ptr;
        }
    }

    void show() {
        cout << m_age << " " << m_score << endl;
        if (m_ptr != nullptr) {
            cout << *m_ptr << endl;
        }
    }

    People &operator=(const People &p) {
        //如果是自己给自己赋值
        if (this == &p) {
            return *this;
        }
        if (p.m_ptr == nullptr) {//如果源对象的指针为空，则清空目标对象的内存和指针
            if (m_ptr != nullptr) {
                delete m_ptr;
                m_ptr = nullptr;
            }
        } else {//源对象指针不为空
            //如果目标对象的指针为空，先分配内存
            if (m_ptr == nullptr) {
                m_ptr = new int;
            }
            //然后把源对象内存中的数据复制到目标对象的内存中
            memcpy(m_ptr, p.m_ptr, sizeof(int));
        }
        m_score = p.m_score;
        m_age = p.m_age;
        cout << "调用了重载赋值函数\n" << endl;
        return *this;
    }
};

void test() {
    People p1, p2;
    p1.m_score = 10;
    p1.m_age = 10;
    p1.m_ptr = new int(2);
    p1.show();
    p2.show();
    p2 = p1;
    p2.show();
}

int main() {
    test();
    return 0;
}