#include <iostream>
#include "StrVec.h"

using namespace std;

int main()
{
    StrVec sv{"hello world", "long time no see", "I wanna be free"};

    for (auto beg = sv.begin(); beg != sv.end(); ++beg)
        cout << *beg << endl;

    return 0;
}
