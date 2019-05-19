#include <iostream>
#include <forward_list>
#include <string>

using namespace std;

void insert_flist(forward_list<string> &flstr, const string &pos, const string &elem)
{
    auto prev = flstr.before_begin();

    for (auto cur = flstr.begin(); cur != flstr.end(); ++cur)
    {
        if (*cur == pos)
        {
            flstr.insert_after(cur, elem);
            return;
        }

        prev = cur;
    }

    flstr.insert_after(prev, elem);
}

int main()
{
    forward_list<string> flstr;
    string pos, elem;

    cout << "Enter some words: " << endl;
    while (cin >> elem)
        flstr.push_front(elem);

    cin.clear();

    cout << "Enter the position and target: " << endl;
    cin >> pos >> elem;

    for (auto s: flstr)
        cout << s << ' ';
    cout << endl;

    insert_flist(flstr, pos, elem);

    for (auto s: flstr)
        cout << s << ' ';
    cout << endl;

    return 0;
}
