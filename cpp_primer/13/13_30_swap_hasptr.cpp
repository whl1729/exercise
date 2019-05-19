#include <iostream>
#include "HasPtr.h"

using namespace std;

int main()
{
    HasPtr a("hello world", 5);
    HasPtr b("see you", 6);
    a.print("a: ");
    b.print("b: ");
    swap(a, b);
    a.print("after swap, a: ");
    b.print("after swap, b: ");

    return 0;
}
