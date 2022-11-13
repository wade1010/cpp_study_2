#include "iostream"
using namespace std;

void test()
{
    cout << sizeof(int) << endl;
    cout << sizeof(long) << endl;
    cout << sizeof(long long) << endl;
    cout << sizeof(long double) << endl;

    //原始字面量
    string path = "C:\\Program Files\\Microsoft OneDriver\\nation";
    string path2 = R"(C:\Program Files\Microsoft OneDriver\nation)";
    cout << __cplusplus << endl;

    // C++字符串
    string str = "西施";

    //如果字符串内容都是常量,不要写加号(+),如果内容很长,可以分成多行书写
    // str = "呼啦啦" + "发哈啊" + "fadsfas"; // error: invalid operands of types 'const char [10]' and 'const char [10]' to binary 'operator+'
    // str = "呼啦啦" "发哈啊"  "fadsfas"; //没有问题,但是格式化后会分成3行

    bool a = true, b = false;
    cout << "a+a+a+a+b=" << a + a + a + a + b << endl; // a+a+a+a+b=4

    bool c = 100, d = false;
    cout << "c+d=" << c + d << endl; // c+d=1  因为c=100,最终也是1

    //找到布尔变量的内存 把里面的数据强制为8
    char *e = (char *)&b;
    *e = 255;
    cout << "b=" << b << endl; //将显示255

    *e = 256;
    cout << "b=" << b << endl; //将显示0

    //上面可以看出bool类型的本质就是unsigned char
    // true和false是C++在语法上的处理

    // 4294967295是unsigned int 的最大值
    unsigned int f = 4294967295;
    cout << f << endl; //显示 4294967295
    f += 1;
    cout << f << endl; //显示 0
    f += 1;
    cout << f << endl; //显示 1 // 值被截断,从高位截断

    int aa;
    char bb;
    bool cc;
    string dd;
    cout << &aa << endl;
    cout << &bb << endl;
    cout << &cc << endl;
    cout << &dd << endl;
}
int main()
{
    test();
    return 0;
}