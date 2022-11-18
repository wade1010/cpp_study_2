#include <iostream>

using namespace std;

//为整型动态分配内存
void *operator new(size_t size) {
    cout << "调用了重载的new：" << size << "字节" << endl;
    void *p = malloc(size);
    cout << "申请到的内存地址是：" << p << endl;
    return p;
}

void operator delete(void *ptr) {
    cout << "调用了重载的delete" << endl;
//    if (ptr == 0) {//这是模拟C++的封装，所以C++中delete空指针也是安全的
    if (ptr == nullptr) {//这是模拟C++的封装，所以C++中delete空指针也是安全的
        return;
    }
    free(ptr);
}

void test() {
    //对于我们来说，C++的new和delete缺省屏蔽了全部细节，如果我们重载了new和delete运算符，就可以
    //用自己的代码申请和释放内存了。
    int *p = new int(1);
    cout << "p=" << p << ",*p=" << *p << endl;
    cout << "p=" << (void *) p << ",*p=" << *p << endl;
    delete p;


}

int main() {
    test();
    return 0;
}
/*
调用了全局重载的new：4字节
申请到的内存地址是：0x7ff198c05910
p=0x7ff198c05910,*p=1
p=0x7ff198c05910,*p=1
调用了全局重载的delete

调用了类重载的new：8字节
申请到的内存地址是：0x7ff198c05910
调用了构造函数Person(int age, int score)
p2的地址是0x7ff198c05910 1 2
调用了析构函数~Person()
调用了类重载的delete
*/