#include "iostream"
using namespace std;
class Person
{
public:
    Person() { cout << "调用了基类的构造函数Person()" << endl; }
    virtual void func() { cout << "调用了基类的func()" << endl; }
    ~Person() { cout << "调用了基类的析构函数~Person()" << endl; }
    // virtual ~Person() { cout << "调用了基类的析构函数~Person()" << endl; }
};

class Student : public Person
{
public:
    Student() { cout << "调用了派生类的构造函数Student()" << endl; }
    void func() { cout << "调用了派生类的func()" << endl; }
    ~Student() { cout << "调用了派生类的析构函数~Student() " << endl; }
};

void test()
{
    // Student *stu = new Student;
    // stu->~Student();
    // stu->~Student();
    // stu->~Student();
    // stu->~Student();
    // delete stu;
    // 上面代码是输出
    /*调用了基类的构造函数Person()
    调用了派生类的构造函数Student()
    调用了派生类的析构函数~Student()
    调用了基类的析构函数~Person()
    调用了派生类的析构函数~Student()
    调用了基类的析构函数~Person()
    调用了派生类的析构函数~Student()
    调用了基类的析构函数~Person()
    调用了派生类的析构函数~Student()
    调用了基类的析构函数~Person()
    调用了派生类的析构函数~Student()
    调用了基类的析构函数~Person()*/
    Person *p = new Student;
    delete p;
    //上面两行代码输出
    /*调用了基类的构造函数Person()
    调用了派生类的构造函数Student()
    调用了基类的析构函数~Person()*/
    // 可以看出,没有调用派生类的析构函数，解决的办法很简单,把基类的析构函数设置为虚函数积就行了.
}
int main()
{
    test();
    return 0;
}