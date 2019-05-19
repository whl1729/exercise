#include <iostream>
#include "StrVec.h"
#include "Vec.h"

using namespace std;

int main()
{
    StrVec sv{"hello world", "long time no see", "I wanna be free"};

    sv.emplace_back("welcome");
    sv.emplace_back(10, 'c');
    sv.emplace_back();

    for (auto beg = sv.begin(); beg != sv.end(); ++beg)
        cout << *beg << endl;

    Vec<string> vs{"who you are", "where you from", "what you do"};

    vs.emplace_back("as long as you ...");
    vs.emplace_back(10, '6');
    vs.emplace_back();

    for (auto beg = vs.begin(); beg != vs.end(); ++beg)
        cout << *beg << endl;

    return 0;
}
