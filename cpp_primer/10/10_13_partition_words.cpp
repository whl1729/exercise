#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool is_long(const string &str)
{
    return str.size() >= 5;
}

int main()
{
    string word;
    vector<string> vs;

    cout << "Enter some words: " << endl;
    while (cin >> word)
        vs.push_back(word);

    auto end_long = partition(vs.begin(), vs.end(), is_long);

    for (auto vbeg = vs.begin(); vbeg != end_long; ++vbeg)
        cout << *vbeg << ' ';
    cout << endl;

    return 0;
}
