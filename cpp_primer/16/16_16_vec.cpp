#include <iostream>
#include "Vec.h"

using namespace std;

int main()
{
    Vec<string> sv{"hello world", "long time no see", "I wanna be free"};

    for (auto beg = sv.begin(); beg != sv.end(); ++beg)
        cout << *beg << endl;

    return 0;
}
