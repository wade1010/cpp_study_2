#include "iostream"
#include <cstring>

using namespace std;
//结构体中的指针
struct People {
    int a;
    int *p;
};

void test() {
    People people;
    people.p = new int[100];
    cout << "sizeof(people)=" << sizeof(people) << endl;//16个字节 ，肯定是有问题

    //结构体清零
    cout << "调用前：people.a:" << people.a << ",people.p:" << people.p << endl;
    memset(&people, 0, sizeof(people));
    cout << "调用后：people.a:" << people.a << ",people.p:" << people.p << endl;

    //上面的清零是有问题的  输出结果如下，这个指针都给清零了，导致p之前所指向的内存就不能被操作了，内存泄漏
//    sizeof(people) = 16
//    调用前：people.a:0, people.p:0x7fb1e6405910
//    调用后：people.a:0, people.p:0x0

//应该这么做
    People people2;
    people2.a = 3;
    people2.p = new int[100];
    cout << endl;
    cout << "调用前：people2.a:" << people2.a << ",people2.p:" << people2.p << endl;
    people2.a = 0;//清零成员a
    memset(people2.p, 0, 100 * sizeof(people2.p));//清空p指向的内存中的内容
    cout << "调用后：people2.a:" << people2.a << ",people2.p:" << people2.p << endl;


    delete[] people.p;//释放动态分配的内存
}

struct stringTest {
    string name;
};

void test2() {

    stringTest st;
    st.name = "葫芦娃";
    cout << "name=" << st.name << endl;
    //我这里演示是没有问题的，但是视频里面是有问题的 视频里面是VS
    memset(&st, 0, sizeof(st));

    st.name = "舅爷爷";
    cout << "name=" << st.name << endl;
}

int main() {
    cout << "执行test()" << endl;
    test();
    cout << "执行test2()" << endl;
    test2();
    return 0;
}
/*
 执行test()
sizeof(people)=16
调用前：people.a:175696784,people.p:0x7ff71bc05910
调用后：people.a:0,people.p:0x0

调用前：people2.a:3,people2.p:0x7ff71bc05aa0
调用后：people2.a:0,people2.p:0x7ff71bc05aa0
执行test2()
name=葫芦娃
name=舅爷爷
 */