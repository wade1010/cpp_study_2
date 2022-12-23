#include <iostream>
#include <cstring>
using namespace std;
//用string容器存放结构体数据
void test()
{
    struct st_girl
    {
        int id;
        char name[30];
    } girl;
    cout << "结构体的大小:" << sizeof(st_girl) << endl;

    string buffer;
    //生成10个女生信息,存入buffer中.
    for (int i = 0; i < 10; i++)
    {
        memset(&girl, 0, sizeof(st_girl));
        girl.id = i;
        sprintf(girl.name, "美女%02d", i);
        buffer.append((char *)&girl, sizeof(st_girl));
    }
    cout << "buffer.capacity()" << buffer.capacity() << endl;
    cout << "buffer.size()" << buffer.size() << endl;

    //用一个循环,把buffer容器中的全部数据取出来
    for (int i = 0; i < 10; i++)
    {
        memset(&girl, 0, sizeof(st_girl));
        //把容器中的数据复制到结构体中
        // memcpy(&girl, buffer.data() + i * sizeof(st_girl), sizeof(st_girl));
        buffer.copy((char *)&girl, sizeof(st_girl), i * sizeof(st_girl));
        cout << "id=" << girl.id << ",name=" << girl.name << endl;
    }
}
int main()
{
    test();
    return 0;
}