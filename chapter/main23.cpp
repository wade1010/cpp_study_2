#include "iostream"

using namespace std;
struct people {
    char name[21];
    int age;
    double weight;
    char sex;
    bool isVIP;
};

void test() {
    people *p = new people;
    memset(&p, 0, sizeof(people));
    //最常用的初始值不适用memset，而是下面
    people *p2 = new people({});//也可以 new people({0});

    delete p;
    delete p2;
}

int main() {
    test();
    return 0;
}