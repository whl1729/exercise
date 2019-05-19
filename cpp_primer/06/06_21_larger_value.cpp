#include <iostream>

using namespace std;

int larger(int foo, const int *bar)
{
    return (foo > *bar ? foo : *bar);
}

int main()
{
    int foo, bar;

    cout << "Enter two numbers:" << endl;
    cin >> foo >> bar;
    cout << "The larger of them: " << larger(foo, &bar) << endl;

    return 0;
}
