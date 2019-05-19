#include <iostream>
#include <algorithm>
#include <string>
#include <list>

using namespace std;

int main()
{
    string val;
    list<string> slist;

    cout << "Enter some words: " << endl;
    while (cin >> val)
        slist.push_front(val);

    cin.clear();
    cout << "Enter a target: " << endl;
    cin >> val;

    cout <<  "The target occurs " << count(slist.cbegin(), slist.cend(), val)
         << " times." << endl;

    return 0;
}
