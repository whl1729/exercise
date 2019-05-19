#include <iostream>

using std::cout;
using std::endl;

template <class T>
struct add
{
    T operator()(const T &x, const T &y) const { return x + y; }
};

template <class T>
struct sub
{
    T operator()(const T &x, const T &y) const { return x - y; }
};

int main()
{
    add<int> addobj;
    sub<int> subobj;

    cout << addobj(3, 5) << endl;
    cout << subobj(3, 5) << endl;

    cout << add<int>()(43, 50) << endl;
    cout << sub<int>()(43, 50) << endl;

    return 0;
}
