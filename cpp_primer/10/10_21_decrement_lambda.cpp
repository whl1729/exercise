#include <iostream>

using namespace std;

int main()
{
    int foo = 10;

    auto dec = [&foo] { if (foo) { --foo; return false; } else return true; };

    for (int num = 0; num < 15; ++num)
    {
        cout << "foo = " << foo << ", ";
        cout << (dec() ? "equal 0" : "not equal 0.") << endl;
    }

    return 0;
}
