#include <iostream>
#include <cstddef>

using namespace std;

class alloc {};

template <class T, class Alloc = alloc, size_t BufSiz = 0>
class deque
{
public:
    deque() { cout << "deque "; }
};

template <class T, class Sequence>
class stack;

template <class T, class Sequence>
bool operator==(const stack<T, Sequence> &x, const stack<T, Sequence> &y);

template <class T, class Sequence>
bool operator<(const stack<T, Sequence> &x, const stack<T, Sequence> &y);

template <class T, class Sequence = deque<T>>
class stack
{
    friend bool operator== <> (const stack&, const stack&);
    friend bool operator< <> (const stack&, const stack&);
//    friend bool operator== <T> (const stack<T>&, const stack<T>&);
//    friend bool operator< <T> (const stack<T>&, const stack<T>&);
public:
    stack() { cout << "stack" << endl; }
private:
    Sequence c;
};

template <class T, class Sequence>
bool operator==(const stack<T, Sequence> &x, const stack<T, Sequence> &y)
{
    cout << "operator==" << endl;
    return true;
}

template <class T, class Sequence>
bool operator<(const stack<T, Sequence> &x, const stack<T, Sequence> &y)
{
    cout << "operator<" << endl;
    return true;
}

int main()
{
    stack<int> x;
    stack<int> y;

    cout << (x == y) << endl;
    cout << (x < y) << endl;

//    stack<char> z;
//    cout << (x == z) << endl;
//    cout << (x < z) << endl;

    return 0;
}
