#include <iostream>
#include <vector>
using namespace std;
void test()
{
    vector<int> v1;
    cout << v1.capacity() << "," << v1.size() << endl;
    vector<int> v2(8);
    cout << v2.capacity() << "," << v2.size() << endl;

    // vector<int> v3({1, 2, 3, 4, 5});//м╛об
    vector<int> v3 = {1, 2, 3, 4, 5};
    cout << v3.capacity() << "," << v3.size() << endl;

    vector<int> v4;
    v4.reserve(1000);
    v4.push_back(1);
    v4.push_back(2);
    v4.push_back(3);
    v4.push_back(4);
    cout << v4.capacity() << "," << v4.size() << endl;
    vector<int>(v4).swap(v4);
    cout << v4.capacity() << "," << v4.size() << endl;

    vector<int> v5;
    cout << "v5.data()=" << v5.data() << endl;

    vector<int> v6 = {1, 2, 3, 4, 5};
    cout << "v6.data()=" << v6.data() << endl;

    for (int i = 0; i < v6.size(); i++)
    {
        cout << v6[i] << " ";
    }
    cout << endl;
    v6.data()[0] = 100;
    v6.data()[1] = 200;
    *(v6.data() + 2) = 300;
    *(v6.data() + 3) = 400;
    for (int i = 0; i < v6.size(); i++)
    {
        cout << v6[i] << " ";
    }
    cout << endl;
}
int main()
{
    test();
    return 0;
}
