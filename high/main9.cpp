#include <iostream>
using namespace std;

namespace
{
    template <class _Ty>
    class List;

    template <class _Ty>
    class ListIterator;

    // 节点类。
    template <class _Ty>
    class ListNode
    {
        friend class List<_Ty>;
        friend class ListIterator<_Ty>;

    public:
        ListNode() : _Value(_Ty()), _Next(nullptr), _Prev(nullptr) {}
        ListNode(_Ty V, ListNode *next = nullptr, ListNode *prev = nullptr) : _Value(V), _Next(next), _Prev(prev) {}

    private:
        _Ty _Value;
        ListNode *_Next;
        ListNode *_Prev;
    };

    // 迭代器。
    template <class _Ty>
    class ListIterator
    {
        typedef ListIterator<_Ty> _It;

    public:
        ListIterator() : _Ptr(nullptr) {}
        ListIterator(ListNode<_Ty> *_P) : _Ptr(_P) {}

    public:
        _It &operator++()
        {
            _Ptr = _Ptr->_Next;
            return *this;
        }
        _It &operator--()
        {
            _Ptr = _Ptr->Prev;
            return *this;
        }
        _Ty &operator*()
        {
            return (_Ptr->_Value);
        }
        bool operator!=(const _It &it)
        {
            return _Ptr != it._Ptr;
        }
        bool operator==(const _It &it)
        {
            return _Ptr == it._Ptr;
        }
        ListNode<_Ty> *_Mynode()
        {
            return _Ptr;
        }

    private:
        ListNode<_Ty> *_Ptr;
    };

    // 链表类。
    template <class _Ty>
    class List
    {
    public:
        typedef ListNode<_Ty> *_Nodeptr;
        typedef ListIterator<_Ty> iterator;

    public:
        List() : _Size(0)
        {
            CreateHead();
        }
        List(size_t n, const _Ty &x = _Ty()) : _Size(0)
        {
            CreateHead();
            insert(begin(), n, x);
        }
        List(const _Ty *first, const _Ty *last) : _Size(0)
        {
            CreateHead();
            while (first != last)
                push_back(*first++);
        }
        List(iterator first, iterator last)
        {
            CreateHead();
            while (first != last)
            {
                push_back(*first);
                ++first;
            }
        }
        List(List<_Ty> &lt) : _Size(0)
        {
            CreateHead();
            List<_Ty> tmp(lt.begin(), lt.end());
            this->swap(tmp);
        }
        ~List()
        {
            clear();
            delete _Head;
            _Size = 0;
        }

    public:
        void push_back(const _Ty &x)
        {
            insert(end(), x);
        }
        void pop_back()
        {
            erase(--end());
        }
        void push_front(const _Ty &x)
        {
            insert(begin(), x);
        }
        void pop_front()
        {
            erase(begin());
        }
        _Ty &front()
        {
            return *begin();
        }
        const _Ty &front() const
        {
            return *begin();
        }
        _Ty &back()
        {
            return *--end();
        }
        const _Ty &back() const
        {
            return *--end();
        }

    public:
        size_t size() const
        {
            return _Size;
        }
        bool empty() const
        {
            return (size() == 0);
        }

    public:
        iterator begin()
        {
            return iterator(_Head->_Next);
        }
        iterator end()
        {
            return iterator(_Head);
        }
        void clear()
        {
            erase(begin(), end());
        }

    public:
        //在_P位置前插入值为x的节点
        iterator insert(iterator _P, const _Ty &x)
        {
            _Nodeptr cur = _P._Mynode();
            _Nodeptr _S = new ListNode<_Ty>(x);

            _S->_Next = cur;
            _S->_Prev = cur->_Prev;
            _S->_Prev->_Next = _S;
            _S->_Next->_Prev = _S;

            _Size++;
            return iterator(_S);
        }
        void insert(iterator _P, size_t n, const _Ty &x = _Ty())
        {
            while (n--)
                insert(_P, x);
        }
        //删除_P位置的节点，返回该节点的下一个节点位置
        iterator erase(iterator _P)
        {
            _Nodeptr cur = _P._Mynode();
            _Nodeptr next_node = cur->_Next;

            cur->_Prev->_Next = cur->_Next;
            cur->_Next->_Prev = cur->_Prev;
            delete cur;

            _Size--;

            return iterator(next_node);
        }
        iterator erase(iterator first, iterator last)
        {
            while (first != last)
            {
                first = erase(first);
            }
            return first;
        }
        void swap(List<_Ty> &lt)
        {
            std::swap(_Head, lt._Head);
            std::swap(_Size, lt._Size);
        }

    protected:
        void CreateHead()
        {
            _Head = new ListNode<_Ty>;
            _Head->_Prev = _Head->_Next = _Head;
        }

    private:
        _Nodeptr _Head;
        size_t _Size;
    };
};

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    List<int> la(arr + 2, arr + 10);
    List<int> lb(la);

    for (auto elem : la)
        cout << elem << " ";
    cout << endl;

    for (auto elem : lb)
        cout << elem << " ";
    cout << endl;
}