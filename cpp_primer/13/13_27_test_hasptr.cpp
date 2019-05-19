#include <iostream>
#include "13_27_HasPtr.h"

using namespace std;

void nonref(HasPtr c)
{
    c.print("nonref(c), c");
    
    HasPtr d = c;
    d.print("d=c, d");
    
    HasPtr e("like the blue bird flying by me");
    e.print("e(str), e");

    d = e;
    d.print("d=e, d");
    c.print("d=e, c");
}

int main()
{
    HasPtr a("I wanna be free");
    a.print("a(str), a");

    a = a;
    a.print("a=a, a");

    HasPtr b(a);
    b.print("b(a), b");

    nonref(a);

    return 0;
}
