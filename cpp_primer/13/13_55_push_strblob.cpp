#include <iostream>
#include "StrBlob.h"

using namespace std;

int main()
{
    StrBlob b;
    string words[] = {"just", "the", "way", "you", "are"};

    b.push_back("hello");
    b.push_back("world");
    for (int pos = 0; pos < 5; ++pos)
        b.push_back(words[pos]);

    cout << "b:" << endl;
    b.print(cout);

    StrBlob c(b);
    cout << "c(b), c:" << endl;
    c.print(cout);

    StrBlob d{"as", "long", "as", "you", "love", "me"};
    cout << "d:" << endl;
    d.print(cout);

    c = d;
    cout << "c=d, b:" << endl;
    b.print(cout);
    cout << "c:" << endl;
    c.print(cout);
    
    while (!c.empty())
        c.pop_back();

    cout << "c.pop_back, c:" << endl;
    c.print(cout);
    cout << "d:" << endl;
    d.print(cout);

    return 0;
}
