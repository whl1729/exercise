#include <iostream>
#include "StrVec.h"

using std::cout;
using std::endl;

int main()
{
    StrVec sv;
    sv.reserve(5);
    cout << sv.capacity() << " " << sv.size() << endl;
    sv.reserve(50);
    cout << sv.capacity() << " " << sv.size() << endl;
    sv.resize(5);
    cout << sv.capacity() << " " << sv.size() << endl;
    sv.resize(500);
    cout << sv.capacity() << " " << sv.size() << endl;

    return 0;
}
