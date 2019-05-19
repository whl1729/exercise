#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

void print(const multimap<string, string> &authors)
{
    auto beg = authors.begin();
    while (beg != authors.end())
    {
        auto range = authors.equal_range(beg->first);
        vector<pair<string, string>> svec(range.first, range.second);
        sort(svec.begin(), svec.end(),
             [] (const pair<string, string> &p1, const pair<string, string> &p2)
             { return p1.second < p2.second; } );

        for (auto &s : svec)
            cout << s.first << " " << s.second << endl;

        beg = range.second;
    }
}

int main()
{
    multimap<string, string> authors;
    string person, book;

    cout << "Enter author's name and his work: " << endl;

    while (cin >> person >> book)
    {
        authors.emplace(person, book);
    }

    print(authors);

    return 0;
}
