#include "iostream"

using namespace std;

void func1(int no, string str) {
    cout << no << " " << str << endl;
}

void func2(int *no, string *str) {
    cout << *no << " " << *str << endl;
}


void func3(int &no, string &str) {
    cout << no << " " << str << endl;
}

//普通数据类型传参
void test() {
    int no = 3;
    string msg = "hello";
    func1(no, msg);
}

void test2Func1(int **p) {
    *p = new int(10);//p是二级指针，存放指针的地址
    cout << "内存地址为：" << *p << "内存中的值为：" << **p << endl;
}

void test2Func2(int *&p) {
    p = new int(10);
    cout << "内存地址为：" << p << "内存中的值为：" << *p << endl;
}

//二级指针
void test2() {
    int *p = nullptr;//存放在子函数中动态分配内存的地址
    test2Func1(&p);//传地址，实参填写指针p的地址
    test2Func2(p);//传引用，实参填指针p
}

void constFunc1(const int no, const string str) {
    cout << no << " " << str << endl;
}

void constFunc2(const int *no, const string *str) {
    cout << *no << " " << *str << endl;
}


void constFunc3(const int &no, const string &str) {
    cout << no << " " << str << endl;
}

void constFunc3_2(const int &no, string &str) {
    cout << no << " " << str << endl;
}

//const
void test3() {
    /*int no = 1;
    string msg = "hello";//可以调用
    constFunc1(no, msg);//可以调用
    constFunc2(&no, &msg);//可以调用
    constFunc3(no, msg);//可以调用
     */

    //不声明变量
//    func1(1, "hello");//可以调用
//    func2(&2, &"hello");//不可以调用  annot take the address of an rvalue

//不可以调用  no matching function for call to 'func3'
// candidate function not viable: expects an l-value for 1st argument
//    func3(3, "hello");

    constFunc1(1, "hello");//可以
//    constFunc2(&2, &"hello");//不可以
    constFunc3(3, "hello");//可以
}


int main() {
//    test();//普通数据类型传参
//    test2();//二级指针
    test3();//const

//    int &r=9;//编译失败
    const int &r = 9;//OK 编译器会创建临时变量，相当于 int tmp=9;const int &r = tmp;

//    const int r2 = "string";//错误，数据对象的类型时正确的，但不是左值。

    constFunc3('a', "hello");//数据对象的类型不正确，但可以转换为正确的类型。

    //这里'a'可以正确转换，
//     形参是string,但是实参是C风格的字符串，constFunc3_2的str参数没有const，所以无法转换,报错如下：
//    no known conversion from 'const char [6]' to 'std::__1::string
//    constFunc3_2('a', "hello");
    return 0;
}