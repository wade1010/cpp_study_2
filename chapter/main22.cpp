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
    struct people p;
    memset(&p, 0, sizeof(p));
    bzero(&p, sizeof(people));
    cout << p.age << endl;
    p.age = 11;
    struct people p2;
    memcpy(&p2, &p, sizeof(p));
    cout << p2.age << endl;
}

int main() {
    test();
    return 0;
}