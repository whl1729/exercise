#include <iostream>
#include "Screen.h"

using namespace std;

int main()
{
    Screen<4,5> sc("HelloWorld");
    cout << sc << endl;
    cout << sc.get() << endl;
    cout << sc.move(6).get() << endl;

    cin >> sc;
    cout << sc << endl;
    return 0;
}
