#include <iostream>
#include "StrBlob.h"

using namespace std;

int main()
{
    StrBlob blob;
    string words[] = {"just", "the", "way", "you", "are"};

    for (int pos = 0; pos < 5; ++pos)
        blob.push_back(words[pos]);

    StrBlobPtr ptr = blob.begin();

    for (int pos = 0; pos < 5; ++pos)
    {
        cout << ptr.deref() << ' ';
        ptr.incr();
    }

    cout << endl;

    while (!blob.empty())
    {
        cout << blob.back() << ' ';
        blob.pop_back();
    }

    cout << endl;
    return 0;
}
