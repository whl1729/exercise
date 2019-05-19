#include <iostream>
#include <string>
#include <functional>
#include <map>

using namespace std;

int add(int a, int b) { return a + b; }
int mod(int a, int b) { return a % b; }

struct Divide
{
    int operator()(const int &a, const int &b) const { return a / b; }
};

map<string, function<int(int, int)>> binops =
{
    {"+", add},
    {"-", minus<int>()},
    {"/", Divide()},
    {"*", [](int i, int j) { return i * j; }},
    {"%", mod}
};

int main()
{
    int lhs, rhs;
    string op;

    cout << "Enter arithmetic expressions:" << endl;

    while (cin >> lhs >> op >> rhs)
        cout << lhs << " " << op << " " << rhs << " = " << binops[op](lhs, rhs) << endl;

    return 0;
}
