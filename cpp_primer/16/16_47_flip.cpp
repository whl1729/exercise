#include <iostream>

using namespace std;

void f(int v1, int &v2)
{
    cout << v1 << " " << ++v2 << endl;
}

void g(int &&v1, int &v2)
{
    cout << v1 << " " << v2 << endl;
}

template <typename F, typename T1, typename T2>
void flip1(F f, T1 t1, T2 t2)
{
    f(t2, t1);
}

template <typename F, typename T1, typename T2>
void flip2(F f, T1 &&t1, T2 &&t2)
{
    f(t2, t1);
}

template <typename F, typename T1, typename T2>
void flip3(F f, T1 &&t1, T2 &&t2)
{
    f(std::forward<T2>(t2), std::forward<T1>(t1));
}

int main()
{
    int foo = 5;

    flip1(f, foo, 42);
    cout << "flip1: foo = " << foo << endl;

    flip2(f, foo, 42);
    cout << "flip2: foo = " << foo << endl;

    flip3(g, foo, 42);

    return 0;
}
