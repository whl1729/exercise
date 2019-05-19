#include <iostream>
#include "StrBlob.h"

using namespace std;

int main()
{
    const StrBlob blob{"just", "the", "way", "you", "are"};

    StrBlobPtr ptr = blob.begin();

    for (auto beg = blob.begin(), end = blob.end(); beg != end; beg.incr())
    {
        cout << beg.deref() << ' ';
    }

    cout << endl;

    return 0;
}
