#include <iostream>

using namespace std;

int main()
{
    int foo, bar;

    cout << "Enter two integers: " << endl;
    cin >> foo >> bar;

    if (bar == 0)
        throw runtime_error("Error: Divide 0.");

    cout << foo << " / " << bar << " = " << foo / bar << endl;

    return 0;
}
