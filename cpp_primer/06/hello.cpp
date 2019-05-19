#include <iostream>
#include "hello.h"

using namespace std;

int foo(int bar=100)
{
    return bar;
}

int main()
{
    cout << foo() << endl;

    return 0;
}
