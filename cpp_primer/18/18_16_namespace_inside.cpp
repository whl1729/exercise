#include <iostream>

using std::cout;
using std::endl;

namespace Exercise
{
    int ivar = 0;
    double dvar = 0;
    const int limit = 1000;
}

int ivar = 0;

void manip()
{
    using Exercise::ivar;
//    using Exercise::dvar;
    using Exercise::limit;

    double dvar = 3.1416;
    int iobj = limit + 1;
    ++ivar;
    ++::ivar;
    cout << "ivar: " << ivar << " (expected: 1)" << endl;
    cout << "::ivar: " << ::ivar << " (expected: 1)" << endl;
    cout << "dvar: " << dvar << " (expected: 3.1416)" << endl;
}

int main()
{
    manip();
    return 0;
}
