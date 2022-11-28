#include <iostream>
#include <unordered_map>
using namespace std;

void test()
{
    unordered_map<int, string> m;
    m.insert({{1, "a"}, {2, "b"}, {3, "c"}, {4, "d"}});
    m.insert({{6, "e"}, {7, "f"}, {8, "g"}, {9, "h"}});

    for (int i = 0; i < m.bucket_count(); i++)
    {
        cout << "Ͱ" << i << ":";
        for (auto it = m.begin(i); it != m.end(i); it++)
            cout << it->first << "," << it->second << " ";
        cout << endl;
    }
    m.insert({{15, "a"}, {16, "b"}, {17, "c"}, {18, "d"}});
    m.insert({{25, "e"}, {26, "f"}, {27, "g"}, {28, "h"}});
    cout << endl;
    for (int i = 0; i < m.bucket_count(); i++)
    {
        cout << "Ͱ" << i << ":";
        for (auto it = m.begin(i); it != m.end(i); it++)
            cout << it->first << "," << it->second << " ";
        cout << endl;
    }
}
int main()
{
    test();
    return 0;
}
/* Ͱ0:
Ͱ1:1,a
Ͱ2:2,b
Ͱ3:3,c
Ͱ4:4,d
Ͱ5:
Ͱ6:6,e
Ͱ7:7,f
Ͱ8:8,g
Ͱ9:9,h
Ͱ10:
Ͱ11:
Ͱ12:
Ͱ13:
Ͱ14:
Ͱ15:
Ͱ16:

Ͱ0:17,c
Ͱ1:18,d 1,a
Ͱ2:2,b
Ͱ3:3,c
Ͱ4:4,d
Ͱ5:
Ͱ6:6,e
Ͱ7:7,f
Ͱ8:25,e 8,g
Ͱ9:26,f 9,h
Ͱ10:27,g
Ͱ11:28,h
Ͱ12:
Ͱ13:
Ͱ14:
Ͱ15:15,a
Ͱ16:16,b */