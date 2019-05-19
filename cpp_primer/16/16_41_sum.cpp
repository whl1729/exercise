#include <iostream>

using namespace std;

template <typename T>
auto sum(T &a, T &b) -> decltype(a+b)
{
    return a + b;
}

int main()
{
    auto a = 3456789987654321;
    auto b = 7654321123456789;
    cout << a << "+" << b << "=" << sum(a, b) << endl;

    return 0;
}
