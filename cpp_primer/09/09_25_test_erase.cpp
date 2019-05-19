#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
    list<string> slist{"hello", "world"};

    for (auto s: slist)
        cout << s << endl;

    auto elem1 = slist.end();
    auto elem2 = elem1;
    elem1 = slist.erase(elem1, elem2);

    //cout << *elem1 << endl;

    for (auto s: slist)
        cout << s << endl;

    return 0;
}
