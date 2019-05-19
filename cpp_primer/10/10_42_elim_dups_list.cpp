#include <iostream>
#include <algorithm>
#include <list>
#include <string>

using namespace std;

void print_list(const list<string> &slist)
{
    for (auto &s: slist)
        cout << s << ' ';
    cout << endl;
}

void elim_dups(list<string> &slist)
{
    slist.sort();

    print_list(slist);

    slist.unique();

    print_list(slist);
}

int main()
{
    string word;
    list<string> slist;

    cout << "Enter some words: " << endl;
    while (cin >> word)
        slist.push_back(word);

    elim_dups(slist);

    return 0;
}
