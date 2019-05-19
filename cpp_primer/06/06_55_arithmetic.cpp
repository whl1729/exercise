#include <iostream>
#include <vector>

using namespace std;

void add(int a, int b)
{
    cout << a << '+' << b << '=' << (a + b) << endl;
}

void sub(int a, int b)
{
    cout << a << '-' << b << '=' << (a - b) << endl;
}

void mul(int a, int b)
{
    cout << a << '*' << b << '=' << (a * b) << endl;
}

void divide(int a, int b)
{
    cout << a << '/' << b << '=' << (a / b) << endl;
}

int main()
{
    vector <decltype(add) *> vf{add, sub, mul, divide};
    int foo;
    int bar;

    cout << "Enter two numbers: " << endl;
    cin >> foo >> bar;

    for (auto f : vf)
        f(foo, bar);

    return 0;
}
