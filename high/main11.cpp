#include <iostream>
#include <unordered_map>
using namespace std;

template <class K, class V>
using umap = unordered_map<K, V>;

void test()
{
    umap<int, string> m;
    cout << m.bucket_count() << endl;
    size_t itmp = m.bucket_count();
    for (int i = 0; i < 2000000; i++)
    {
        char name[50];
        sprintf(name, "user%d", i);
        m.emplace(i, name);
        if (itmp != m.bucket_count())
        {
            cout << m.bucket_count() << endl;
            itmp = m.bucket_count();
        }
    }
}
int main()
{
    test();
    return 0;
}