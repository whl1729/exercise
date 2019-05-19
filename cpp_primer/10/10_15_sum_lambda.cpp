#include <iostream>

using namespace std;

int main()
{
    int foo;
    cout << "Enter a number:" << endl;
    cin >> foo;

    auto add = [foo] (int a) { return a + foo; };

    cout << foo << " + 100  = " << add(100) << endl;

    return 0;
}
