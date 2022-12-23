#include <iostream>
#include <queue>
#include <deque>
#include <list>
using namespace std;
class girl
{
public:
    int m_bh;
    string m_name;
    girl(const int &bh, const string &name) : m_bh(bh), m_name(name) {}
};
void test()
{
    // template<class T,class _Container=deque<T>>
    // class queue{
    //  ......
    // }
    //第一个模板参数T:元素的数据类型.
    // 第二个模板参数_Container:底层容器的类型,可以 是std:deque,可以用std::list还可以用自定义的类模板.

    queue<girl, list<girl>> q;    //物理结构为链表
    queue<girl, deque<girl>> q2;  //物理结构为数组.
    queue<girl> q3;               //物理结构为数组
    queue<girl, vector<girl>> q4; //物理结构为数组,!!!!!!！!!!！!！!！!!!！!！!!这个不行
                                  /*    q4.push(girl(1, "a"));
                                    q4.push(girl(2, "b"));
                                    q4.push(girl(3, "c"));
                                    while (!q4.empty())
                                    {
                                        cout << q4.front().m_bh << "  " << q4.front().m_name << endl;
                                        q4.pop();
                                    }
                                    error: 'class std::vector<girl>' has no member named 'pop_front'; did you mean 'front'?
                                   c.pop_front();
                                   ~~^~~~~~~~~
                                   front */

    q3.push(girl(1, "a"));
    q3.push(girl(2, "b"));
    q3.push(girl(3, "c"));
    while (!q3.empty())
    {
        cout << q3.front().m_bh << "  " << q3.front().m_name << endl;
        q3.pop();
    }
}
int main()
{
    test();
    return 0;
}
