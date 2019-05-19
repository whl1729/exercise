#include <iostream>
#include <string>
#include "HasPtr.h"

using namespace std;

int main()
{
    HasPtr a("hello world");
    HasPtr b = a;
    cout << "a: " << a.get_str() << endl;
    cout << "b: " << b.get_str() << endl;

    a.set_str("uptown funk");

    cout << "a: " << a.get_str() << endl;
    cout << "b: " << b.get_str() << endl;

    return 0;
}
