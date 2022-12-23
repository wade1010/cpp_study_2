#include <iostream>
#include <cstring>
using namespace std;

void test()
{
    struct st_girl
    {
        int age;
        char name[20];
    } girl;

    cout << "�ṹ���С:" << sizeof(st_girl) << endl;

    string buffer;
    for (int i = 0; i < 10; i++)
    {
        memset(&girl, 0, sizeof(girl));
        girl.age = 10 + i;
        sprintf(girl.name, "ѡ��%02d", i);
        buffer.append((char *)&girl, sizeof(girl));
    }
    cout << "buffer.capacity()=" << buffer.capacity() << endl;
    cout << "buffer.size()=" << buffer.size() << endl;

    for (int i = 0; i < 10; i++)
    {
        //�������ն˶����ݸ��Ƶ��ṹ��
        memcpy((char *)&girl, buffer.data() + i * sizeof(girl), sizeof(girl));
        // memcpy((char *)&girl, buffer.c_str() + i * sizeof(girl), sizeof(girl));
        // buffer.copy((char *)&girl, sizeof(girl), i * sizeof(girl));
        cout << "age=" << girl.age << ",name=" << girl.name << endl;
    }
}
int main()
{
    test();
    return 0;
}