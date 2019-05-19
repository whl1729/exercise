#include <iostream>

using namespace std;

int main()
{
    int foo, bar;
    cout << "Enter two numbers:" << endl;
    cin >> foo >> bar;

    auto add = [] (int a, int b) { return a + b; };

    cout << foo << " + " << bar << " = " << add(foo, bar) << endl;

    return 0;
}
